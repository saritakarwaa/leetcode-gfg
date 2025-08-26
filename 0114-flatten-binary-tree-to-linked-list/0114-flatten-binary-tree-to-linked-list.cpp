/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(vector<TreeNode*>&v,TreeNode* root){
        if(root==NULL) return;
        v.push_back(root);
        preorder(v,root->left);
        preorder(v,root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*>v;
        preorder(v,root);
        for(int i=0;i<v.size()-1;i++){
            v[i]->left=NULL;
            v[i]->right=v[i+1];
        }
        // v.back()->left=NULL;
        // v.back()->right=NULL;
    }
};