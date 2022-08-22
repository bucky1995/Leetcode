int binary_s(vector<int> nums){
    if(nums.size()>3){
        if(nums[0]!=nums[1])    return 0;
        if(nums[nums.size()-1] != nums[nums.size()-2])  return nums.size()-1;
    }
    int l = 0;
    int r = nums.size()-1;
    while(l<r){
        int mid = l + (r-l)/2;

        if(nums[mid] == nums[mid+1]){
            r=mid-1;
        }else if(nums[mid] == nums[mid-1]){
            l = mid+1;
        }else{
            return mid;
        }
    }
    return l;
}

int main() {
    vector<int> nums = {3,3,2};
    cout<<binary_s(nums);
    return 1;
}