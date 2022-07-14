class Solution_naive {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int r = INT_MIN;
        
        for(int i=0;i<houses.size();i++){
            int house = houses[i];
            int min_r_for_house = findMinR(house, heaters);
            r = max(min_r_for_house, r);
        }
        return r;
    }
    
    int findMinR(int house, vector<int> heaters){
        int left =0;
        int right = heaters.size()-1;
        int min_r = INT_MAX;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            int diff = abs(heaters[mid]-house);
            min_r = min(min_r,diff);
            
            if(heaters[mid] == house){
                return 0;
            }else{
                if(heaters[mid]<house){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return min_r;
    }
};


class Solution {
public:
    bool isAllWarmed(vector<int>& houses, vector<int>& heaters, int r){
        int cur = 0;
        int left = heaters[cur]-r;
        int right = heaters[cur]+r;
        
        for(int i=0;i<houses.size();i++){
            int house = houses[i];
            if(left<=house && house<=right){
                continue;
            }else{
                cur++;
                if(cur>=heaters.size()) return false;
                else{
                    left = heaters[cur]-r;
                    right = heaters[cur]+r;       
                    i--;
                }
            }
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l = 0;
        int r = INT_MAX;
        int min_r = -1;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isAllWarmed(houses, heaters, mid)){
                min_r = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return min_r;
    }
};