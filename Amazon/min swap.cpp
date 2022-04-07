vector<int> arr;

min(count_swap(arr,0), count_swap(arr,1));

int count_swap(vector<int> arr, int num){
    int numCount = 0;
    int swapCount = 0;

    for(int i=0;i<arr.size();i++){
        if(arr[i] == num){
            numCount++;
        }else{
            swapCount+=numCount;
        }
    }
    return swapCount;
}