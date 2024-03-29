/*
Question Link:- https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770
*/

#include <bits/stdc++.h> 
#include<stack>
int findMinimumCost(string str) {
  // Write your code here
  if(str.length()%2==1){
    return -1;
  }

  stack<char> s;

  for(int i=0; i<str.length(); i++){
    char ch = str[i];
    if(ch=='{'){
      s.push(ch);
    }
    else{
      if(!s.empty() && s.top()=='{'){
        s.pop();
      }
      else{
        s.push(ch);
      }
    }
  }

  //stack contains invalid expression

  int a=0, b=0;
  while(!s.empty()){
    if(s.top()=='{'){
      b++;
    }
    else{
      a++;
    }
    s.pop();
  }


  int ans = (a+1)/2 + (b+1)/2;
  return ans;
}