class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size();
        
        while(left<right){
            int mid = left+(right-left)/2;
            if(letters[mid]<=target)    left = mid+1;
            else    right = mid;
        }
        if(left>=letters.size())    return letters.front();
        else    return letters[left];
    }
};