class Solution {
public:
    class web {
    public:
        string name;
        int timestamp;
    };
    static bool compare(web a, web b){
        return a.timestamp < b.timestamp;
    }
    unordered_set<string> generate_pattern(vector<web> history){
        unordered_set<string> res;
        for(int i=0;i<history.size()-2;i++){
            for(int j=i+1;j<history.size()-1;j++){
                for(int k=j+1;k<history.size();k++){
                    string pattern = history[i].name + "." + history[j].name + "." + history[k].name;
                    res.insert(pattern);
                }
            }
        }
        return res;
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<web>> userhistory;
        unordered_set<string> users;
        for(int i=0;i<username.size();i++){
            web temp;
            temp.name = website[i];
            temp.timestamp = timestamp[i];
            userhistory[username[i]].push_back(temp);
            users.insert(username[i]);
        }
        
        for(string user : users){
            sort(userhistory[user].begin(), userhistory[user].end(), compare);
        }
        
        unordered_map<string, int> pattern_score;
        
        for(string user: users){
            vector<web> history = userhistory[user];
            if(history.size()<3)
                continue;
            
            unordered_set<string> patterns = generate_pattern(history);
            for(string pattern: patterns){
                 pattern_score[pattern]++;
            }
        }
        string res;
        int maxscore = 0;
        for(auto score: pattern_score){
            if(score.second>maxscore){
                maxscore = score.second;
                res = score.first;
            }else if(score.second == maxscore){
                res = min(res, score.first);
            }
        }
        
        vector<string> r;
        
        int i=0;
        string temp = "";
        while(!res.empty()){
            if(res.front() == '.'){
                r.push_back(temp);
                temp = "";
            }else{
                temp.push_back(res.front());
            }
            res.erase(res.begin());
        }
        r.push_back(temp);
        return r;
        
    }
};