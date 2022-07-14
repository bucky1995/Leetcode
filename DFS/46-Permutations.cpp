class Solution {
public:
    vector<vector<int>> res;
    void deep_combine(vector<int>& nums, vector<int> buffer, unordered_set<int> used){
        if(buffer.size() == nums.size()){
            res.push_back(buffer);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used.find(nums[i]) != used.end()){
                continue;
            }
            
            buffer.push_back(nums[i]);
            used.insert(nums[i]);
            deep_combine(nums, buffer, used);
            buffer.pop_back();
            used.erase(nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> buffer;
        unordered_set<int> used;
        deep_combine(nums, buffer, used);
        return res;
    }
};