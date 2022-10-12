class Solution {
public:
    int stoi(string num){
        int res = 0;
        int neg = 1;
        if(num.front() == '-'){
            neg = -1;
            num.erase(num.begin());
        }
        while(num.size()!=0){
            res = res*10+(num.front()-'0');
            num.erase(num.begin());
        }
        return res*neg;
    }
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("*");
        op.insert("/");
        
        vector<long> buffer;
        while(!tokens.empty()){
            string token = tokens.front();
            tokens.erase(tokens.begin());
            if(op.count(token)!=0){
                int temp = buffer.back();
                buffer.pop_back();
                if(token == "+"){
                    buffer.back() = buffer.back()+temp;
                }else if(token == "-"){
                    buffer.back() = buffer.back()-temp;
                }else if(token == "*"){
                    buffer.back() = buffer.back()*temp;
                }else{
                    buffer.back() = buffer.back()/temp;
                }
            }else{
                buffer.push_back(stoi(token));
            }
        }
        return buffer.front();
    }
};