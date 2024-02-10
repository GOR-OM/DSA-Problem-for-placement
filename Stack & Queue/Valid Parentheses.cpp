#include<bits/stdc++.h>
using namespace std ;



bool isValidParenthesis(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]== '('){
            st.push(s[i]);
        }
        else{
            if(st.empty())return false;
            char t = st.top();
            st.pop();
            if(s[i]=='}'  && t!='{')return false ;
            else if(s[i]==')' && t!= '(')return false;
            else if(s[i]== ']' && t!='[')return false ;
        }
    }
    if(st.empty())return true ;
    return false ;
}