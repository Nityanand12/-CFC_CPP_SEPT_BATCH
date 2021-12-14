#include<vector>
#include<iostream>
using namespace std;
int fibonacciWithRecursion(int n){
  if(n<=1){
    return n;
  }
  int left= fibonacciWithRecursion(n-1);
  int right= fibonacciWithRecursion(n-2);
  return left+right;
}

int fibonacciWithMemoization(int n,vector<int>&dp){
  if(n<=1){
    return dp[n]= n;
  }
  if(dp[n]!=0){
    return dp[n];
  }
  int left= fibonacciWithMemoization(n-1,dp);
  int right= fibonacciWithMemoization(n-2,dp);
   dp[n]= left+right;
   return dp[n];
}
int fibonacciWithTabulation(int n,vector<int>&dp){
  for(int i=0;i<=n;i++){
    if(i<=1){
      dp[i]=i;
      continue;
    }
    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n];
}
int permutationWithRecursion(vector<int>&arr,int tar){
  if(tar==0){
    return 1;
  }
  int ans=0;
  for(int i=0;i<arr.size();i++){
    if(tar-arr[i]>=0){
      ans+=permutationWithRecursion(arr,tar-arr[i]);
    }
  }
  return ans;
}
int permutationWithMemoization(vector<int>&arr,int tar,vector<int>&dp){
  if(tar==0){
    return dp[tar]= 1;
  }
  if(dp[tar]!=-1){
    return dp[tar];
  }
  int ans=0;
  for(int i=0;i<arr.size();i++){
    if(tar-arr[i]>=0){
      ans+=permutationWithMemoization(arr,tar-arr[i],dp);
    }
  }
  return dp[tar]= ans;
}
int permutationWithTabulation(vector<int>&arr,int tar,vector<int>&dp){
  for(int i=0;i<=tar;i++){
    if(i==0){
      dp[i]=1;
      continue;
    }
    int ans=0;
    for(int j=0;j<arr.size();j++){
      if(i-arr[j]>=0){
        ans+=dp[i-arr[j]];
      }
    }
    dp[i]= ans;
  }
  return dp[tar];
}
void permutation(){
  vector<int>arr={1,2,3,4};
  int tar=4;
  // cout<<permutationWithRecursion(arr,tar)<<"\n";
  vector<int>dp(tar+1,-1);
  // cout<<permutationWithMemoization(arr,tar,dp)<<"\n";
  cout<<permutationWithTabulation(arr,tar,dp)<<"\n";
  for(int i=0;i<dp.size();i++){
    cout<<dp[i]<<" ";
  }
}
int main(){
  int n=43;
  vector<int>dp(n+1,0);
  // cout<<fibonacciWithRecursion(n)<<"\n";
  // cout<<fibonacciWithMemoization(n,dp)<<"\n";
  // for(int i=0;i<=n;i++){
  //   cout<<dp[i]<<" ";
  // }
  // cout<<fibonacciWithTabulation(n,dp)<<"\n";

  permutation();
  return 0;
}