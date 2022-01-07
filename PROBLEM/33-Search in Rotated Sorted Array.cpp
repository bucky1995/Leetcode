#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    int find_k(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>nums[mid+1]){
                return mid+1;
            }else if(nums[mid]<nums[left]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return 0;
    }

    int binary_search(int left, int right, int target, vector<int> &nums) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else {
                if (target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int> &nums, int target) {
        if (nums[0] <= nums.back()) {
            return binary_search(0, nums.size() - 1, target, nums);
        }
        int k = find_k(nums);

        if (target >= nums[0] && target <= nums[k - 1]) {
            return binary_search(0, k - 1, target, nums);
        } else {
            return binary_search(k, nums.size() - 1, target, nums);
        }
    }
};

