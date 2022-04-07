class Solution {
public:
    int cut(vector<int> nums, int left, int right, int neg_count){
        if(neg_count%2 == 0)    return right-left+1;
        int l = left;
        int r = right;
        while(nums[l]>0)    l++;
        while(nums[r]>0)    r--;
        return max(right-l, r-left);
    }
    
    int getMaxLen(vector<int>& nums) {
        int res = 0;
        int end=0;
        int N = nums.size();
        
        while(end<N){
            int neg_count = 0;
            int start = end;
            while(end<N && nums[end]!=0){
                if(nums[end]<0)
                    neg_count++;
                end++;
            }
            
            res = max(res, cut(nums, start,end-1, neg_count));
            
            end++;
        }
        return res;
    }
};