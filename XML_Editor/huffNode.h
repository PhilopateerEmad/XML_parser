#ifndef HUFFNODE_H_
#define HUFFNODE_H_
#include <string>
using namespace std;
class HuffNode
{
private:
    char id;
    int frequency;
    string code;
    HuffNode *left;
    HuffNode *right;

public:
    HuffNode();
    void setId(char id);
    void setFrequency(int frequency); 
    void setCode(string code);        
    void setLeft(HuffNode *left);
    void setRight(HuffNode *right);
    HuffNode *getLeft();
    HuffNode *getRight();
    char getId();
    int getFrequency();
    string getCode();
};
#endif // HUFFNODE_H_
