class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(),0);
        vector<int> rightMax(height.size(),0);
        leftMax[0] = height[0];
        rightMax.back() = height.back();
        
        for(int i=1;i<height.size();i++){
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--){
            rightMax[i] = max(height[i], rightMax[i+1]);
        }
        int res = 0;
        for(int i=0;i<height.size();i++){
            res+= min(leftMax[i], rightMax[i]) - height[i];
            
        }
        return res;
    }
};