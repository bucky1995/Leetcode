class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> buffer(dominoes.size(), 0);
        int force = 0;
        int i=0;
        for(char c : dominoes){
            if(c == 'R'){
                force = dominoes.size();
            }else if(c == 'L'){
                force = 0;
            }else{
                force = max(force-1, 0);
            }
            buffer[i++]+= force;
        }
        i=0;
        force = 0;
        for(i=dominoes.size()-1;i>=0;i--){
            char c = dominoes[i];
            if(c == 'L'){
                force = dominoes.size();
            }else if(c == 'R'){
                force = 0;
            }else{
                force = max(force-1, 0);
            }
            buffer[i]-=force;
        }
        string res;
        for(int f : buffer){
            if(f>0) res.push_back('R');
            else if(f==0)   res.push_back('.');
            else    res.push_back('L');
        }
        return res;

    }
};