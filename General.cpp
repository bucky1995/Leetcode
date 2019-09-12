#include <iostream> 
#include <unordered_map> 
#include <vector>
#include <queue>
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

    int partitation(int left,int right,vector<int>& nums){
        int piviot=right;
        int pos=left-1;
        for(int i=left;i<right;i++){
            if(nums[i]<nums[piviot]){
                pos++;
                swap(nums[pos],nums[i]);
            }
        }
        pos++;
        swap(nums[right],nums[pos]);
        return pos;
    }
    void quicksort(int left, int right,vector<int>& nums){
        if(left>=right) return;
        
        int piviot=partitation(left,right,nums);
        
        quicksort(left,piviot-1,nums);
        quicksort(piviot+1,right,nums);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)   return res;
        
        quicksort(0,nums.size()-1,nums);
        
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            
            if(nums[i]>0)   break;
            
            int left=i+1,right=nums.size()-1;
            
            int remain = 0-nums[i];
            
            while(left<right){
                if(right<nums.size()-1&&nums[right]==nums[right+1]){
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]==remain){
                    res.push_back(vector<int>({nums[i],nums[left],nums[right]}));
                    right--;left++;
                }else if(nums[left]+nums[right]<remain){
                    left++;
                }else if(nums[left]+nums[right]>remain){
                    right--;
                }
            }
        }
        return res;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        quicksort(0,nums.size()-1,nums);
        int res=target-100000;
        for(int i=0;i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(right<nums.size()-1&&nums[right]==nums[right+1]){
                    right--;
                    continue;
                }
                
                int temp=nums[i]+nums[left]+nums[right];
                
                if(abs(temp-target)<abs(res-target)){
                    res=temp;
                }
                if(temp<=target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return res;  
    }

    void rotate(vector<vector<int>>& matrix) {
        int a =0;
        int b=matrix.size()-1;
        while(a<b){
            for(int i=0;i<b-a;i++){
                swap(matrix[a][a+i],matrix[a+i][b]);
                swap(matrix[a][a+i],matrix[b][b-i]);
                swap(matrix[a][a+i],matrix[b-i][a]);
            }
            a++;b--;
        }
    }

};