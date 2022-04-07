// Find the maximum aggregate temperature changed evaluated among all the days.
// ex - [-1,2,3] - 5
// explanation -
// [-1],[-1,2,3] - max(-1,4) = 4
// [-1,2],[2,3] - max(1,5) = 5
// [-1,2,3][3] - max(4,3) = 4

int max_change(vector<int> arr){


        vector<int> left(arr.size(),0);
        vector<int> right(arr.size(),0);

        int max = INT_MIN;
        int N = arr.size();

        left[0] = arr.front();
        right[right.size()-1] = arr.back();

        for(int i=1;i<arr.size();i++){
            left[i] = left[i-1]+arr[i];
        }
        for(int i=N-2;i>=0;i--){
            right[i] = right[i+1]+arr[i];
        }
        int res = INT_MIN;
        for(int i=0;i<arr.size();i++){
            int sum = left[i]>right[i]?left[i]:right[i];
            res = res>=sum? res:sum;
        }
        return res;
    }
