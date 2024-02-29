/*
Question Link:- https://www.codingninjas.com/studio/problems/redundant-brackets_975473
*/

#include <bits/stdc++.h> 
#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.

    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){

                bool isRedundant = true;

                while(st.top()!='('){
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant){
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}
