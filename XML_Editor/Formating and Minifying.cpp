#include "Formating_and_minifying.h";
bool writeFile(string fileName, const vector<string> & xml) {
	fstream out;
	out.open(fileName, ios::out);
	if (!out) {
		cout << "Cannot open the File : " << fileName << endl;
		return false;
	}
	if (out.is_open()) {
		for (int i = 0; i < (int)xml.size(); i++) {
			out << xml[i] << "\n";
		}
	}
	out.close();
	return true;
}
bool readFile(string fileName, vector<string> & xml)
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
string minifying_func(vector<string>& xml)
{
	string result = "";
	for (int i = 0; i < xml.size(); i++)
	{
		for (int j = 0; j < xml[i].size(); j++)
		{

			if (xml[i][j] != ' ' && xml[i][j] != 9)
			{
				xml[i] = xml[i].substr(j, xml[i].size() - j);
				break;
			}
		}

		for (int j = xml[i].size() - 1; j >= 0; j--)
		{
			if (xml[i][j] != ' ' && xml[i][j] != 9)
			{
				xml[i] = xml[i].substr(0, j + 1);
				break;
			}
		}
		result += xml[i];
	}

	string file_name = "test_result.txt"; // this file name must be created and located in your project folder
	vector<string> res;
	res.push_back(result);
	writeFile(file_name, res);
	return result;
}

string getTabs(int n)
{
	string tabs = "";
	string tab = "  ";
	for (int i = 0; i < n; i++)
	{
		tabs += tab;
	}
	return tabs;
}
vector<string> prettifying_func(vector<string>& xml)
{
	string s = minifying_func(xml); // to minify the xml 
	xml = {};
	bool open_tag = false; // flag for open tags
	bool close_tag = false; // flag for close tags
	string temp = "";
	int number_of_tabs = 0; // number of (4 spaces)
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<' && s[i + 1] != '/') // open tag case
		{

			open_tag = true;
			temp += s[i];
		}
		else if (s[i] == '<' && s[i + 1] == '/') // close tab case
		{
			close_tag = true;
			temp += s[i]; // to save '<'
			temp += s[i + 1]; // to save '/'
			i++; // to skip '/' character because it is already saved in the previous line
		}
		else if (s[i] == '>') // case of end of tage (open tag or closed tag)
		{
			temp += s[i];
			if (open_tag == true) // in case if it was an open tag
			{
				open_tag = false;
				string tabs = getTabs(number_of_tabs); // get string of tabs(each tab equal 4 spaces)
				xml.push_back(tabs + temp); // push the open tag into the xml vector
				number_of_tabs++; // add more tab(to next insert not to the current one)
				temp = "";
			}
			else if (close_tag == true) // in case the tag is a closed tag
			{
				close_tag = false;
				number_of_tabs--; // remove one tab(4 spaces)
				if (temp[0] != '<') // in case of text + closed tag (leaf)
				{
					string tabs = getTabs(number_of_tabs);
					// to handle long lines
					if ((tabs.size() + temp.size()) >= 60) // to be in multiple lines
					{

						// to get the index of closed tag (to sperate between text and closed tag)
						int x = temp.size() - 1;
						while (temp[x] != '<')
						{
							x--;
						}
						string line = temp.substr(0, x);// this is the text
						string tag = temp.substr(x, temp.size() - x);// this is the closed tag
						int threshold = 60;//max size per line
						string l = "";
						// the next for loop is to divide the text into multiple lines
						// and add each line to the xml vector
						for (int j = 0; j <= line.size(); j++)
						{
							if (j > threshold)
							{
								xml.push_back(tabs + l);
								l = "";
								threshold += 60;//update the threshold
							}
							else
							{
								l += line[j];
							}

						}
						if (l.size() != 0) // to check if there is any characters left
						{
							xml.push_back(tabs + l);
						}
						xml.push_back(tabs + tag);
					}
					else // to be in single line
					{
						xml[xml.size() - 1] += temp; // will adding the text and closed tage into the last line
													// which was an open tag
					}
					temp = "";

				}
				else // if the temp contains tag only
				{
					string tabs = getTabs(number_of_tabs);
					xml.push_back(tabs + temp);
					temp = "";
				}
			}
		}
		else// case of other characters
		{
			temp += s[i];
		}
	}
	string file_name = "prettifying_result.txt"; // this file name must be created and located in your project folder
	writeFile(file_name, xml);
	return xml;
}