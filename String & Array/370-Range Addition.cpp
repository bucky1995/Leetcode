class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff_array(length, 0);
        vector<int> array;
        
        for(int i=0;i<updates.size();i++){
            int left = updates[i][0];
            int right = updates[i][1];
            int inc = updates[i][2];
            
            diff_array[left]+=inc;
            if(right<length-1)    diff_array[right+1] -=inc;
        }
        int num = 0;
        for(int i=0;i<diff_array.size();i++){
            array.push_back(
                num+=diff_array[i]
            );
        }
        return array;
    }
};