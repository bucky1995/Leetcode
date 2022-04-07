#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    void two_sum(vector<int> nums, vector<int> buffer, vector<vector<int>> * result,
                 int target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;

        while (lo < hi) {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target ) {
                ++lo;
            } else if (curr_sum > target ) {
                --hi;
            } else {
                result->push_back(buffer);
                result->back().push_back(nums[lo++]);
                result->back().push_back(nums[hi--]);
                while(lo < hi){
                    if(nums[lo] == nums[lo-1])
                        lo++;
                    else{
                        break;
                    }
                }
                while(lo<hi){
                    if( nums[hi] == nums[hi+1])
                        hi--;
                    else{
                        break;
                    }
                }
            }
        }
        return;
    }

    void kSum(vector<int> nums, vector<int> buffer, vector<vector<int>> *result,
              int left, int k, int target){
        if(nums.size()<k){
            return;
        }
        if(k == 2){
            two_sum(nums, buffer, result, target, left);
            return;
        }else{
            for(int i=left;i<nums.size()-k+1;i++){
                if(i>left && nums[i] == nums[i-1]){
                    continue;
                }
                buffer.push_back(nums[i]);
                kSum(nums,buffer, result, i+1, k-1, target-nums[i]);
                buffer.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> buffer;
        kSum(nums, buffer, &result, 0, 4, target);
        return result;
    }
};