class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    int count_ways(int dice_i, int cur_sum, int n, int k, int target){
        if(n == dice_i){
            if(cur_sum == target)   return 1;
            else    return 0;
        }
        
        if(memo[dice_i][cur_sum]!=-1){
            return memo[dice_i][cur_sum];
        }
        
        int ways = 0;
        for(int i=1;i<=min(k, target-cur_sum);i++){
            ways = (ways + count_ways(dice_i+1, cur_sum+i, n, k, target)) % MOD;
        }
        memo[dice_i][cur_sum] = ways;
        return ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<int>>(n+1, vector<int>(target+1, -1));
        return count_ways(0, 0, n, k, target);
    }
};