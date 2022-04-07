#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1;
        int right = nums.size();
        int temp;
        for(int i=0;i<nums.size();i++){
            if(i == right){
                break;
            }
            if(i<=left){
                continue;
            }
            if(nums[i] == 0){
                left++;
                temp = nums[i];
                nums[i] = nums[left];
                nums[left] = 0;
                i--;
            }else if(nums[i] == 2){
                right--;
                temp = nums[i];
                nums[i] = nums[right];
                nums[right] = 2;
                i--;
            }
        }
    }
};

