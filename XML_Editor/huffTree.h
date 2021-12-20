#ifndef HUFFTREE_H_
#define HUFFTREE_H_
#include "huffNode.h"

class HuffTree
{
private:
public:
    HuffNode *array_of_nodes[128];
    void createNodeArray();
    virtual void createHuffmanTree() = 0;
};
#endif // HUFFTREE_H_
