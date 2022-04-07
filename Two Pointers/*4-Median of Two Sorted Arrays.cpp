class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        int left = 0;
        int right = m;
        
        int left_size = (m+n+1)/2;
        
        while(left < right){
            int i = left+(right-left+1)/2;
            int j = left_size - i;
            
            if(nums1[i-1]>nums2[j]){
                right = i-1;
            }else{
                left = i;
            }
        }
        int i = left;
        int j = left_size - i;
        double res = 0;

        int nums1LeftMax = i == 0? INT_MIN : nums1[i-1];
        int nums1RightMin = i == m? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0? INT_MIN : nums2[j-1];
        int nums2RightMin = j == n? INT_MAX : nums2[j];
        
        if((n+m)%2 == 1)
            res = max(nums1LeftMax,nums2LeftMax);
        else
            res = (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin))/2.0;            
        return res;
        
    }
};