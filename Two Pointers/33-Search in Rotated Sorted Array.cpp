class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(nums[mid] == target) return mid;
            else{
                if(nums[mid]>=nums.front()){
                    if(nums.front() <= target && target<nums[mid]){
                        right = mid-1;
                    }else{
                        left = mid+1;
                    }
                }else if(nums[mid]<nums.front()){
                    if(nums[mid]<target && target<=nums.back()){
                        left = mid+1;
                    }else{
                        right = mid-1;
                    }
                }
            }
        }
        return -1;
    }
};