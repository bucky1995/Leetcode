#include <iostream>
using namespace std;


class Solution {
public:
    bool isP(char c) {
        if(('a'<= c && c<='z') || ('A'<=c && c<='Z') || '0'){
            return true;
        }else{
            return false;
        }
    }

    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            if(!isP(s[i])){
                s.erase(i,1);
                i--;
            }
            else{
                if('A'<=s[i] && s[i]<='Z') {
                    s[i] = s[i] + 32;
                }
            }
        }
        cout<<s<<endl;
        for(int i=0;i<s.length()/2;i++){
            int j = s.length()-1 - i;
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string input = "0P";
    cout<<input<<endl;
    cout<<s.isPalindrome(input);
    return 0;
}

