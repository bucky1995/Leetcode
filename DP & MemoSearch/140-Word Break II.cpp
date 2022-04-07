class Solution {
public:
    vector<string> res;
    string combine(vector<string> buffer){
        string res = "";
        for(string word : buffer){
            res += word;
            res = res + " ";
        }
        res.pop_back();
        return res;
    }
    
    bool is_possible(string s, int start, unordered_set<string> words, 
                     unordered_map<int, bool>& memo){
        if(memo.find(start) != memo.end()){
            return memo[start];
        }
        
        if(start == s.size()){
            return true;
        }
        
        for(int end = start+1; end<=s.size();end++){
            string word = s.substr(start, end - start);
            if(words.find(word) == words.end()){
                continue;
            }
            
            if(is_possible(s, end, words, memo)){
                memo[start] = true;
                return true;
            }
        }
        
        memo[start] = false;
        return false;
    }
    
    void dfs(vector<string> buffer, unordered_set<string> words, 
             unordered_map<int,bool>& memo,
             int start, string s){
        if(start == s.size()){
            res.push_back(combine(buffer));
            return;
        }
        if(!is_possible(s, start, words, memo)){
            return;
        }
        for(int end = start+1;end<=s.size();end++){
            string word = s.substr(start, end-start);
            if(words.find(word) != words.end()){
                buffer.push_back(word);
                dfs(buffer, words, memo, end, s);
                buffer.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<int,bool> memo;
        dfs({}, words, memo,0,s);
        
        return res;
    }
};