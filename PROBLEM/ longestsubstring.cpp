#include <iostream> 
#include <unordered_set> 
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> hash;
        int res = 0;
        int i =0,j = 0;
        while(i<n&&j<n){
            if(hash.find(s[j]) == hash.end()){
                hash.insert(s[j]);
                j++;
                res = res > (j-i) ? res : j-i;
            }else{
                hash.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};