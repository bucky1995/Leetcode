class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int row=0;row<triangle.size();row++){
            for(int col=0;col<triangle[row].size();col++){
                if(row == 0){
                    continue;
                }
                if(col == 0){
                    triangle[row][col] += triangle[row-1].front();
                }
                else if(col == row){
                    triangle[row][col] += triangle[row-1].back();
                }
                else{
                    triangle[row][col] += min(triangle[row-1][col-1], triangle[row-1][col]);
                }
            }
        }
        int min_sum = INT_MAX;
        for(int e : triangle.back()){
            if(min_sum>e)
                min_sum=e;
        }
        return min_sum;
    }
};