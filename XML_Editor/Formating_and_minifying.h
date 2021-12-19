#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stack>
using namespace std;
bool writeFile(string fileName, const vector<string>& xml);
bool readFile(string fileName, vector<string>& xml);
string minifying_func(vector<string>& xml);
string getTabs(int n);
vector<string> prettifying_func(vector<string>& xml);
