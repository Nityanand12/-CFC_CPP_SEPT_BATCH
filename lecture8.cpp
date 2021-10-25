#include<iostream>
#include<vector>
using namespace std;
void checkBit(){
  int num=11,m=3;
  int mask=(1<<(m-1));
  if((num&mask)==0){
    cout<<"Off Bit"<<"\n";
  }
  else{
    cout<<"On bit "<<"\n";
  }
}
void onBit(){
  int num=11,m=2;
  int mask=(1<<(m-1));
  int ans= (num|mask);
  cout<<ans<<"\n";
}
void offBit(){
  int num=11,m=2;
  int mask=(1<<(m-1));
  int ans=(num&(~mask));
  cout<<ans<<"\n";
}
void toggleBit(){
  int num=11,m=3;
  int mask=(1<<(m-1));
  int ans=(num^mask);
  cout<<ans<<"\n";
}
void q1(){
  vector<int>arr={10,11,25,11,10,16,21,16,25,18,21};
  int ans=0;
  for(int ele: arr){
    ans=(ans^ele);
  }
  cout<<ans<<"\n";
}
void q2(){
  vector<int>arr={10,11,25,11,10,37,16,21,16,25,18,21};
  int ans=0;
  for(int ele: arr){
    ans=(ele^ans);
  }
  int cnt=0;
  int ans1= ans;
  while(ans1%2!=1){
    ans1=ans1/2;
    cnt++;
  }
  int mask=(1<<cnt);
  int ans2=0;
  for(int ele: arr){
    if((mask&ele)==0){
      ans2= (ans2^ele);
    }
  }
  cout<<ans2<<" "<<(ans^ans2)<<"\n";
}
int main(){
  // checkBit();
  // onBit();
  // offBit();
  // toggleBit();
  // q1();
  q2();
  return 0;
}