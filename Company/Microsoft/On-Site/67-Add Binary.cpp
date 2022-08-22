class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        while(!a.empty() || !b.empty()){
            int byte_a = a.empty()? 0 : a.back()-'0';
            if(!a.empty())  a.pop_back();
            int byte_b = b.empty()? 0 : b.back()-'0';
            if(!b.empty())  b.pop_back();
            
            char byte = '0' + (byte_a+byte_b+carry)%2 ;
            carry = (byte_a+byte_b+carry)/2;
            res = byte + res;
        }
        if(carry == 1)
            res = "1"+res;
        return res;
    }
};