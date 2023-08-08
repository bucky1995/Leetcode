class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int steps = 0;
        while(i<nums.size()-1){
            steps++;
            int range = nums[i]+i;
            if( range >= nums.size()-1)
                break;
            int next_i = range;
            int max_jump = range;
            for(int j=i+1;j<nums.size() && j<=range;j++){
                if(j+nums[j]>=max_jump){
                    next_i = j;
                    max_jump = j+nums[j];
                }
            }
            i = next_i;
            
        }
        return steps;
    }
};