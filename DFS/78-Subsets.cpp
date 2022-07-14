class Solution {
public:
    vector<vector<int>> res;
    void deep_generate(int start, vector<int> nums, vector<int> buffer){
        res.push_back(buffer);
        for(int i=start;i<nums.size();i++){
            buffer.push_back(nums[i]);
            deep_generate(i+1, nums, buffer);
            buffer.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        deep_generate(0, nums, vector<int>{});
        return res;
    }
};