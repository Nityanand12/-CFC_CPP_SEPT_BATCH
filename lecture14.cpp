#include<vector>
#include<iostream>
using namespace std;
void nokiaKeyPadWithoutReturnType(vector<string>arr,string num,int idx,string ans){
  if(idx==num.length()){
    cout<<ans<<"\n";
    return;
  }
  char ch= num[idx];
  for(int i=0;i<arr[ch-'0'].length();i++){
    nokiaKeyPadWithoutReturnType(arr,num,idx+1,ans+arr[ch-'0'][i]);
  }
}
int main(){
  vector<string>arr={"abc","def","ghi","jkl","mno","pqr","stu","vuw","yz","-%*"};
  string num="284";
  nokiaKeyPadWithoutReturnType(arr,num,0,"");
  return 0;
}