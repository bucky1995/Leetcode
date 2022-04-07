class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeftBound(nums,target);
        int right = findRightBound(nums, target);
        if(left>right){
            left = -1;
            right = -1;
        }
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
    
    int findLeftBound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(nums[mid] == target){
                right = mid;
            }else{
                if(nums[mid] < target){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
        }
        return left;
    }
    
    int findRightBound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(nums[mid] == target){
                left = mid+1;
            }else{
                if(nums[mid] < target){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
        }
        
        return left-1;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = findLeftBound(nums, target);
        int right = findRightBound(nums, target);
        res.push_back(left);
        res.push_back(right);
        
        return res;
    }
    
    int findLeftBound(vector<int> nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(nums[mid] == target){
                res = mid;
                right = mid-1;
            }else{
                if(nums[mid] > target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
        }
        return res;
    }
    
    int findRightBound(vector<int> nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        
        while(left<=right){
            int mid = left+(right -left)/2;
            
            if(nums[mid] == target){
                res = mid;
                left = mid+1;
            }else{
                if(nums[mid] > target){
                    right = mid-1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return res;
    }
};