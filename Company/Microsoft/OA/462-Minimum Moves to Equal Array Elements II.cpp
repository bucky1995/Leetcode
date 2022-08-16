class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long moves = LONG_MAX;
        long sum = 0;
        long total = 0;
        for(int num : nums){
            sum+=num;
        }
        long sumLessK = 0;
        for(int i=0;i<nums.size();i++){
            long num = nums[i];
            long current_moves_less = num*(long)i - sumLessK;
            long current_moves_bigger = (sum-num-sumLessK) - num*(nums.size()-i-1);
            long current_moves = current_moves_less + current_moves_bigger;
            moves = moves>current_moves?current_moves:moves;
            sumLessK+=num;
        }
        return (int)moves;
    }
};