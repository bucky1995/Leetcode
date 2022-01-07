#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int get_dis(int a, int target){
        return abs(a-target);
    }

    int find_closet(vector<int>& arr,int target){
        int min_dis = -1;
        int closest_index = -1;

        int left = 0;
        int right = arr.size()-1;

        int max_small = -1;

        while(left<=right){
            int mid = left+(right-left)/2;
            if(arr[mid]<target){
                max_small = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        if(max_small == arr.size()-1){
            return max_small;
        }

        return get_dis(arr[max_small],target) <= get_dis(arr[max_small+1],target)?max_small:max_small+1;

    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {


        if(x<=arr.front()){
            return vector<int> (arr.begin(),arr.begin()+k);
        }else if(x>=arr.back()){
            return vector<int> (arr.end()-k,arr.end());
        }

        int closest_index = find_closet(arr,x);

        vector<int> res;
        res.push_back(arr[closest_index]);
        int count = 1;
        int left = closest_index-1;
        int right = closest_index+1;
        while(count!=k){
            int left_dis = -1;
            if(left>=0){
                left_dis = get_dis(arr[left],x);
            }
            int right_dis = -1;
            if(right<arr.size()){
                right_dis = get_dis(arr[right],x);
            }

            if(left_dis>=0 && right_dis>=0){
                res.push_back(
                        left_dis<=right_dis? arr[left--]:arr[right++]
                );
            }else{
                res.push_back(
                        left_dis<0?arr[right++]:arr[left--]
                );
            }
            count++;
        }
        sort(res.begin(),res.end());
        return res;
    }
};

