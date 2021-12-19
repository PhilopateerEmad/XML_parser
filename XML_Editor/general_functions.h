#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

bool writeFile(string fileName, const vector<string>& xml);
bool readFile(string fileName, vector<string>& xml);
string remove_spaces(string line);
vector<string> get_XML_Vector(string input_line);

#endif // GENERAL_FUNCTIONS_H
