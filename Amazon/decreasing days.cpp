int countDecreasingRatings(vector<int> ratings) {
    int N = ratings.size();

    if(N == 0)  return 0;

    int i=0;
    int res = 1;
    for(int j=1;j<N;j++){
        if(ratings[j-1] - ratings[j] == 1){
            result+=(j-i+1);
        }else{
            i=j;
            result++;
        }
    }
    return res;
}