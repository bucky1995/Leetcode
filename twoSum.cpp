#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int targetNum=target-nums[i];
            if(hash.find(targetNum)!=hash.end()){
                result.push_back(i);
                result.push_back(hash[targetNum]);
                return result;
            }
            hash[nums[i]]=i;
        }
        return result;
    }
};