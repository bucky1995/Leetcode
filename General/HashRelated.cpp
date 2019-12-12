#include <iostream> 
#include <unordered_map> 
#include <unordered_set> 
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int targetNum=target-nums[i];
            if(hash.find(targetNum)!=hash.end()){
                result.push_back(i);
                result.push_back(hash[targetNum]);
                return result;
            }
            hash[nums[i]]=i;
        }
        return result;
    }

    int firstUniqChar(string s) {
        vector<int> count(256,0);
        for(int i=0;i<s.size();i++){
            count[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(count[s[i]]==1)
                return i;
        }
        return -1;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> counts(256,0),countp(256,0);
        unordered_map<char,int> count;
        if(s.size()==0||p.size()>s.size()){
            return res;
        }
        for(int i=0;i<p.size();i++){
            counts[s[i]]++;
            countp[p[i]]++;
        }
        if(counts==countp){
            res.push_back(0);
        }
        counts[s[0]]--;
        for(int i=1;i<=s.size()-p.size();i++){
            counts[s[i+p.size()-1]]++;
            if(counts==countp){
                res.push_back(i);
            }
            counts[s[i]]--;
        }
        return res;
    }

    bool isIsomorphic(string s, string t) {
        if( s.length()!=t.length()){
            return false;
        }
        int length=t.length();
        
        unordered_map<char,char> hashstot;
        unordered_map<char,char> hashttos;
        for(int i=0;i<length;i++){
            if(hashstot.find(s[i])!=hashstot.end()){
                {   
                    if(hashstot[s[i]]!=t[i]){
                        return false;
                    }
                }
            }
            else if(hashttos.find(t[i])!=hashttos.end()){
                    if(hashttos[t[i]]!=s[i]){
                        return false;
                    }
            }else{
                hashstot[s[i]]=t[i];
                hashttos[t[i]]=s[i];
            }
        }
        return true;
    }

};

class ValidWordAbbr {
/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
private:
    unordered_map<string,int> dichash;
    unordered_map<string,int> abbrdichash;
public:
    string abbr(string word){
        string abbr;
        if(word.size()>2){
            abbr.push_back(word[0]);
            abbr+=to_string(word.size()-2);
            abbr.push_back(word.back());
        }else{
            abbr=word;
        }
        
        return abbr;
    }
    
    ValidWordAbbr(vector<string>& dictionary) {
        string word;
        for(int i=0;i<dictionary.size();i++){
            word=abbr(dictionary[i]);
            dichash[dictionary[i]]++;
            abbrdichash[word]++;
        }
    }
    
    bool isUnique(string word) {
        string abb;
        abb=abbr(word);
        
        if(dichash.find(word)!=dichash.end()){
            return dichash[word]==abbrdichash[abb];
        }else{
            return abbrdichash[abb]==0;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());
        int res=0,pre,next;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end()){
                hash.erase(nums[i]);
                pre=nums[i]-1;
                next=nums[i]+1;
                while(hash.find(pre)!=hash.end()){
                    hash.erase(pre);
                    pre--;
                }
                while(hash.find(next)!=hash.end()){
                    hash.erase(next);
                    next++;
                }
                res=max(res,next-pre-1);
            }
        }
        return res;
    }
};

