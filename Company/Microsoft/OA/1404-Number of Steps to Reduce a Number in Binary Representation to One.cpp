class Solution {
public:
    string add_one(string s){
        bool carry = true;
        int digit = s.size()-1;
        while(carry){
            carry = false;
            if(digit == -1){
                s = "1" + s;
            }else{
                if(s[digit] == '1'){
                    carry = true;
                    s[digit] = '0';
                }else{
                    s[digit] = '1';
                }
            }
            digit --;
        }
        return s;
    }
    int numSteps(string s) {
        int steps = 0;
        while(s!="1"){
            steps++;
            if(s.back() == '1'){
                s = add_one(s);
            }else{
                s.pop_back();
            }
        }
        return steps;
    }
};