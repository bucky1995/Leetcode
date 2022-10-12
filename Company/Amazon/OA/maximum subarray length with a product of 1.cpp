// an arr of -1 or 1, return the maximum subarray length with a product of 1.
// The array is of size 2 and above and only contains -1 and 1
// e.g arr = [-1,-1,1,1,-1], return 4, since index 0 to 3 have the max length with product equal to 1

int getMaxLen(vector<int> arr){
    int neg_count=0;
    for(int n: arr){
        if(n<0) neg_count++;
    }
    if(neg_count%2 == 0)    return arr.size();
    int N = arr.size();

    int left = 0;
    while(arr[left]>0)  left++;

    int right = N-1;
    while(arr[right]>0) right--;

    return max(N-1-left, right);
}