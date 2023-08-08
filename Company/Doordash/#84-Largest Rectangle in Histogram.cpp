class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> buffer;
        buffer.push_back(-1);// one time pass solution
        int res = 0;
        for(int i=0;i<heights.size();i++){
            int h = heights[i];
            while(buffer.back()!=-1 && h<=heights[buffer.back()]){
                int temp_h = heights[buffer.back()];
                buffer.pop_back();
                int temp_w = i - buffer.back() -1;
                res = max(temp_h * temp_w, res);
            }
            buffer.push_back(i);
        }
        // int n = heights.size();
        // while(buffer.back()!=-1){
        //     int h = heights[buffer.back()];
        //     buffer.pop_back();
        //     int w = n - buffer.back() -1;
        //     int area = h * w;
        //     res = max(area, res);
        // }
        return res;
    }
};