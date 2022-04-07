class Solution {
public:
    unordered_map<int,int> num_frequency;
    static bool compare(vector<int> a, vector<int> b){
        return a[1] > b [1];
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> num;
        for(int i=0;i<nums.size();i++){
            // if(num_frequency.find(nums[i]) == num_frequency.end()){
            //     num.push_back(nums[i]);
            // }
            num_frequency[nums[i]]++;
        }
        
        vector<vector<int>> buffer;
        
        // for(int i=0;i<num.size();i++){
        //     buffer.push_back({num[i], num_frequency[num[i]]});
        // }
        
        //sort(buffer.begin(), buffer.end(), compare);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        
        for(auto num: num_frequency){
            if(min_heap.size() < k){
                min_heap.push({num.second, num.first});
            }else if(min_heap.size() == k && num.second > min_heap.top()[0]){
                min_heap.pop();
                min_heap.push({num.second, num.first});
            }
            
        }
        
        
        vector<int> res;
        for(int i=0;i<k;i++){
            //res.push_back(buffer[i][0]);
            
            res.push_back(
                min_heap.top()[1]
            );
            min_heap.pop();
        }
        
        return res;
    }
};