#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int mcmWithRecursion(vector<int>&arr,int i,int j){
  if(i+1==j){
    return 0;
  }
  int ans=1000000000;
  for(int cut=i+1;cut<j;cut++){
    int left=mcmWithRecursion(arr,i,cut);
    int right= mcmWithRecursion(arr,cut,j);
    ans=min(ans,left+right+arr[i]*arr[cut]*arr[j]);
  }
  return ans;
}
int mcmWithMemoization(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
  if(i+1==j){
    return dp[i][j]= 0;
  }
  if(dp[i][j]!=0){
    return dp[i][j];
  }
  int ans=1000000000;
  for(int cut=i+1;cut<j;cut++){
    int left=mcmWithMemoization(arr,i,cut,dp);
    int right= mcmWithMemoization(arr,cut,j,dp);
    ans=min(ans,left+right+arr[i]*arr[cut]*arr[j]);
  }
  return dp[i][j]= ans;
}
int mcmWihTabulation(vector<int>&arr,vector<vector<int>>&dp){
  for(int gap=1;gap<arr.size();gap++){
    for(int i=0,j=gap;j<arr.size();i++,j++){
      if(i+1==j){
        dp[i][j]= 0;
        continue;
      }
      int ans=1000000000;
      for(int cut=i+1;cut<j;cut++){
        int left=dp[i][cut];
        int right=dp[cut][j];
        ans=min(ans,left+right+arr[i]*arr[cut]*arr[j]);
      }
     dp[i][j]= ans;
    }
  }
  return dp[0][dp[0].size()-1];
}
void mcm(){
  vector<int>arr={7,3,5,8,2};
  vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
  // cout<<mcmWithRecursion(arr,0,arr.size()-1)<<"\n";
  // cout<<mcmWithMemoization(arr,0,arr.size()-1,dp)<<"\n";
  cout<<mcmWihTabulation(arr,dp)<<"\n";
  for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int editDistanceWithRecursion(string s1,string s2,int s1Pos,int s2Pos){
  if(s1Pos==0){
    return s2Pos;
  }
  if(s2Pos==0){
    return s1Pos;
  }
  if(s1[s1Pos-1]==s2[s2Pos-1]){
    return editDistanceWithRecursion(s1,s2,s1Pos-1,s2Pos-1);
  }
  else{
   int a= editDistanceWithRecursion(s1,s2,s1Pos-1,s2Pos);//insert
   int b= editDistanceWithRecursion(s1,s2,s1Pos,s2Pos-1);//delete
   int c= editDistanceWithRecursion(s1,s2,s1Pos-1,s2Pos-1);//swap
   return min(a,min(b,c))+1;
  }
}
int editDistanceWithMemoization(string s1,string s2,int s1Pos,int s2Pos,vector<vector<int>>&dp){
if(s1Pos==0){
    return dp[s1Pos][s2Pos]= s2Pos;
  }
  if(s2Pos==0){
    return dp[s1Pos][s2Pos]= s1Pos;
  }
  if(dp[s1Pos][s2Pos]!=0){
    return dp[s1Pos][s2Pos];
  }
  if(s1[s1Pos-1]==s2[s2Pos-1]){
    return dp[s1Pos][s2Pos]= editDistanceWithMemoization(s1,s2,s1Pos-1,s2Pos-1,dp);
  }
  else{
   int a= editDistanceWithMemoization(s1,s2,s1Pos-1,s2Pos,dp);//insert
   int b= editDistanceWithMemoization(s1,s2,s1Pos,s2Pos-1,dp);//delete
   int c= editDistanceWithMemoization(s1,s2,s1Pos-1,s2Pos-1,dp);//swap
   return dp[s1Pos][s2Pos]= min(a,min(b,c))+1;
  }
}
int editDistanceWithTabulation(string s1,string s2,vector<vector<int>>&dp){
  for(int s1Pos=0;s1Pos<=s1.length();s1Pos++){
    for(int s2Pos=0;s2Pos<=s2.length();s2Pos++){
   if(s1Pos==0){
     dp[s1Pos][s2Pos]= s2Pos;
     continue;
  }
  if(s2Pos==0){
    dp[s1Pos][s2Pos]= s1Pos;
    continue;
  }
  if(s1[s1Pos-1]==s2[s2Pos-1]){
    dp[s1Pos][s2Pos]= dp[s1Pos-1][s2Pos-1];
  }
  else{
   int a= dp[s1Pos-1][s2Pos];//insert
   int b= dp[s1Pos][s2Pos-1];//delete
   int c= dp[s1Pos-1][s2Pos-1];//swap
  dp[s1Pos][s2Pos]= min(a,min(b,c))+1;
  }      
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
}
void editDistance(){
  string s1="abcd";
  string s2="acebd";
  // cout<<editDistanceWithRecursion(s1,s2,s1.length(),s2.length())<<"\n";
  vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
  //  cout<<editDistanceWithMemoization(s1,s2,s1.length(),s2.length(),dp)<<"\n";
  cout<<editDistanceWithTabulation(s1,s2,dp)<<"\n";
    for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main(){
  // mcm();
  editDistance();
  return 0;
}