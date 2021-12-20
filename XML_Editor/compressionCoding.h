#ifndef COMPRESSIONCODING_H_
#define COMPRESSIONCODING_H_
#include "huffTree.h"
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class CompressionCoding : HuffTree
{
private:
    fstream in_file;
    fstream out_file;
    string input_file_name;
    string output_file_name;
    HuffNode *root_node;
    char id;
    void createPriorityQueue();
    void createHuffmanTree();
    void traverse(HuffNode *node, string code);
    void setFixedStringForm(string &input_string);
    void appendCodeOfEachChar(string &input_string);
    int binaryToDecimal(string in);

    class compare
    {
    public:
        bool operator()(HuffNode *child1, HuffNode *child2) const
        {
            return child1->getFrequency() > child2->getFrequency();
        }
    };
    priority_queue<HuffNode *, vector<HuffNode *>, compare> P_Q;

public:
    CompressionCoding(string input_file_name, string output_file_name);
};
#endif // COMPRESSIONCODING_
