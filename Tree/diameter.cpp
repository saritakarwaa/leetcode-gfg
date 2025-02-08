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

int diameter(Node* root,int &d){
    if(root==NULL) return 0;
    int l=diameter(root->left,d);
    int r=diameter(root->right,d);
    d=max(d,l+r);
    return 1+max(l,r);
}

int main() {

    // Constructed binary tree is
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
      root->right->left = new Node(9);
    int d;
    cout << diameter(root,d) << endl;
  
    return 0;
}