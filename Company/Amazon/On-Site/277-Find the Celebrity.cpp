/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int c = 0;
        int i = 1;
        
        while(i<n && c< n){
            if(knows(c,i)){
                c = i;
            }
            i++;
        }
        
        for(int i=0;i<n;i++){
            if(i == c)
                continue;
            if(!knows(i, c) || knows(c,i)){
                return -1;
            }
        }
        return c;   
    }
};