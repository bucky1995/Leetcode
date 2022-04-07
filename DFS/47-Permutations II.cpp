class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int> map;
    void DFS(vector<int>& num_options, vector<int> current_order, int length){
        if(current_order.size() == length){
            res.push_back(current_order);
            return;
        }
        
        for(int i=0;i<num_options.size();i++){
            if(map[num_options[i]]>0){
                current_order.push_back(num_options[i]);
                map[num_options[i]]--;
                DFS(num_options, current_order, length);
                map[num_options[i]]++;
                current_order.pop_back();
            }
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<int> num_options;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i]) == map.end()){
                num_options.push_back(nums[i]);
                map[nums[i]] = 1;
            }else{
                map[nums[i]]++;
            }
        }
        
        DFS(num_options, {}, nums.size());
        return res;
    }
};