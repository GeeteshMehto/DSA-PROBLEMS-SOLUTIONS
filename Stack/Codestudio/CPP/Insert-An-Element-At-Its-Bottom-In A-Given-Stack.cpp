/*
QUestion Link:- https://www.codingninjas.com/studio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166
*/

#include <bits/stdc++.h> 


void solve(stack<int>& myStack, int x){

    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int element = myStack.top();
    myStack.pop();
    

    solve(myStack, x);
    myStack.push(element);


}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{

    solve(myStack, x);

    return myStack;
}
