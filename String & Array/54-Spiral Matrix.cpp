class Solution {
public:
    void delete_empty(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i].empty()){
                matrix.erase(matrix.begin()+i);
                i--;
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        while(!matrix.empty()){
            //delete top
            res.insert(res.end(), matrix.front().begin(), matrix.front().end());
            matrix.erase(matrix.begin());
            if(matrix.empty()){
                break;
            }
            //delete right most
            for(int i=0;i<matrix.size();i++){
                res.push_back(matrix[i].back());
                matrix[i].pop_back();
            }
            delete_empty(matrix);
            if(matrix.empty()){
                break;
            }
            //delete bottom
            reverse(matrix.back().begin(), matrix.back().end());
            res.insert(res.end(), matrix.back().begin(), matrix.back().end());
            matrix.pop_back();
            if(matrix.empty()){
                break;
            }
            //delete left
            for(int i=matrix.size()-1;i>=0;i--){
                res.push_back(matrix[i].front());
                matrix[i].erase(matrix[i].begin());
            }
            delete_empty(matrix);
        }
        return res;
    }
};34