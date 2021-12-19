#ifndef CONSISTENCY_H
#define CONSISTENCY_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stack>
using namespace std;

bool isOpeningTag(string tag);
bool areMatchingTags(string tag1, string tag2);
bool isXMLTagMatched(stack<string> S, string tag);
bool check_consistency(vector<string>& XML_Vector);
void fix_errors(vector<string>& XML_Vector);
void detect_errors(vector<string>& XML_Vector);
#endif // CONSISTENCY_H
