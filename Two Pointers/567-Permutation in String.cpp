class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map<char, int> need;
        for(int i=0;i<s1.size();i++){
            need[s1[i]]++;
        }
        unordered_map<char, int> window;
        for(int i=0;i<s1.size();i++){
            if(need.find(s2[i]) != need.end())
                window[s2[i]]++;
        }
        int left = 0;
        int right = s1.size()-1;
        while(right<s2.size()){
            if(need == window)  return true;
            if(need.find(s2[left]) != need.end())
                window[s2[left]]--;
            left++;
            right++;
            if(need.find(s2[right]) != need.end())
                window[s2[right]]++;
        }
        return false;
    }
};