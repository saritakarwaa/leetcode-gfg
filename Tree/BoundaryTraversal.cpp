#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
};
class Solution {
    public:
      void leftBoundary(Node* root,vector<int>&result){
          if (!root || (!root->left && !root->right)) return;
          result.push_back(root->data);  // Add before recursion
          if (root->left) leftBoundary(root->left, result);
          else leftBoundary(root->right, result);
      }
      void leaf(Node* root,vector<int>&result){
          if (!root) return;
          if (!root->left && !root->right) {
              result.push_back(root->data);
              return;
          }
          leaf(root->left, result);
          leaf(root->right, result);
      }
      void rightBoundary(Node* root,vector<int>&result){
          if (!root || (!root->left && !root->right)) return;
          if (root->right) rightBoundary(root->right, result);
          else rightBoundary(root->left, result);
          result.push_back(root->data);  // Add after recursion (reverse order)
      }
      vector<int> boundaryTraversal(Node *root) {
          vector<int>result;
          if(root==NULL) return result;
          result.push_back(root->data);
          if(root->left==NULL && root->right==NULL) return result;
          leftBoundary(root->left,result);
          leaf(root,result);
          rightBoundary(root->right,result);
          return result;
      }
  };