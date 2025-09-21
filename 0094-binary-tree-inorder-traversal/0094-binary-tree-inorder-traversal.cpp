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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*>s;
        vector<int>v;
        TreeNode* node=root;
        while(true){
            if(node){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()) break;
                node=s.top();
                s.pop();
                v.push_back(node->val);
                node=node->right;
            }
        }
        return v;
    }
};