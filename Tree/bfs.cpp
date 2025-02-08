#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
//using queue
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int len=q.size();
        ans.push_back({});
        vector<int>level;
        for(int i=0;i<len;i++){
            Node* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}



int main() {
    // Create binary tree
    //      1         
    //     / \       
    //    3   2      
    //          \   
    //           4 
    //          /  \
    //         6    5
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);

    // Perform level order traversal
    vector<vector<int>> res = levelOrder(root);

    // Print the result
    for (vector<int> level : res)
        for (int data : level)
            cout << data << " ";
}

//using recursion
// void level(Node*root, int level,vector<vector<int>>&res){
//     if(root==NULL) return;
//     if(level==res.size()) res.push_back({root->data});
//     else res[level].push_back(root->data);
//     level(root->left,level+1,res);
//     level(root->right,level+1,res);

// }