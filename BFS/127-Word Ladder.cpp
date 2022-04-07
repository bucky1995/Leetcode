#include <iostream> 
#include <unordered_set> 
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    vector<string> get_next_words(string curWord, vector<string>& wordList){
        vector<string> nextWords;
        for(int i=0;i<wordList.size();i++){
            string word = wordList[i];
            if(word.size() != curWord.size()){
                continue;
            }
            bool oneDiff = false;
            for(int j=0;j<word.size();j++){
                if(word[j]!=curWord[j]){
                    if(oneDiff){
                        oneDiff = false;
                        break;
                    }else{
                        oneDiff = true;
                    }
                }
            }
            if(oneDiff){
                nextWords.push_back(word);
            }
        }
        return nextWords;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        vector<string> buffer;
        
        buffer.push_back(beginWord);
        visited.insert(beginWord);
        
        int length = 1;
        
        while(!buffer.empty()){
            length++;
            int size = buffer.size();
            while(size!=0){
                string curWord = buffer.front();
                buffer.erase(buffer.begin());
                vector<string> nextWords = get_next_words(curWord, wordList);
                for(int i=0;i<nextWords.size();i++){
                    if(nextWords[i] == endWord){
                        return length;
                    }
                    if(visited.find(nextWords[i]) != visited.end()){
                        continue;
                    }

                    buffer.push_back(nextWords[i]);
                    visited.insert(nextWords[i]);
                }  
                size--;
            }
                 
        }
        return 0;
        
    }
};