#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(int left, int right, vector<int> &nums){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    void sortColors(vector<int>& nums) {
        int left = -1;
        int right = nums.size();
        for(int i=0;i<right;i++){
            if(nums[i] == 0){
                left++;
                swap(left,i,nums);
                if(nums[i] == 0 || nums[i] == 1){
                    i--;
                }
            }else if(nums[i] == 2){
                right--;
                swap(right,i,nums);
                if(nums[i] == 0 || nums[i] == 1){
                    i--;
                }
            }

        }
    }
};

