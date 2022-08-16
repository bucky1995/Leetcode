class Solution {
public:
    vector<int> sumZero(int n) {
        int pair_num = n/2;
        vector<int> res;
        for(int i=1;i<=pair_num;i++){
            res.push_back(i);
            res.push_back(0-i);
        }
        if(n%2 == 1)    res.push_back(0);
        return res;
    }

    vector<int> sumTarget(int n, int target){
        int pair_num;
        vector<int> res;
        if(target ==0){
            pair_num = n/2;
            if(n%2 == 1){
                res.push_back(0);
            }
        }else{
            if(n%2 == 0){
                pair_num = n/2-1;
                res.push_back(0);
            }else{
                pair_num = n/2;
            }
            res.push_back(target);

            if(abs(target)<=pair_num&&target!=INT_MIN)    pair_num++;
        }
        for(int i=1;i<=pair_num;i++){
            if(i == target || (0-i) == target) continue;
            res.push_back(i);
            res.push_back(0-i);
        }
        return res;
    }
};

