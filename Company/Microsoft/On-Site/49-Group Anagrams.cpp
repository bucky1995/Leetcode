class Solution {
public:
    string generate_key(string s){
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<string> keys;
        for(string s : strs){
            string key = generate_key(s);
            if(map.count(key) == 0){
                keys.push_back(key);
            }
            map[key].push_back(s);
        }
        vector<vector<string>> res;
        for(string key : keys){
            res.push_back(map[key]);
        }
        return res;
    }
};