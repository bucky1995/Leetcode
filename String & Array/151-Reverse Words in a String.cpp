class Solution {
public:
    void clean(string& s){
        while(s.front() == ' '){
            s.erase(s.begin());
        }
        while(s.back() == ' '){
            s.pop_back();
        }
    }
    string cut_word_from_back(string& s){
        string res="";
        while(!s.empty() && s.back()!=' '){
            res = s.back()+res;
            s.pop_back();
        }
        while(s.back() == ' '){
            s.pop_back();
        }
        return res;
    }
    string reverseWords(string s) {
        clean(s);
        s.insert(s.begin(), '*');
        bool done = false;
        string word;
        int i = 0;
        
        while(!done){
            word = cut_word_from_back(s);
            if(word.front() == '*'){
                word.erase(word.begin());
                if(!s.empty())
                    s = s+' ';
                s = s+word;
                break;
            }
            word.push_back(' ');
            s.insert(s.begin()+i, word.begin(), word.end());
            i = i+word.size();
        }
        return s;
    }
};