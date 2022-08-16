class Solution {
public:
    vector<pair<int,int>> temp;
    vector<int> count;
    vector<pair<int, int>> arr;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count = vector<int>(n,0);
        temp = vector<pair<int,int>>(n,pair<int,int>{0,0});
        for(int i=0;i<n;i++){
            arr.push_back(pair<int,int>{nums[i],i});
        }        
        
        sort(0, n-1);
        
        return count;
    }
    
    void sort(int left, int right){
        if(left == right)
            return;
        
        int mid = left+(right-left)/2;
        
        sort(left, mid);
        sort(mid+1, right);
        
        merge(left, right, mid);
    }
    
    void merge(int left, int right, int mid){
        for(int i = left;i<=right;i++){
            temp[i] = arr[i];
        }
        
        int i=left;
        int j = mid+1;
        
        for(int p=left;p<=right;p++){
            if(i == mid+1){
                arr[p] = temp[j];
                j++;
            }else if(j == right+1){
                arr[p] = temp[i];
                i++;
                count[arr[p].second]+=j-mid-1;
            }else if(temp[i].first > temp[j].first){
                arr[p] = temp[j];
                j++;
            }else{
                arr[p] = temp[i];
                i++;
                count[arr[p].second]+=j-mid-1;
            }
        }
    }
};