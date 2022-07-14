class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> buffer;
        deep_sum(0,0,candidates,buffer, target);
        return res;
    }
    
    void deep_sum(int sum, int start, vector<int> candidates, vector<int> buffer, int target){
        if(sum == target){
            res.push_back(buffer);
            return;
        }else if(sum>target){
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            if(candidates[i] > target){
                break;
            }
            buffer.push_back(candidates[i]);
            sum+=candidates[i];
            deep_sum(sum, i, candidates, buffer,target);
            buffer.pop_back();
            sum-=candidates[i];
        }
        return;
    }
};