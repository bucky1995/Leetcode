#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

class Solution {
public:
    bool knows(int a, int b);
    int findCelebrity_1(int n) {
        int candidates = 0;
        for(int i=1;i<n;i++){
            if(knows(candidates,i)){
                candidates=i;
            }
        }
        for(int i=0;i<n;i++){
            if(!knows(i,candidates)){
                return -1;
            }
            if(knows(candidates,i)&&i!=candidates){
                return -1;
            }
        }
        return candidates;
    }

    int numDecodings(string s) {
        int n = s.size();
        int n0=1;
        int n1=(s[0]=='0')?0:1;
        for(int i=1;i<n;i++)
        {
            int tmp=n1;
            if(s[i]=='0')
                n1=0;
            if((s[i-1]=='2'&&s[i]<='6')||s[i-1]=='1')
                n1+=n0;
            if(n1==0)
                return 0;
            n0=tmp;
        }
        return n1;
    }

    bool isOneEditDistance(string s, string t) {
        int m=s.size(),n=t.size();
        if(m>n){
            return isOneEditDistance(t,s);
        }
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(m==n){
                    return s.substr(i+1)==t.substr(i+1);
                }else{
                    return s.substr(i)==t.substr(i+1);
                }
            }
        }
        return false;
    }
     
    //Greedy Alogrithm
    string intToRoman(int num) {
        vector<string> Ro={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string result;
        for(int i=0;i<Ro.size();i++){
            while(num>=val[i]){
                result+=Ro[i];
                num-=val[i];
            }
        }
        return result;
    }


};