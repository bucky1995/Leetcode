#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int count(vector<int> nums, int index){
        int res = 0;
        int left = 0;
        int third_side = nums[index];
        int right = index-1;
        while(left<right){
            int sum = nums[left] + nums[right];
            if(sum>nums[index]){
                res+=right-left;
                right--;
            }else{
                left++;
            }
        }
        return res;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i=2;i<nums.size();i++){
            res+=count(nums,i);
        }
        return res;
    }
};