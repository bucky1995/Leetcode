class Solution {
public:
    long stoi(string s){
        long res = 0;
        for(char c : s){
            res = res*10 + c-'0';
        }
        return res;
    }
    int calculate(string s) {
        vector<long> buffer;
        string clean_s;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                continue;
            }
            clean_s.push_back(s[i]);
        }
        int i=0;
        s = clean_s;
        int neg = 1;
        char o = '#';
        while(i<s.size()){
            string num;
            if(s[i] == '-'){
                neg = -1;
                i++;
            }else if(s[i] == '*'){
                o = '*';
                i++;
            }else if(s[i] == '/'){
                o = '/';
                i++;
            }else if('0' <= s[i] && s[i] <= '9'){
                while(i<s.size() && '0' <= s[i] && s[i] <= '9'){
                    num.push_back(s[i]);
                    i++;
                }
                if(o == '*'){
                    buffer.back() = buffer.back() * stoi(num);
                    o = '#';
                }else if(o == '/'){
                    buffer.back() = buffer.back() / stoi(num);
                    o = '#';
                }else {
                    buffer.push_back(neg * stoi(num));
                    neg = 1;
                }
            }else{
                i++;
            }
        }
        int res = 0;
        for(int i : buffer){
            res+=i;
        }
        return res;
    }
};