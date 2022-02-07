#include "xmltomat.h"

void xmltomat(string inputFile,int *users_count,int arr[100][100] ){
int current_id;
int follower;
int index;
//int arr[100][100]={0};
vector<string> x;
readFile(inputFile,x);
for(int i=0;i<(int)x.size();i++){
    if (x[i].find("<user>") != string::npos) {
        while(x[i].find("</user>")== string::npos){

            if(x[i++].find("<user>")!= string::npos&&x[i].find("<id>") != string::npos){
                index=x[i].find('>')+1;
                current_id=x[i][index]-'0'-1;
                (*users_count)++;
            }
            if(x[i].find("<followers>")!= string::npos){
                while(x[i++].find("</followers>")== string::npos){
                    if(x[i].find("<id>") != string::npos){
                        index=x[i].find('>')+1;
                        follower=x[i][index]-'0'-1;
                        arr[current_id][follower]=1;
                    }
                }
            }
        }
    }
  }
}
