class Solution {
public:
    unordered_set<string> dic;
    vector<string> one_diff(string word){
        vector<string> res;
        dic.erase(word);
        for(int i=0;i<word.size();i++){
            string temp = word;
            for(int c = 'a'; c<='z'; c++){
                temp[i] = c;
                if(dic.count(temp)!=0){
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        
        dic.insert(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        int res = 0;
        bool find = false;
        vector<string> buffer;
        buffer.push_back(beginWord);
        while(!buffer.empty()){
            vector<string> next_buffer;
            res++;
            for(string word : buffer){
                vector<string> next = one_diff(word);
                visited.insert(word);
                for(string w : next){
                    if(w == endWord){
                        find = true;
                        break;
                    }else if(!visited.count(w)) {
                        next_buffer.push_back(w);
                    }
                }             
            }
            if(find)
                break;
            buffer = next_buffer;
        }
        return find ? res+1 : 0;
    }
};