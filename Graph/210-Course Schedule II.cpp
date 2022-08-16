class Solution {
public:
    vector<unordered_set<int>> rules;
    vector<int> indegrees;
    
    void buildRules(vector<vector<int>>& prerequisites){
        for(vector<int> pair:prerequisites){
            int course = pair[0];
            int pre_course = pair[1];
            rules[pre_course].insert(course);
            indegrees[course]++;
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        rules = vector<unordered_set<int>>(numCourses, unordered_set<int>{});
        indegrees = vector<int>(numCourses, 0);
        
        buildRules(prerequisites);
        queue<int> buffer;
        vector<int> res_buffer = vector<int>(numCourses, 0);
        vector<int> res;
        for(int course = 0;course<numCourses;course++){
            if(indegrees[course] == 0){
                buffer.push(course);
            }
        }
        int i=0;
        while(buffer.size()!=0){
            int course = buffer.front();
            buffer.pop();
            res_buffer[i++] = course;
            
            if(rules[course].size()!=0){
                for(int next : rules[course]){
                    indegrees[next]--;
                    if(indegrees[next] == 0){
                        buffer.push(next);
                    }
                }
            }
        }
        
        if(i == numCourses){
            res = res_buffer;
        }
        return res;
    }
};