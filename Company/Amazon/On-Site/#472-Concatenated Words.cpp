class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> hash(words.begin(), words.end());
        vector<string> res;
        for(string word : words){
            vector<bool> dp(word.size()+1, false);
            dp[0] = true;
            hash.erase(word);
            for(int i=1;i<=word.size();i++){
                for(int j=0;j<i;j++){
                    if(dp[j] && hash.count(word.substr(j, i-j))!=0){
                        dp[i] = true;
                        break;
                    }
                }
            }
            hash.insert(word);
            if(dp[word.size()]){
                res.push_back(word);
            }
        }
        return res;
    }
};