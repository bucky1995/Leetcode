class Solution {
public:
    string cut_number(string s){
        string res = "";
        
        int start = 0;
        while(s[start] == ' '){
            s.erase(s.begin());
        }
        if(s.front() == '-' || s.front() == '+'){
            if(s.front() == '-'){
                res.push_back('-');
            }
            s.erase(s.begin());
        }
        
        while(s.front()<='9' && s.front()>='0'){
            res.push_back(s.front());
            s.erase(s.begin());
        }
        
        return res;
              
    }
    int myAtoi(string s) {
        string cut = cut_number(s);
        int offset = 1;
        if(cut.front() == '-' || cut.front() == '+'){
            if(cut.front() == '-')
                offset = -1;
            cut.erase(cut.begin());
        }
        long t = 1;
        long res = 0;
        while(!cut.empty() && cut.front() == '0')
            cut.erase(cut.begin());
        while(!cut.empty() && cut.front() <='9' && cut.front()>='0'){
            
            int n = cut.front() - '0';
            cut.erase(cut.begin());
            res=res*10 + n;
            if(res*offset<=INT_MIN){
                return INT_MIN;
            }else if(res*offset>=INT_MAX){
                return INT_MAX;
            }
        }
        
        return (int)res*offset;
    }
};