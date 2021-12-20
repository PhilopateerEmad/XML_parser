#include "huffTree.h"

void HuffTree::createNodeArray()
{
    for (int i = 0; i < 128; i++)
    {
        array_of_nodes[i] = new HuffNode();
        array_of_nodes[i]->setId(i);        // give ascii for each index
        array_of_nodes[i]->setFrequency(0); // initialize all frequencies to zero
    }
}
