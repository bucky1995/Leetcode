#include <iostream> 
#include <unordered_set> 
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:

    bool find132pattern(vector<int>& nums) 
    {
        // bad test case.
        if (nums.size () < 3)
            return false;
        
        // min_arr[i] -> min (nums [:i-1])
        vector <int> min_arr (nums.size (), INT_MAX);
        for (int i = 1; i < nums.size (); i++)
            min_arr [i] = min (min_arr [i-1], nums [i-1]);
        
        // intmed_arr[i] -> min (nums [i+1:]) such that intmed_arr[i] > min_arr[i].
        vector <int> intmed_arr (nums.size (), INT_MAX);
        for (int i = nums.size ()-2; i >= 0; i--)
        {
            intmed_arr [i] = intmed_arr [i+1];
            if (nums [i+1] < intmed_arr [i+1] && nums [i+1] > min_arr [i]) // if < prev value and > min.
                intmed_arr [i] = nums [i+1];
        }
        
        // look for the first '3' with '1' and '2'.
        vector <int> &max_arr = nums;
        for (int i = 1; i < max_arr.size ()-1; i++)
            if (max_arr [i] > intmed_arr [i] && intmed_arr [i] > min_arr [i])
                return true;
        
        // done.
        return false;
    }
};
