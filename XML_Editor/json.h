#ifndef JSON_H
#define JSON_H
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class attribute{
    public:
        string option="";
        string value="";

};

class node{
public:
        string tag;
       list<attribute> attr;//list of attributes

        string text;

        bool duplicate=0;
        list<node*>next;

        node* previous = nullptr;
        bool not_attribute();
        int get_parent_index();
};

string pasre_tag(string s);
int get_string_index(string s); //this function searching for attribute if found return its starting index else return 0
vector<string> xml_attribute_to_json(string s, int index);
int is_duplicate(node *child);
node* make_tree(vector<string> arr, int arrSize);
string xml_to_json(node* root);
string iteration(node* root, string& out);

#endif // JSON_H
