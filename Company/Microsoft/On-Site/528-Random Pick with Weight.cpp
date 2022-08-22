class Solution {
public:
    vector<int> buffer;
    int sum;
    Solution(vector<int>& nums) {
        sum = 0;
        for(int num : nums){
            sum+=num;
            buffer.push_back(sum);
        }
    }
    
    int pick(int target) {
        int n = rand()%sum;
        
        for(int i=0;i<buffer.size();i++){
            if(n<=buffer[i])
                return i;
        }
        return buffer.size()-1;
    }
};