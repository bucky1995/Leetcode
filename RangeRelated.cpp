#include <iostream> 
#include <unordered_map> 
#include <vector>
using namespace std;

class Solution {
public:
    //dummy one
    string combine(int rangelow,int rangehigh){
        return rangelow==rangehigh?to_string(rangelow):to_string(rangelow)+"->"+to_string(rangehigh);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        string buffer;
        vector<string> result;
        int rangelow,rangehigh,temp;
        int i=0;
        while(i<=nums.size()){
            buffer="";
            if(i==0){
                rangelow=lower;
            }else if(i==nums.size()){
                if(nums[i-1]<upper){
                    rangelow=nums[i-1]+1;
                    rangehigh=upper;
                    buffer=combine(rangelow,rangehigh);
                }
            }
            if(i<nums.size()){
                if(nums[i]>rangelow){
                    rangehigh=nums[i]-1;
                    buffer=combine(rangelow,rangehigh);
                    if(nums[i]<2147483647){
                        rangelow=nums[i]+1;
                    }
                }else if(nums[i]==rangelow){
                    if(nums[i]<2147483647){
                        rangelow=nums[i]+1;
                    }
                }
            }
            if(buffer!=""){
                if(!result.empty()){
                    if(result.back()!=buffer){
                        result.push_back(buffer);
                    }
                }else{
                    result.push_back(buffer);
                }
                buffer="";
            }
            i++;
        }
        return result;
    }
    //improved one
    string get_range(int start, int end)
    {
        return start==end? to_string(start) : to_string(start)+"->"+to_string(end);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int pre = lower-1;
        for(int i =0; i <= nums.size(); i++)
        {
           int cur = (i==nums.size()? upper+1:nums[i]);
           if(cur-pre>=2)
                result.push_back(get_range(pre+1,cur-1));
            pre = cur;
        }
        return result;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2]<=rec2[0]||rec1[0]>=rec2[2]||rec1[1]>=rec2[3]||rec1[3]<=rec2[1]){
            return false;
        }else{
            return true;
        }
    }

    vector<int> combine(vector<int> a,vector<int> b){
        int min = a[0];
        int max = a[1]>b[1]?a[1]:b[1];
        vector<int> result;
        result.push_back(min);
        result.push_back(max);
        return result;
    }
    static bool compare(vector<int> a, vector<int> b){
        return (a[0]<b[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<int> temp;
        if(intervals.size()<=1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end(),compare);
        
        result.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=result.back()[1]){
                temp=result.back();
                result.pop_back();
                result.push_back(combine(temp,intervals[i]));
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

        vector<int> merge(vector<int> a,vector<int> b){
        vector<int> result;
        result.push_back(a[0]<b[0]?a[0]:b[0]);
        result.push_back(a[1]>b[1]?a[1]:b[1]);
        return result;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        
        if(intervals.size()==0){
            result.push_back(newInterval);
            return result;
        }
        
        while(i<intervals.size()&&intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        
        while(i<intervals.size()&&intervals[i][0]<=newInterval[1]){
            newInterval=merge(newInterval,intervals[i]);
            i++;
        }
        
        result.push_back(newInterval);
 
        while(i<intervals.size()){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }

};
