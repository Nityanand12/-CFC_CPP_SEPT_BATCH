#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int unboundedKnapSackWithRecursion(vector<int>&wt,vector<int>&val,int cap){
  if(cap==0){
    return 0;
  }
  int ans=0;
  for(int i=0;i<wt.size();i++){
    if(cap-wt[i]>=0){
      ans=max(ans, unboundedKnapSackWithRecursion(wt,val,cap-wt[i])+val[i]);
    }
  }
  return ans;
}
int unboundedKnapSackWithMemoization(vector<int>&wt,vector<int>&val,int cap,vector<int>&dp){
  if(cap==0){
    return dp[cap]= 0;
  }
  if(dp[cap]!=0){
    return dp[cap];
  }
  int ans=0;
  for(int i=0;i<wt.size();i++){
    if(cap-wt[i]>=0){
      ans=max(ans, unboundedKnapSackWithMemoization(wt,val,cap-wt[i],dp)+val[i]);
    }
  }
  return dp[cap]= ans;
}
int unboundedKnapSackWithTabulation(vector<int>&wt,vector<int>&val,vector<int>&dp){
  for(int cap=0;cap<dp.size();cap++){
    if(cap==0){
     dp[cap]= 0;
     continue;
  }
  int ans=0;
  for(int i=0;i<wt.size();i++){
    if(cap-wt[i]>=0){
      ans=max(ans, dp[cap-wt[i]]+val[i]);
    }
  }
  dp[cap]= ans;
  }
  return dp[dp.size()-1];
}


void unboundedKnapSack(){
  vector<int>wt={2,3,1,4};
  vector<int>val={20,13,8,38};
  int cap=5;
  cout<<unboundedKnapSackWithRecursion(wt,val,cap)<<"\n";
  vector<int>dp(cap+1,0);
  // cout<<unboundedKnapSackWithMemoization(wt,val,cap,dp)<<"\n";
  // for(int i=0;i<dp.size();i++){
  //   cout<<dp[i]<<" ";
  // }
  cout<<unboundedKnapSackWithTabulation(wt,val,dp)<<"\n";
}
int knapSackWithRecursion(vector<int>&wt,vector<int>&val,int cap,int pos){
  if(cap==0||pos==0){
    return 0;
  }
  int left=0,right=0;
  left=knapSackWithRecursion(wt,val,cap,pos-1);
  if(cap-wt[pos-1]>=0){
    right=knapSackWithRecursion(wt,val,cap-wt[pos-1],pos-1)+val[pos-1];
  }
  return max(left,right);
}

int knapSackWithMemoization(vector<int>&wt,vector<int>&val,int cap,int pos,vector<vector<int>>&dp){
  if(cap==0||pos==0){
    return dp[pos][cap]= 0;
  }
  if(dp[pos][cap]!=0){
    return dp[pos][cap];
  }
  int left=0,right=0;
  left=knapSackWithMemoization(wt,val,cap,pos-1,dp);
  if(cap-wt[pos-1]>=0){
    right=knapSackWithMemoization(wt,val,cap-wt[pos-1],pos-1,dp)+val[pos-1];
  }
  return dp[pos][cap]= max(left,right);
}


int knapSackWithTabulation(vector<int>&wt,vector<int>&val,int cap,int pos,vector<vector<int>>&dp){
  for(int i=0;i<=pos;i++){
    for(int j=0;j<=cap;j++){
      if(i==0||j==0){
        dp[i][j]=0;
        continue;
      }
      int left=0,right=0;
      left= dp[i-1][j];
      if(j-wt[i-1]>=0){
        right=dp[i-1][j-wt[i-1]]+val[i-1];
      }
      dp[i][j]=max(left,right);
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
}
void knapSack(){
  vector<int>wt={2,3,1,4};
  vector<int>val={20,13,8,38};
  int cap=5;
  // cout<<knapSackWithRecursion(wt,val,cap,wt.size())<<"\n";
  vector<vector<int>>dp(wt.size()+1,vector<int>(cap+1,0));
  // cout<<knapSackWithMemoization(wt,val,cap,wt.size(),dp)<<"\n";

  cout<<knapSackWithTabulation(wt,val,cap,wt.size(),dp)<<"\n";
    for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main(){
  // unboundedKnapSack();
  knapSack();
  return 0;
}