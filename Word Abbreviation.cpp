#include <iostream> 
#include <unordered_map> 
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> result;
        unordered_map<string,int> count;
        vector<int> iteration(dict.size(),1);
        int unique=1;
        for(int i=0;i<dict.size();i++){
            result.push_back(getAbbr(dict[i],iteration[i]));
            if(count.find(result[i])!=count.end()){
                count[result[i]]++;
                unique=0;
            }else{
                count[result[i]]=1;
            }
        }
        while(unique!=1){
            unique=1;
            for(int i=0;i<result.size();i++){
                if(count[result[i]]>1){
                    iteration[i]++;
                    result[i]=getAbbr(dict[i],iteration[i]);
                    if(count.find(result[i])!=count.end()){
                        count[result[i]]++;
                        unique=0;
                    }else{
                        count[result[i]]=1;
                    }
                }

            }
        }
        return result;
    }
    string getAbbr(string a, int offset){
        int length=a.size();
        int i=0;
        string abbr;
        if(length<=2){
            return a;
        }
        while(i<length){
            if(i==offset){
                abbr+=to_string(length-offset-1);
                i=length-1;
            }else{
                abbr+=a[i];
                i++;
            }
        }
        if(abbr.size()==a.size()){
            return a;
        }else{
            return abbr;
        }
    }
};
