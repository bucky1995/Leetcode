class Solution {
public:
    int change_digit(vector<int> nums, int x, int y){
        int res = 0;
        for(int n : nums){
            if(n == x)    n = y;
            res = 10*res;
            res+=n;
        }
        return res;
    }
    int maxNum(vector<int> nums){
        int res = change_digit(nums, nums.front(),9);
        for(int num: nums){
            if(num == 9)    continue;
            return change_digit(nums, num, 9);
        }
        return res;
    }
    int minNum(vector<int> nums){
        int res = change_digit(nums, nums.front(),1);
            
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(i == 0 && num==1)   continue;
            if(i == 0 && num!=1)    return change_digit(nums,num,1);
            if(num == 0)    continue;
            if(nums.front()!=num)   return change_digit(nums,num,0);
        }
        
        return change_digit(nums,1,1);
    }
    vector<int> breakNum(int num){
        vector<int> res;
        int digit = 0;
        if(num == 0)    {
            res.push_back(0);
        }
        while(num!=0){
            res.push_back(num%10);
            num = num/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int maxDiff(int num) {
        vector<int> nums = breakNum(num);
        
        int a = maxNum(nums);
        int b = minNum(nums);
        
        return abs(a-b);
    }
};