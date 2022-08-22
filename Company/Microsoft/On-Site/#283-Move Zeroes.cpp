class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow =-1;
        int fast = 0;
        while(fast<nums.size()){
            if(nums[fast] != 0){
                slow++;
                bool turn = nums[slow] == 0;
                nums[slow] = nums[fast];
                nums[fast] = turn ? 0 : nums[fast];
            }
            fast++;
        }
    }
};