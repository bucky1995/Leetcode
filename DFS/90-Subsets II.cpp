class Solution {
public:
    unordered_map<int,int> count;
    vector<vector<int>> res;
    unordered_map<int,int> num_count;
    void deep_generate(int start, vector<int> nums, vector<int> buffer){
        res.push_back(buffer);
        for(int i=start; i< nums.size();i++){
            buffer.push_back(nums[i]);
            num_count[nums[i]]--;
            int next = num_count[nums[i]] == 0 ? i+1 : i;
            deep_generate(next, nums, buffer);
            num_count[nums[i]]++;
            buffer.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> nums_unique = nums;
        nums_unique.erase(unique(nums_unique.begin(), nums_unique.end()), nums_unique.end());
        
        for(int i=0;i<nums.size();i++){
            num_count[nums[i]]++;
        }
        deep_generate(0, nums_unique, vector<int>({}));
        return res;
    }
};

class Solution_without_map {
public:
    vector<vector<int>> res;
    void deep_generate(int start, vector<int> nums, vector<int> buffer){
        res.push_back(buffer);
        for(int i=start; i< nums.size();i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            buffer.push_back(nums[i]);
            deep_generate(i+1, nums, buffer);
            buffer.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        deep_generate(0, nums, vector<int>({}));
        return res;
    }
};