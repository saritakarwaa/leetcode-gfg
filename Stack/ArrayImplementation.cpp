#include<iostream>
using namespace std;
class Stack{
    int top;
    int arr[100];
public:
    Stack() { top=-1; }
    void push(int val){
        if(top==99){
            cout<<"Stack Overflow";
            return;
        }
        arr[++top]=val;
    }
    int pop(){
        if(top==-1){
            cout<<"Stack underflow";
            return;
        }
        return arr[top--];
    }
    int peek(){
        return (top==-1)? -1: arr[top];
    }
};