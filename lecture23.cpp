#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

// 85. Maximal Rectangle
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<int>st;
//         st.push(-1);
//         int ans=0;
//         for(int i=0;i<heights.size();i++){
//             if(st.size()==1||heights[i]>heights[st.top()]){
//                 st.push(i);
//             }
//             else{
//                 while(st.size()!=1&&heights[i]<=heights[st.top()]){
//                     int id= st.top();
//                     st.pop();
//                     int val= (i-st.top()-1)*heights[id];
//                     ans=max(ans,val);
//                 }
//                 st.push(i);
//             }
//         }
//         int l= heights.size();
//         while(st.size()!=1){
//             int id= st.top();
//             st.pop();
//             int val= (l-st.top()-1)*heights[id];
//             ans=max(ans,val);
//         }
//         return ans;
//     }
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if(matrix.size()==0) return 0;
//         int ans=0;
//         vector<int>heights(matrix[0].size(),0);
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]!='0'){
//                     heights[j]++;
//                 }
//                 else{
//                     heights[j]=0;
//                 }
//             }
//              ans= max(ans,largestRectangleArea(heights));
//         }
//         return ans;
//     }
// };



int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(st.size()==1||heights[i]>heights[st.top()]){
                st.push(i);
            }
            else{
                while(st.size()!=1&&heights[i]<=heights[st.top()]){
                    int id= st.top();
                    st.pop();
                    int val= (i-st.top()-1)*heights[id];
                    ans=max(ans,val);
                }
                st.push(i);
            }
        }
        int l= heights.size();
        while(st.size()!=1){
            int id= st.top();
            st.pop();
            int val= (l-st.top()-1)*heights[id];
            ans=max(ans,val);
        }
        return ans;
    }
int main(){
  vector<int>heights={2,1,5,6,2,3};
 cout<<largestRectangleArea(heights);
  return 0;
}