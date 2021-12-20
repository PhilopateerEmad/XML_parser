#include "huffNode.h"
#include <cstdlib>
HuffNode ::HuffNode()
{
    this->id = '\0';
    this->frequency = 0;
    this->code = "";
    this->left = NULL;
    this->right = NULL;
}

void HuffNode::setId(char id)
{
    this->id = id;
}
void HuffNode::setFrequency(int frequency)
{
    this->frequency = frequency;
}
void HuffNode::setCode(string code)
{
    this->code = code;
}
void HuffNode::setLeft(HuffNode *left)
{
    this->left = left;
}
void HuffNode::setRight(HuffNode *right)
{
    this->right = right;
}
HuffNode *HuffNode ::getLeft()
{
    return this->left;
}
HuffNode *HuffNode::getRight()
{
    return this->right;
}
char HuffNode::getId()
{
    return this->id;
}
int HuffNode::getFrequency()
{
    return this->frequency;
}
string HuffNode::getCode()
{
    return this->code;
}
