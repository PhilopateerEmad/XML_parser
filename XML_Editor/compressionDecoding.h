#ifndef COMPRESSIONDECODINGH_H_
#define COMPRESSIONDECODINGH_H_
#include "huffTree.h"
#include <fstream>
#include <string>
#include <queue>
class CompressionDecoding : HuffTree
{
private:
    fstream in_file;
    fstream out_file;
    string input_file_name;
    string output_file_name;
    HuffNode *root_node;
    void buildTree(string &path, char ascii_code);
    string decimalToBinary(int number);
    void createHuffmanTree();

public:
    CompressionDecoding(string input_file_name, string output_file_name);
};
#endif // COMPRESSIONDECODINGH_H
