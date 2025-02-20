#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Stack{
    Node* top;
    public: 
        Stack() {
            top=NULL;
        }
        void push(int val){
            Node* newnode=new Node(val);
            newnode->next=top;
            top=newnode;
        }
        int pop(){
            if(!top) return -1;
            int val=top->data;
            Node* temp=top;
            top=top->next;
            delete temp;
            return val;
        }
        int peek() {
            return top ? top->data : -1;
        }
};
