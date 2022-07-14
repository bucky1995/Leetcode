class Solution {
public:
    unordered_map<int, int> count;
    int n;
    vector<vector<int>> res;
    void deep_gen(unordered_set<int> nums, vector<int> buffer){
        if(buffer.size() == n){
            res.push_back(buffer);
            return;
        }
        for(auto it = nums.begin(); it!= nums.end();it++){
            int num = *it;
            buffer.push_back(num);
            count[num]--;
            unordered_set<int> temp = nums;
            if(count[num] ==0)  temp.erase(num);
            deep_gen(temp, buffer);
            buffer.pop_back();
            count[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> unique_nums = nums;
        unique_nums.erase(unique(unique_nums.begin(),unique_nums.end()), unique_nums.end());
        unordered_set<int> hash;
        hash.insert(unique_nums.begin(), unique_nums.end());
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        n = nums.size();
        deep_gen(hash, vector<int>({}));
        return res;
        
    }
};