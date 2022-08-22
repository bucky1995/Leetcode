class Solution {
public:
    unordered_map<int, vector<int>> helper;
    unordered_set<int> taken;
    unordered_set<int> visited;
    bool canFinish_helper(int startCourse){
        if(taken.count(startCourse) !=0 )   return false;
        if(visited.count(startCourse) !=0 ) return true;
        
        taken.insert(startCourse);
        visited.insert(startCourse);
        vector<int> next = helper[startCourse];
        
        for(int c: next){
            if(!canFinish_helper(c))
                return false;
        }
        
        taken.erase(startCourse);
        
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int> c : prerequisites){
            int ai = c.front();
            int bi = c.back();
            helper[bi].push_back(ai);
        }
        
        for(int i=0;i<numCourses;i++){
           if(!canFinish_helper(i))
                return false;
        }
        
        return true;
    }
};