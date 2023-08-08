class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1000000000;
        int res = 0;
        for(int n : piles){
            res = max(n, res);
        }
        while(l<r){
            int mid = l+(r-l)/2;
            int hours = f(piles, mid);
            if(hours<=h){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }

    int f(vector<int>& piles, int k){
        int res = 0;
        for(int n : piles){
            res+=n/k;
            if(n%k>0){
                res++;
            }
        }
        return res;
    }
};