#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n,g,res;
        while(low<=high){   //非常重要，就算只剩下一个元素也要继续查找
            g=low+(high-low)/2;//计算新的查找值，(low+high)/2可能会越界
            res=guess(g);
            
            if(res==0){
                return g;
            }
              
            if(res==-1)
                high=g-1;
            else
                low=g+1;
        }
        return 0;
    }
};