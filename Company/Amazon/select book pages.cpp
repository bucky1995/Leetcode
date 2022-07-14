int selectPaged(string arr){
    int zeroTotal = 0;
    int oneTotal = 0;

    for(int i=0;i<arr.size();i++){
        if(arr[i] == '0')   zeroTotal++;
        else    oneTotal++;
    }

    int zeroSoFar = 0;
    int oneSofar = 0;

    int res = 0;

    for(int i=0;i<arr.size();i++){
        int sum = 0;
        if(arr[i] == '0'){
            sum = oneSofar * (oneTotal-oneSofar);
            res+=sum;
            zeroSoFar++;
        }else{
            sum = zeroSoFar * (zeroTotal-zeroSoFar);
            res+=sum;
            oneSofar++;
        }
    }
    return res;
}