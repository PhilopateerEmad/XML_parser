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
    void setFrequency(int frequency); // 8aleban ha5li dol static goa el cpp
    void setCode(string code);        // 8aleban ha5li dol static goa el cpp
    void setLeft(HuffNode *left);
    void setRight(HuffNode *right);
    HuffNode *getLeft();
    HuffNode *getRight();
    char getId();
    int getFrequency();
    string getCode();
};
#endif // HUFFNODE_H_
