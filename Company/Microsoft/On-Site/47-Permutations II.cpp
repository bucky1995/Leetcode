class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int> hash;
    unordered_set<string> generated;
    int n;
    
    void generate(unordered_map<int,int> map, vector<int> buffer, string cur){
        if(buffer.size() == n){
            res.push_back(buffer);
            return;
        }
        unordered_set<int> used;
        for(int n : hash){
            if(map[n]!=0 && used.count(n)==0){
                buffer.push_back(n);
                cur.push_back('0'+ n);
                map[n]--;
                generate(map, buffer, cur);
                buffer.pop_back();
                cur.pop_back();
                map[n]++;
                used.insert(n);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> map;
        n = nums.size();
        for(int num : nums){
            map[num]++;
            hash.insert(num);
        }
        generate(map, vector<int>{}, "");
        return res;
    }
};