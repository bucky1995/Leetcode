#include <iostream> 
#include <unordered_map> 
#include<vector>
using namespace std;

class Solution {
public:
    void swap(int a, int b, vector<int>* nums){
        int temp=(*nums)[a];
        (*nums)[a]=(*nums)[b];
        (*nums)[b]=temp;
    }
    int partition(vector<int> *nums, int low, int high){
        int piviot = (*nums)[high];
        int i = (low-1);

        for(int j=low;j<=high;j++){
            if((*nums)[j]<piviot){
                i++;
                swap(i,j,nums);
            }
        }
        swap(i+1,high,nums);
        return (i+1);
    }
    
    void quickSort(vector<int>* nums,int low, int high){
        if(low < high){
            int pi = partition(nums,low, high);

            quickSort(nums,low,pi-1);
            quickSort(nums,pi+1,high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(&nums,0,nums.size()-1);
        return nums;    
    }
};