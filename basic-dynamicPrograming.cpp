#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int num_coin = coins.size();
        vector<int> buffer(amount+1,INT_MAX);
        buffer[0] = 0;
        for(int i=1;i<=amount;i++){
            int min = INT_MAX;
            for(int j=0;j<num_coin;j++){
                int diff = i-coins[j];
                if(diff<0)  continue;
                if(buffer[diff]!=INT_MAX){
                    if(min>buffer[diff]){
                        min = buffer[diff]+1;
                    }
                }
            }
            if(min != INT_MAX){
                buffer[i] = min;
            }
        }
        if(buffer.back() == INT_MAX){
            return -1;
        }else{
            return buffer.back();
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(n,vector<int>(m,0));
        path[0][0] = 1;
        for(int i=1;i<m;i++){
            path[0][i] = 1;
            
        }
        for(int i=1;i<n;i++){
            path[i][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                path[i][j] =path[i-1][j]+path[i][j-1];
            } 
        }
        return path[n-1][m-1];
    }

    int maxProduct(vector<int>& nums) {
        vector<int> minP(nums.size(),0),maxP(nums.size(),0);
        minP[0] = nums[0];
        maxP[0] = nums[0];
        int res = maxP[0];
        for(int i=1;i<nums.size();i++){
            maxP[i] = max(nums[i],max(nums[i]*minP[i-1],nums[i]*maxP[i-1]));
            minP[i] = min(nums[i],min(nums[i]*minP[i-1],nums[i]*maxP[i-1]));
            if(maxP[i]>res)    res = maxP[i];
        }
        return res;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long>> buffer(n,vector<long>(m,0));
        if(obstacleGrid[0][0]==1||obstacleGrid[n-1][m-1]==1)  return 0;
        buffer[0][0] = 1;
        for(int i=1;i<n;i++){
            if(obstacleGrid[i][0]==0){
                buffer[i][0] = buffer[i-1][0];
            }else{
                buffer[i][0] = 0;
            }
        }
        for(int i=1;i<m;i++){
            if(obstacleGrid[0][i]==0){
                buffer[0][i] = buffer[0][i-1];
            }else{
                buffer[0][i] = 0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j] == 1)
                    buffer[i][j] = 0;
                else{
                    buffer[i][j] = buffer[i-1][j]+buffer[i][j-1];
                }
            }
        }
        return buffer[n-1][m-1];
    }

    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> buffer(n+1,vector<int>(3,0));
        for(int i=1;i<=n;i++){
            buffer[i][0] = min(buffer[i-1][1]+costs[i-1][0],buffer[i-1][2]+costs[i-1][0]);
            buffer[i][1] = min(buffer[i-1][0]+costs[i-1][1],buffer[i-1][2]+costs[i-1][1]);
            buffer[i][2] = min(buffer[i-1][0]+costs[i-1][2],buffer[i-1][1]+costs[i-1][2]);
        }
        return min(buffer[n][0],min(buffer[n][1],buffer[n][2]));
    }

    int numDecodings(string s) {
        int n =s.size();
        vector<int> buffer(n+1,0);
        if(s[0] == '0') return 0;
        buffer[0] = 1;
        //very import!!!!!!!!!!, it's like a compensent for case when s[i-2]s[i-1] is a valid option. 
        buffer[1] = 1;
        for(int i=2;i<=n;i++){
            int n0=0,n1=0;
            if(s[i-1]!='0'){
                n0 = buffer[i-1];
            }
            if((s[i-2]=='1')||(s[i-2]=='2'&&s[i-1]<='6')){
                n1 = buffer[i-2];
            }
            buffer[i] = n0 + n1;
        }
        return buffer[n];
    }
};
