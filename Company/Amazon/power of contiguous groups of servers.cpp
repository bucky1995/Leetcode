// Find the power of each possible contiguous group of servers.
// ex- [2,1,3] - 27
// explanation -
// power[0,0] = min(2)*sum([2]) = 4
// power[0,1] = min(2,1)*sum([2,1]) = 3
// power[0,2] = min(2,1,3)*sum([2,1,3]) =6
// power[1,1] = min(1)*sum(1) = 1
// power[1,2] = min(1,3)*sum([1,3]) = 4
// power[2,2] = min(3)*sum([3]) = 9

// overall sum = 27


vector<int> arr {2,1,3};

int server(vector<int> arr){
    int res=0;
    int N = arr.size();

    for(int i=0;i<N;i++){
        int min = arr[i];
        int temp_sum = arr[i];
        res = res+ min*temp_sum;
        for(int j=i+1;j<N;j++){
            min = min<arr[j]?min:arr[j];
            temp_sum+=arr[j];
            res = res+min*temp_sum;
        }
    }
    return res;
}
