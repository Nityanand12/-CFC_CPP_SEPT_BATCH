#include<iostream>
#include<stack>
#include<vector>
using namespace std;
char openBracket(char ch){
  if(ch=='{') return '}';
  else if(ch=='[') return ']';
  else return ')';
}
void balancedParenthesis(){
   stack<int>st;
  string str = "{{[]()}()}";
  for(int i=0;i<str.length();i++){
    if(str[i]=='['||str[i]=='{'||str[i]=='('){
      st.push(i);
    }
    else{
      if(st.size()==0||str[i]!=openBracket(str[st.top()])){
        cout<<"Parenthesis is not balanced"<<"\n";
        return ;
      }
      else{
        st.pop();
      }
    }
  }
  if(st.size()==0){
    cout<<"Parenthesis is balanced"<<"\n";
  }
  else{
    cout<<"Parenthesis is not balanced"<<"\n";
  }
}
void nextGreaterElement(){
  stack<int>st;
  vector<int>arr={7,2,8,2,1,9,20,6,18,7,15};
  vector<int>ans(arr.size(),0);
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]<arr[i]){
      ans[st.top()]=arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    ans[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Next Greater Element of "<<arr[i]<<" is "<<ans[i]<<"\n";
  }
}
void nextSmallerElement(){
  stack<int>st;
  vector<int>arr={7,2,8,2,1,9,20,6,18,7,15};
  vector<int>ans(arr.size(),0);
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]>arr[i]){
      ans[st.top()]=arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    ans[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Next Smaller Element of "<<arr[i]<<" is "<<ans[i]<<"\n";
  }
}

void previousGreaterElement(){
  stack<int>st;
  vector<int>arr={7,2,8,2,1,9,20,6,18,7,15};
  vector<int>ans(arr.size(),0);
  for(int i=arr.size()-1;i>=0;i--){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]<arr[i]){
      ans[st.top()]=arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    ans[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Previous Greater Element of "<<arr[i]<<" is "<<ans[i]<<"\n";
  }
}
void previousSmallerElement(){
  stack<int>st;
  vector<int>arr={7,2,8,2,1,9,20,6,18,7,15};
  vector<int>ans(arr.size(),0);
  for(int i=arr.size()-1;i>=0;i--){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]>arr[i]){
      ans[st.top()]=arr[i];
      st.pop();
    }
    st.push(i);
  }
  while(st.size()!=0){
    ans[st.top()]=-1;
    st.pop();
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Previous Smaller Element of "<<arr[i]<<" is "<<ans[i]<<"\n";
  }
}
int main(){
  balancedParenthesis();
  // nextGreaterElement();
  // nextSmallerElement();
  // previousGreaterElement();
  previousSmallerElement();
  return 0;
}