class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)  return x;
        long left = 0;
        long right = x;
        int res=-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            long sqr = (long) mid*mid;
            if(sqr == x){
                return mid;
            }else{
                if(sqr<x){
                    res = mid;
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return res;
    }
};