#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int get_count(vector<int>& ribbons, int cut_length){
        int count = 0;
        for(int i=0;i< ribbons.size();i++){
            count+=ribbons[i]/cut_length;
        }
        return count;
    }
    int maxLength(vector<int>& ribbons, int k) {
        int sum = 0;
        int max_length = 0;
        for(int i=0;i<ribbons.size();i++){
            if(ribbons[i] > max_length){
                max_length = ribbons[i];
            }
        }
        
        int left = 1;
        int right = max_length;
        max_length = 0;
        while(left<=right){
            int mid = left+(right-left)/2;
            int count = get_count(ribbons,mid);
            
            if(count>=k){
                max_length = mid;
                left=mid+1;
            }else{
                right = mid-1;
            }
        }
        return max_length;
    }
};