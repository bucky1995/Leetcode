class Solution {
public:
    bool dfs(string s, unordered_set<string> words, int min, int max){
        if(s.size() == 0){
            return true;
        }
        
        for(int i=min;i<=max;i++){
            if(words.find(s.substr(0, i)) !=words.end()){
                string temp = s.substr(i, s.size()-1);
                if(dfs(temp, words, min, max)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool memo_dfs(string s, int start, int min, int max,
                  unordered_set<string> words, vector<int>& memo){
        if(start == s.size()){
            return true;
        }
        
        if(memo[start]!= -1){
            return memo[start];
        }
        
        for(int end=min;end<=max;end++){
            string word = s.substr(start, end);
            if(words.find(word)!=words.end() &&
                memo_dfs(s, start+end, min, max, words, memo)){
                memo[start] = true;
                return true;
            }
        }
        
        memo[start] = false;
        return false;
    }
    bool dfs_wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        words.insert(wordDict.begin(), wordDict.end());
        int min = 100;
        int max = -1;
        
        
        for(int i=0;i< wordDict.size();i++){
            int word_l = wordDict[i].size();
            min = min > word_l ? word_l:min;
            max = max < word_l ? word_l:max;
        }
        
        vector<int> memo (s.size(),-1);
        
        return memo_dfs(s, 0, min, max, words, memo);

        //return dfs(s, words, min, max);
    }

    bool dp_wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(words.find(s.substr(j,i-j)) != words.end()
                  && dp[j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};