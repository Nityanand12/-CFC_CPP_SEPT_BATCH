#include<iostream>
using namespace std;


// 735. Asteroid Collision
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int>st;
//         for(int i=0;i<asteroids.size();i++){
//             if(asteroids[i]>0){
//                 st.push(asteroids[i]);
//             }
//             else{
//                 while(st.size()>0&&abs(asteroids[i])>st.top()&&st.top()>0){
//                     st.pop();
//                 }
//                 if(st.size()==0||st.top()<0){
//                     st.push(asteroids[i]);
//                 }
//                 else if(abs(asteroids[i])==st.top()){
//                     st.pop();
//                 }
//             }
//         }
//         vector<int>ans(st.size(),0);
//         for(int i=ans.size()-1;i>=0;i--){
//             ans[i]= st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };



//42. Trapping Rain Water
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ans=0;
//         vector<int>left(height.size(),0);
//         vector<int>right(height.size(),0);
//         for(int i=1;i<height.size();i++){
//             left[i]=max(left[i-1],height[i-1]);
//         }
//         for(int i=height.size()-2;i>=0;i--){
//             right[i]=max(right[i+1],height[i+1]);
//         }
//         for(int i=0;i<height.size();i++){
//             int k= min(left[i],right[i])-height[i];
//             if(k>0) ans+=k;
//         }
//         return ans;
//     }
// };



// 921. Minimum Add to Make Parentheses Valid
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char>st;
//         for(int i=0;i<s.length();i++){
//             if(st.size()!=0&&st.top()=='('&&s[i]==')'){
//                 st.pop();
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//         return st.size();
//     }
// };



// 1021. Remove Outermost Parentheses
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string ans="";
//         int cnt=0,id=1;
//         for(int i=0;i<s.length();i++){
//             char ch= s[i];
//             if(ch=='('){
//                 cnt++;
//             }
//             else{
//                 cnt--;
//             }
//             if(cnt==0){
//                 ans+= s.substr(id,i-id);
//                 id=i+2;
//             }
//         }
//         return ans;
//     }
// };




//1047. Remove All Adjacent Duplicates In String
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char>st;
//         for(int i=0;i<s.length();i++){
//             int ch= s[i];
//             if(st.size()==0){
//                 st.push(ch);
//                 continue;
//             }
//             if(ch==st.top()){
//                 st.pop();
//             }
//             else{
//                 st.push(ch);
//             }
//         }
//         string finalAns="";
//         while(st.size()!=0){
//             finalAns=st.top()+finalAns;
//             st.pop();
//         }
//         return finalAns;
//     }
// };


int main(){
  cout<<"Hii"<<"\n";
  return 0;
}