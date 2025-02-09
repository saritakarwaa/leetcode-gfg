#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
    
        Node(int val) {
            data = val;
            left = right = NULL;
        }
};
    class Solution {
      public:
        // Function to return maximum path sum from any node in a tree.
        int dfs(Node* root, int &maxi){
            if(root==NULL) return 0;
            int left=max(0,dfs(root->left,maxi));
            int right=max(0,dfs(root->right,maxi));
            maxi=max(maxi,root->data+left+right);
            return root->data+max(left,right);
        }
        int findMaxSum(Node *root) {
            int maxi=INT_MIN;
            dfs(root,maxi);
            return maxi;
        }
    };