class Solution {
public:
    void reverseWords(vector<char>& s) {
        char c;
        int offset = 0;
        s.insert(s.begin(), '*');
        while(offset<s.size()){
            int word_len = 0;
            while(s.back() != ' ' && s.back()!='*'){
                word_len++;
                c = s.back();
                s.pop_back();
                s.insert(s.begin() + offset, c);
            }
            offset = offset+word_len;
            s.pop_back();
            s.insert(s.begin() + offset, ' ');
            offset++;
        }
        s.pop_back();
    }
};