#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int lcsRecursion(string x, string y, int xPos, int yPos)
{
  if (xPos == 0 || yPos == 0)
  {
    return 0;
  }
  if (x[xPos - 1] == y[yPos - 1])
  {
    return lcsRecursion(x, y, xPos - 1, yPos - 1) + 1;
  }
  else
  {
    int left = lcsRecursion(x, y, xPos - 1, yPos);
    int right = lcsRecursion(x, y, xPos, yPos - 1);
    return max(left, right);
  }
}

int lcsMemoization(string x, string y, int xPos, int yPos, vector<vector<int>> &dp)
{
  if (xPos == 0 || yPos == 0)
  {
    return dp[xPos][yPos] = 0;
  }
  if (dp[xPos][yPos] != -1)
  {
    return dp[xPos][yPos];
  }
  if (x[xPos - 1] == y[yPos - 1])
  {
    return dp[xPos][yPos] = lcsMemoization(x, y, xPos - 1, yPos - 1, dp) + 1;
  }
  else
  {
    int left = lcsMemoization(x, y, xPos - 1, yPos, dp);
    int right = lcsMemoization(x, y, xPos, yPos - 1, dp);
    return dp[xPos][yPos] = max(left, right);
  }
}

int lcsTabulation(string x, string y, vector<vector<int>> &dp)
{
  for (int xPos = 0; xPos <= x.length(); xPos++)
  {
    for (int yPos = 0; yPos <= y.length(); yPos++)
    {
      if (xPos == 0 || yPos == 0)
      {
         dp[xPos][yPos] = 0;
         continue;
      }
      if (x[xPos - 1] == y[yPos - 1])
      {
        dp[xPos][yPos] = dp[xPos-1][yPos-1]+1;
      }
      else
      {
        int left = dp[xPos-1][yPos];
        int right = dp[xPos][yPos-1];
        dp[xPos][yPos] = max(left, right);
      }
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
}
void lcs()
{
  string x = "Saturday";
  string y = "Sunday";
  // cout<<lcsRecursion(x,y,x.length(),y.length())<<"\n";
  vector<vector<int>> dp(x.length() + 1, vector<int>(y.length() + 1, -1));
  // cout<<lcsMemoization(x,y,x.length(),y.length(),dp)<<"\n";
  cout << lcsTabulation(x, y, dp) << "\n";
  for (int i = 0; i < dp.size(); i++)
  {
    for (int j = 0; j < dp[0].size(); j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}
int lis(vector<int>&arr){
  vector<int>dp(arr.size(),0);
  int finalAns=0;
  for(int i=0;i<arr.size();i++){
    int ans=0;
    for(int j=i-1;j>=0;j--){
      if(arr[j]<arr[i]){
        ans=max(ans,dp[j]);
      }
    }
    dp[i]= ans+1;
    finalAns=max(finalAns,dp[i]);
  }
return finalAns;

}
void lis(){
  vector<int>arr={2,1,6,8,4,9,3,17,2};
  cout<<lis(arr)<<"\n";
}
int main()
{
  // lcs();
  lis();
  return 0;
}