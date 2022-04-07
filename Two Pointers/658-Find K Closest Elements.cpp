class Solution {
public:
    int dis(int a, int b){
        
        return abs(a-b);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int min_i = findClosestIndex(arr, x);
        int left = min_i;
        int right = min_i;
        vector<int> res;
        res.push_back(arr[min_i]);
        while(res.size() < k){
            int left_num = left-1>=0? arr[left-1] : 100000;
            int right_num = right+1 < arr.size()? arr[right+1] : 100000;
            int i = dis(left_num, x) <= dis(right_num, x) ? left_num : right_num;
            dis(left_num, x) <= dis(right_num, x) ? left-- : right++;
            res.push_back(i);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    int findClosestIndex(vector<int> nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int res = -1;
        int min_dis = INT_MAX;
        while(left<=right){
            int mid = left + (right - left)/2;
            int mid_dis = dis(nums[mid], target);
            if(mid_dis < min_dis){
                min_dis = mid_dis;
                res = mid;
            }
            if(mid_dis == min_dis && res!=-1 && mid < res)
                res = mid;
            if(nums[mid] == target){
                left++;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return res;
    }
};