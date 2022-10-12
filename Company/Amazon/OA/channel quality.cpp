long maximumQuality(vector<int> packets, int channels){
    if(packets.size() == 0) return 0;

    sort(packets.begin(), packets.end());

    int n = channels-1;

    long median = 0;

    while(n-->0){
        int val = packets.back();
        median+= val;
        packets.pop_back();
    }

    if(packets.size() == 0) return median;

    long val = 0;
    int mid = packets.size()/2;
    if(packets.size()%2 == 0){
        val = (packets[mid] +packets[mid-1])/2;
    }else{
        val = packets[mid];
    }

    return median+val;
}