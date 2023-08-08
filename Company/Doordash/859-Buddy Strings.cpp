class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        if(s == goal){
            vector<int> count(26,0);
            for(int i=0;i<s.size();i++){
                count[s[i]-'a']++;
            }
            for(int c : count){
                if(c>1)
                    return true;
            }
            return false;
        }else{
            vector<int> swap_p;
            for(int i=0;i<s.size();i++){
                if(s[i]!=goal[i]){
                    swap_p.push_back(i);
                }
            }
            if(swap_p.size()!=2 || s[swap_p.front()]!=goal[swap_p.back()] || s[swap_p.back()]!=goal[swap_p.front()])
                return false;
        }
        return true;
    }
};