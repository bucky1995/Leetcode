#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void twoSum(int current, vector<int> nums,vector<vector<int>> *result){
        int left = current+1;
        int right = nums.size()-1;
        int target = 0-nums[current];
        while(left<right){
            int temp_result = nums[left] + nums[right];
            if(temp_result == target){
                result->push_back(vector<int> {nums[current],nums[left],nums[right]});
                left++;
                right--;
                while(left<right && nums[left] == nums[left-1]){
                    left++;
                }
                while(left<right && nums[right] == nums[right+1]){
                    right--;
                }
            }else{
                if(temp_result < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3){
            return result;
        }

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0&&nums[i] == nums[i-1]){
                continue;
            }
            twoSum(i, nums, &result);
        }
        return result;
    }
};