#include <iostream> 
#include <unordered_map> 
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> levelLength;
        int max=0;
        int level=0;
        string in=input;
        string buffer;
        int isfile=0;
        for(int i=0;i<input.size();i++){
            level=0;
            buffer="";
            while(input[i]=='\t'&&i<input.size()){
                level++;
                i++;
            }
            while(input[i]!='\n'&&i<input.size()){
                buffer+=input[i];
                if(input[i]=='.'){
                    isfile=1;
                }
                i++;
            }
            if(levelLength.size()==0){
                levelLength.push_back(buffer.size());
            }else if(level>levelLength.size()-1){
                levelLength.push_back(buffer.size()+levelLength[level-1]+1);
            }else{
                if(level==0){
                    levelLength[level]=buffer.size();
                }else{
                    levelLength[level]=buffer.size()+levelLength[level-1]+1;
                }
                
            }
            if(isfile==1){
                isfile=0;
                max = max>levelLength[level]?max:levelLength[level];
            }

        }
        return max;
    }
};