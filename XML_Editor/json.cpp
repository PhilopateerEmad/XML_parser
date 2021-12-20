#include "json.h"
//this function check if a node is an attribute(value) or not
bool node::not_attribute(){
    if(attr.empty()== 1)
        return 1;
    return 0;
}

int node::get_parent_index()
{
    int num=0;
    node *temp=new node;
    temp=previous;
    while(temp!=nullptr)
    {
        num++;
        temp=temp->previous;
    }
    return num;
}

string pasre_tag(string s)
{
    //start from index 1 to igonre <
    int i =1;
    string tag;//string to save the tag into

    if(s[1] == '/')
    {
        i=2;
    }
    //while we didn't reach a space or a closing > or the end of the line
    while((s[i] !='>') && (s[i] !=' ') && (i != (int)s.length()-1))
    {
        //parse the tag
        if(s[i] == '/')
        {
            break;
        }
        tag += s[i];
        i++;
    }
    return tag;
}

int get_string_index(string s) //this function searching for attribute if found return its starting index else return 0
{
    for(int i=1; i<(int)s.length(); i++)
    {
        if(s[i] == ' ')
            return i+1;
    }
    return 0;
}

vector<string> xml_attribute_to_json(string s, int index)
{
    int i=index;
    string option;
    string value;
    vector<string>v1;

    while(i<(int)s.length())
    {
        if(s[i] == '=')
        {
            v1.push_back(option);
            option.clear();//
            value.clear();
        }
        else if(s[i] == ' ' || s[i] == '>')
        {
            v1.push_back(value); //"price1":"1",
            option.clear();
            value.clear();
        }
        else
        {
            if(i == (int)s.length()-2 && s[i] =='/')
            {
                //do nothing
            }

            else
            {
                option += s[i];
                value += s[i];
            }

        }

        i++;

    }
    return v1;
}

int is_duplicate(node *child)
{
    node *parent=new node;
    parent = child->previous;
    int num=0;

    list<node*>::iterator i;

    if(parent != nullptr)
    {
        for(i=parent->next.begin(); i!=parent->next.end(); i++)
        {
            if(*i == child)
            {
                i++;
                while(i!=parent->next.end())
                {

                    if(child->tag == (*i)->tag)
                    {
                        num++;
                        (*i)->duplicate =1;
                    }
                    else
                    {
                        break;
                    }

                    i++;
                }
                break;
            }

        }
    }
    return num;
}
//Create a tree of nodes of the xml file
node* make_tree (vector<string> XML_Vector, int arrSize)
{

    int i=0;
    vector<string>v;
    stack<string>open_tag;//stack for opening tags
    stack<node*>open_nodes; //here we create stack of pointers to open nodes
    int index;
    node *root=new node;// create a root nod for the tree

    while(i<arrSize)
    {
        //If the line is an opening tag root line
        if(XML_Vector[i][0]=='<' && XML_Vector[i][1] != '/' && i==0 &&(XML_Vector[i][1] != '!' && XML_Vector[i][1] != '?'))//<cataloge>
        {
            //get the tag of the root node
            root->tag=pasre_tag(XML_Vector[0]);
            //push the opening tag of the root node into the opening tag stack
            open_tag.push(pasre_tag(XML_Vector[i]));
            //push the root node into the open nodes stack
            open_nodes.push(root);
            //get the index after the tag string ex:<cataloge >
            //get the index of the first space
            //the function return zero if no spaces found
            index= get_string_index(XML_Vector[i]);
            //if a space is found,then there is an attirbute within the opening tag ex: <cataloge id="5">
            if(index != 0)
            {
                //extract the attribute and convert it using xml_attribute_to_json() from the space" " index
                //xml_attribute_to_json() returns a vector of strings
                v=xml_attribute_to_json(XML_Vector[i],index);
                for(int i=0; i<(int)v.size(); i+=2)
                {
                    //create an attribute pointer
                    attribute *anode= new attribute;
                    //node option is the first string in the v vector ex:<cataloge id="5"> option is id
                    anode->option=v[i];
                    //attribute value is the second string in the v vector ex:<cataloge id="5"> value is 5
                    anode->value=v[i+1];
                    //push it into the attribute list of the root node
                    root->attr.push_back(*anode);

                }
            }

        }
        //If the tag is an opening tag line but not the root line or node
        /*
                Note that opening tags can be empty element tags  within itself ex:<value/>
                now processing these tags in the next else if
                */
        //Check if it's an opening non root tag
        else if(XML_Vector[i][0]=='<' && XML_Vector[i][1] != '/' &&(XML_Vector[i][1] != '!' && XML_Vector[i][1] != '?'))
        {
            //if it's an empty element tag like <value/>
            if(XML_Vector[i][XML_Vector[i].length()-2] =='/')
            {
                //create a new node named branch
                node *branch= new node;
                //set the next(child)of the top node int he open_nodes stack to this branch node
                open_nodes.top()->next.push_back(branch);
                //assign the node's parent to it's previous node
                branch->previous=(open_nodes.top());
                //get the node tag string using parse_tag()
                branch->tag=pasre_tag(XML_Vector[i]);
                //get the index of the first occurence of a space " " inside this XML line
                index= get_string_index(XML_Vector[i]);
                //push the node's tag into the open tag stack
                open_tag.push(pasre_tag(XML_Vector[i]));
                //push the node into the openn nodes stack
                open_nodes.push(branch);


                //if the index!=0 this means that the opening tag contains attributes
                if(index != 0)
                {
                    v=xml_attribute_to_json(XML_Vector[i],index);
                    for(int i=0; i<(int)v.size(); i+=2)
                    {
                        //extract the attribute and convert it using xml_attribute_to_json() from the space" " index
                        //xml_attribute_to_json() returns a vector of strings
                        attribute *anode= new attribute;
                        //node option is the first string in the v vector ex:<cataloge id="5"> option is id
                        anode->option=v[i];
                        //attribute value is the second string in the v vector ex:<cataloge id="5"> value is 5
                        anode->value=v[i+1];
                        //push it into the attribute list of the root node
                        branch->attr.push_back(*anode);

                    }
                }

            }
            //else if the opening tag has no spaces meaning no attributes
            else
            {
                //create a new node named branch
                node *branch= new node;
                //set the next(child)of the top node int he open_nodes stack to this branch node
                open_nodes.top()->next.push_back(branch);
                //assign the node's parent to it's previous node
                branch->previous=(open_nodes.top());
                //get the node tag string using parse_tag()
                branch->tag=pasre_tag(XML_Vector[i]);
                //get the index of the first occurence of a space " " inside this XML line
                index= get_string_index(XML_Vector[i]);
                //push the node's tag into the open tag stack
                open_tag.push(pasre_tag(XML_Vector[i]));
                //push the node into the openn nodes stack
                open_nodes.push(branch);
                //if the index!=0 this means that the opening tag contains attributes
                if(index != 0)
                {
                    v=xml_attribute_to_json(XML_Vector[i],index);
                    for(int i=0; i<(int)v.size(); i+=2)
                    {
                        //extract the attribute and convert it using xml_attribute_to_json() from the space" " index
                        //xml_attribute_to_json() returns a vector of strings
                        attribute *anode= new attribute;
                        //node option is the first string in the v vector ex:<cataloge id="5"> option is id
                        anode->option=v[i];
                        //attribute value is the second string in the v vector ex:<cataloge id="5"> value is 5
                        anode->value=v[i+1];
                        //push it into the attribute list of the root node
                        branch->attr.push_back(*anode);

                    }
                }

            }



        }
        //if it's a closing tag
        else if(XML_Vector[i][0]=='<' && XML_Vector[i][1] == '/')
        {
            //check if the opening tag stack's top matches this closing tag
            if(open_tag.top()==pasre_tag(XML_Vector[i]))
            {
                //if matched pop the node and its tag
                open_tag.pop();
                open_nodes.pop();

            }
        }
        //if the line isn't an opening root tag,closing tag,opening tag with attributes,empty element opening tag
        //then it must be  a string line between two tags
        else if(XML_Vector[i][0] != '<')
        {
            if(open_nodes.top()->text=="")
            {
                open_nodes.top()->text=XML_Vector[i];
            }
            else
            {
                open_nodes.top()->text+=" "+ XML_Vector[i];
            }


        }
        i++;
    }
    return root;
}
//this function transform the xml file to json using the root of the created tree
string xml_to_json(node* root)
{
    string space;
    string space1;
    for(int i=0 ;i<root->get_parent_index();i++)
    {
        space+="    ";
    }
    space1=space+"  ";
    string s;

    if(root->duplicate == 0 )
    {
        s+="\n"+ space+ "\""+root->tag + "\":";
        if(is_duplicate(root)!=0)
        {
            s+=" [";
        }
    }
    if(root->previous==nullptr && root->next.size()==0)//handling 1 node in tree
    {
        if(root->text=="")
        {
            s+=" \"\"";
        }
        else
        {
            s+=" \""+ root->text +"\"";
        }
    }

    else if(root->attr.empty() && root->next.empty())//no attribute and no childen
    {
        s += '"' + root->text + '"';
        if(root->previous->next.size()>1)
        {
            if((!is_duplicate(root))==0 || !root->duplicate==0)
            {
                    s+=",";
            }
            else
                s+=",";
        }
    }


    else if(root->attr.size() != 0 || root->text != "") //with or without attribute and with or without text
    {
        s += "{\n    ";

        if(root->attr.size() != 0)
        {
            for(auto i=root->attr.begin(); i!= root->attr.end(); i++)
            {
                s += space+"\"" + i->option + "\":"+ i->value +",\n    ";
            }

        }
        if(root->text != "")
        {
            s += space+ "\"#text\":\"" + root->text + "\"";
            if(!root->next.empty())
            {
                s+=",";
            }
        }


    }
    else if(root->next.size() !=0)
    {
        s +="{\n    ";
    }


    return s;
}
//this function returns the output string
string iteration(node* root, string& out)
{
    //add the root tag to the output string
    out += xml_to_json(root);
    string space;
    list<node*>::iterator i;//iterator of type pointer to node
    for (i = root->next.begin(); i != root->next.end(); i++)
    {
        iteration(*i, out);

    }
    for(int i=0 ;i<root->get_parent_index()+1;i++)
    {
        space+="    ";
    }
    if (!root->attr.empty() || !root->next.empty())
    {
        out+="\n"+space+"}";
        if(root->duplicate==1 || is_duplicate(root)!=0)
        {
            out+=",";
        }

    }
    if(root->duplicate==1 && is_duplicate(root)==0)
    {
        out+="\n"+space+"]";
    }

    return out;
}
