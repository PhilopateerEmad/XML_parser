#include "general_functions.h"


bool writeFile(string fileName, const vector<string>& xml) {
    fstream out;
    out.open(fileName, ios::out);
    if (!out) {
        cout << "Cannot open the File : " << fileName << endl;
        return false;
    }
    if (out.is_open()) {
        for (int i = 0; i < (int)xml.size(); i++) {
            if (xml[i] != "") {
                out << xml[i] << "\n";
            }
        }
    }
    out.close();
    return true;
}
bool readFile(string fileName, vector<string>& xml)
{
    ifstream in(fileName.c_str());
    if (!in)
    {
        cout << "Cannot open the File : " << fileName << endl;
        return false;
    }
    string str;
    while (getline(in, str))
    {
        if (str.size() > 0)
            xml.push_back(str);
    }
    in.close();
    return true;
}
string remove_spaces(string line){
    int j = 0;
    //remove spaces from the start of the line
    while(line[j] == ' ' || line[j] == '\t' || line[j] == '\n'){
        j ++;
    }
    //remove spaces from the end of theline
    int k = line.length() - 1;
    while(line[k] == ' ' || line[k] == '\t' || line[k] == '\n') {
        k --;
    }
    //creare a string without spaces
    string line_without_pre_or_post_spaces = "";
    //copy only from j where we removed spaces at the start of the line
    //until k the end of the line with no spaces
    for(int q = j ; q <= k; q++){
        line_without_pre_or_post_spaces += line[q];
    }
    // return the string
    return line_without_pre_or_post_spaces;
}
vector<string> get_XML_Vector(string input_line){
    vector<string> xml;
    string str = "";
    unsigned int i = 0;
    while(i < input_line.length()){
        if(input_line[i] == '<'){
            while(i < input_line.length()){
                if(input_line[i] != '>'){
                    str += input_line[i];
                }
                else{
                    break;
                }
                i++;
            }
            str += '>';
            str = remove_spaces(str);
            i++;
            xml.push_back(str);
            str = "";
        }
        else{
            while(i < input_line.length()) {
                if(input_line[i] != '<'){
                    str += input_line[i];
                }
                else{
                    break;
                }
                i++;
            }
            bool add = false;
            for(unsigned int j=0; j<str.length(); j++){
                if(str[j] != ' ' && str[j] != '\n' && str[j] != '\t'){
                    add = true;
                    break;
                }
            }
            if(add == true){
                str = remove_spaces(str);
                xml.push_back(str);
            }
            str = "";
        }
    }
    return xml;
}
