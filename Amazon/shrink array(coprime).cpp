int gcd(int a, int b){
while(a!=0&&b!=0){
    if(a>b){
        a = a%b;
    }else{
        b = b%a;
    }
}
return max(a,b);
}

int lcm(int a, int b, int gcd){
return ((a/gcd)*b);
}
vector<int> shrink(vector<int> arr){
    vector<int> buffer;
    queue<int> nums;
    for(int num: arr)
        nums.push(num);
    while(!nums.empty()){
        int n = nums.front();
        buffer.push_back(n);
        nums.pop();
        while(!buffer.empty() && !nums.empty()){
            int g = gcd(buffer.back(), nums.front());
            if(g==1)    break;
            int l = lcm(buffer.back(), nums.front(), g);
            nums.front() = l;
            buffer.pop_back();
        }
    }
    return buffer;
}