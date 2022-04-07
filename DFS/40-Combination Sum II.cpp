class Solution {
public:
    unordered_map<int,int> map;
    
    void DFS(vector<int>& nums, int remain, int current_position, int current_sum,
             vector<int> current_combination, vector<vector<int>>& res){
        if(remain <=0 ){
            if(remain == 0){
                res.push_back(current_combination);
            }
            return;
        }
        
        for(int i=current_position;i<nums.size();i++){
            int num = nums[i];
            if(current_combination.size() == 2 && current_combination[1] == 5){
                int a=0;
            }
            current_combination.push_back(num);
            current_sum+=num;
            if(map[num]>0){
                map[num]--;
                DFS(nums, remain - num, 
                    map[num] >0 ? i:i+1, 
                    current_sum, current_combination, res);
                map[num]++;
            }
            current_combination.pop_back();
            current_sum-=num;
        }  
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            if(candidates[i] <= target){
                if(map.find(candidates[i]) == map.end()){
                    map[candidates[i]] = 1;
                    nums.push_back(candidates[i]);
                }else{
                    map[candidates[i]]++;
                }
            }
        }
        
        
        DFS(nums, target, 0, 0, {}, res);
        
        return res;
    }
};