/*
Question Link:- https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875
*/


void insertAtBottom(stack<int> &stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int top = stack.top();
    stack.pop();

    insertAtBottom(stack, x);

    stack.push(top);
}

void reverseStack(stack<int> &stack) {

  if (stack.empty()) {
    return;
  }

  int top = stack.top();
  stack.pop();



  reverseStack(stack);

  insertAtBottom(stack, top);
  
}