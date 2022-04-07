class Solution {
public:
    int uniqueLetterString(string s) {
        int N = s.size();
        vector<int> alpha(26,-1);
        vector<int> left(N, -1);
        vector<int> right(N,-1);
        
        for(int i=0;i<s.size();i++){
            if(alpha[s[i]-'A']!=-1) left[i] = alpha[s[i]-'A'];
            alpha[s[i]-'A'] = i;
        }
        alpha = vector<int> (26,-1);
        for(int i=N-1;i>=0;i--){
            if(alpha[s[i]-'A']!=-1) right[i] = alpha[s[i]-'A'];
            alpha[s[i]-'A'] = i;
        }
        int res = 0;
        for(int i=0;i<N;i++){
            int leftBound = left[i] == -1? 0: (left[i]+1);
            int rightBound = right[i] == -1? (N-1): (right[i]-1);
            
            res+= (i-leftBound+1) * (rightBound+1-i);
        }
        return res;
    }
};