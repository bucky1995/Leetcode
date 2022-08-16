class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        int s1 = accumulate(begin(nums1),end(nums1),0);
        int s2 = accumulate(begin(nums2),end(nums2),0);
        if(s1>s2)   return minOperations(nums2, nums1);
        if(s1 == s2)    return 0;
        if(max(l1,l2)>min(l1,l2)*6) return -1;
        
        int res = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.rbegin(), nums2.rend());
        int i=0;
        int j=0;
        while(s1!=s2){
            int diff = s2-s1;
            int d1 = i==l1?0:6-nums1[i];
            int d2 = j==l2?0:nums2[j]-1;
            int d = min(diff, max(d1,d2));
            if(d1>=d2){
                s1+=d;
                i++;
            }else{
                s2-=d;
                j++;
            }
            res++;
        }
        return res;
    }
};