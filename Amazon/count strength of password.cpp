
int uniqueLetterString_brute(string s) {
    int res =0;
    
    int window_size = 1;
    int N = s.size();
    while(window_size<=N){
        unordered_map<char,int> map;
        unordered_set<string> hash;
        for(int i=0;i<window_size;i++){
            map[s[i]]++;
        }
        hash.insert(s.substr(0,window_size));
        cout<<s.substr(0,window_size)<<endl;
        res+=map.size();
        int left = 1;
        int right = left+window_size-1;
        while(right<N){
            map[s[left-1]]--;
            if(map[s[left-1]] == 0){
                map.erase(s[left-1]);
            } 
            map[s[right]]++;
            
            cout<<s.substr(left,window_size)<<endl;
            res+=map.size();
            hash.insert(s.substr(left,window_size));
            right++;
            left++;
        }
        window_size++;
    }
    return res;
}

