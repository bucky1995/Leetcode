#include <iostream> 
#include <unordered_map> 
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> searchRange_fast(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                res[0]=i;
                break;
            }
            if(nums[i]>target){
                return res;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                res[1]=i;
                break;
            }
        }
        return res;
    }
    vector<int> searchRange_binarySearch(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        for(int low=0,high=nums.size()-1;low<=high;){
            int mid = low+(high -low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
            if(nums[mid]==target){
                res[0]=mid;
                res[1]=mid;
                while(res[0]-1>=0){
                    if(nums[res[0]-1]==target){
                        res[0]--;
                    }else{
                        break;
                    }
                }
                while(res[1]+1<nums.size()){
                    if(nums[res[1]+1]==target){
                        res[1]++;
                    }else{
                        break;
                    }
                }
                break;
            }
        }
        return res;
    }

    int guess(int num);
    int guessNumber(int n) {
        int low=1,high=n,g,res;
        while(low<=high){   //非常重要，就算只剩下一个元素也要继续查找
            g=low+(high-low)/2;//计算新的查找值，(low+high)/2可能会越界
            res=guess(g);
            
            if(res==0){
                return g;
            }
              
            if(res==-1)
                high=g-1;
            else
                low=g+1;
        }
        return 0;
    }

    TreeNode* Find(TreeNode* root, TreeNode* p,TreeNode* min){
        if(root==NULL) return min;
        if(root->val > p->val){
            if(min!=NULL){
                min=root->val-p->val < min->val-p->val ? root:min;
            }else{
                min=root;
            }
        }
        if(root->val<=p->val){
            min = Find(root->right,p,min);
        }else if(root->val>p->val){
            min = Find(root->left,p,min);
        }
        return min;
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* min=NULL;
        min = Find(root,p,min);
        return min;
    }
};