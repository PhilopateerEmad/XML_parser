#include "compressionDecoding.h"
#include <iostream>
using namespace std;
string CompressionDecoding::decimalToBinary(int number)
{
    int i = 0;
    string binaryNumber = "", zeroes;
    while (number > 0)
    {
        binaryNumber = (number % 2 == 0 ? "0" : "1") + binaryNumber;

        number /= 2;
        i++;
    }
    zeroes.append(8 - binaryNumber.size(), '0');
    binaryNumber.insert(0, zeroes);
    return binaryNumber;
}
void CompressionDecoding::buildTree(string &path, char ascii_code)
{
    HuffNode *current = root_node;
    for (int i = 0; i < (int)path.size(); i++)
    {
        if (path[i] == '0')
        {
            if (current->getLeft() == NULL) // if it is the first left node create a new node
            {
                current->setLeft(new HuffNode());
            }
            current = current->getLeft(); // let the pointer to point to the next left node
        }
        else if (path[i] == '1')
        {
            if (current->getRight() == NULL) // if it is the first right node create a new node
            {
                current->setRight(new HuffNode());
            }
            current = current->getRight(); // let the pointer to point to the next right node
        }
        else
        {
        }
    }
    current->setId(ascii_code); // set the original id of the character
}

void CompressionDecoding::createHuffmanTree()
{
    in_file.open(input_file_name, ios::in | ios::binary); // open the input file
    unsigned char nodesNumber;
    in_file.read(reinterpret_cast<char *>(&nodesNumber), 1); // read number of nodes of huffman tree
    root_node = new HuffNode;

    for (int i = 0; i < nodesNumber; i++)
    {
        char id_code;                                       // char to hold the original character
        unsigned char b_code[16];                           // 16 unsigned char to obtain the binary code
        in_file.read(&id_code, 1);                          // read character
        in_file.read(reinterpret_cast<char *>(b_code), 16); // read the code of the character
        string s_code = "";
        for (int i = 0; i < 16; i++)
        { // obtain the oringinal 128-bit binary string
            s_code += decimalToBinary(b_code[i]);
        }
        int k = 0;
        while (s_code[k] == '0')
        { // delete the added zeroes '000����1' to get the real huffman code
            k++;
        }
        s_code = s_code.substr(k + 1); // get the real huffman code
        buildTree(s_code, id_code);    // call build tree function
    }
    in_file.close(); // close the file
}

CompressionDecoding::CompressionDecoding(string input_file_name, string output_file_name)
{
    this->input_file_name = input_file_name;
    this->output_file_name = output_file_name;
    createNodeArray();
    createHuffmanTree();

    in_file.open(input_file_name, ios::in | ios::binary); // open the input file
    out_file.open(output_file_name, ios::out);            // open the result file
    unsigned char huffTreeSize;
    char counter;
    in_file.read(reinterpret_cast<char *>(&huffTreeSize), 1); // read the size of huffman tree
    in_file.seekg(-1, ios::end);                              // jump to the last one byte to get the number of '0' append to the string at last

    in_file.read(&counter, 1);                      // read number of zeroes append to the string at last
    in_file.seekg(1 + 17 * huffTreeSize, ios::beg); // jump to the position where text starts

    vector<unsigned char> text_vec;
    unsigned char textsec;
    in_file.read(reinterpret_cast<char *>(&textsec), 1); // read first character code

    while (!in_file.eof())                                   // check that if it isn't the end of the file
    {                                                        // get the text byte by byte using unsigned char
        text_vec.push_back(textsec);                         // push the character read from input file in the new text vector
        in_file.read(reinterpret_cast<char *>(&textsec), 1); // read the next character code
    }                                                        // loop till reach the end of the file

    HuffNode *current_ptr = root_node; // initialize cuurent_ptr to point to the root node
    string path;
    for (int i = 0; i <(int) text_vec.size() - 1; i++)
    {                                        // translate the huffman code
        path = decimalToBinary(text_vec[i]); // convert characters codes in text vector from decimal to binary and save it in a string "path"

        if (i ==(int) text_vec.size() - 2)
            path = path.substr(0, 8 - counter);

        for (int j = 0; j <(int) path.size(); j++)
        {
            if (path[j] == '0')
            {
                current_ptr = current_ptr->getLeft(); // let the pointer to point to the left node
            }
            else
                current_ptr = current_ptr->getRight(); // let the pointer to point to the left node

            if (current_ptr->getLeft() == NULL && current_ptr->getRight() == NULL) // if it is a leaf node
            {
                out_file.put(current_ptr->getId()); // write its id "character" in the output file
                current_ptr = root_node;            // point again to the root node
            }
        }
    }
    in_file.close();  // close input file
    out_file.close(); // close output file
}
