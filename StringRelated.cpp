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

    string decodeString(string s, int& i) {
        string res;
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'

                while (n-- > 0)
                    res += t;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0'){
                    return false;
                }
                int Deviation = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    Deviation = Deviation * 10 + abbr[j] - '0';
                    j++;
                }
                i=i+Deviation;
            }else if (word[i] != abbr[j]) {
                return false;
            }else{
                i++;j++;
            }
        }
        return i == word.size() && j == abbr.size();
    }  

    vector<int> merge(vector<int> a,vector<int> b){
        vector<int> result;
        result.push_back(a[0]<b[0]?a[0]:b[0]);
        result.push_back(a[1]>b[1]?a[1]:b[1]);
        return result;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        
        if(intervals.size()==0){
            result.push_back(newInterval);
            return result;
        }
        
        while(i<intervals.size()&&intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        
        while(i<intervals.size()&&intervals[i][0]<=newInterval[1]){
            newInterval=merge(newInterval,intervals[i]);
            i++;
        }
        
        result.push_back(newInterval);
 
        while(i<intervals.size()){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
