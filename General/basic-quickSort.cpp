#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

class Solution {
public:
    void swap(int left, int right, vector<int> &nums){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

    int partition(int left, int right, vector<int> &nums){
        int pi = right;
        right--;
        while(left<=right){
            while(left <= right && nums[left]<nums[pi]){
                left++;
            }
            while(left<= right && nums[right]>=nums[pi]){
                right--;
            }
            if(left<=right) {
                swap(left, right, nums);
                left++;
                right--;
            }
        }
        swap(left,pi,nums);
        return left;
    }
    void quick_sort(int left, int right, vector<int> &nums) {
        if(left<right){
            int pi = partition(left,right,nums);

            quick_sort(left,pi-1,nums);
            quick_sort(pi+1,right,nums);
        }
    }
};
