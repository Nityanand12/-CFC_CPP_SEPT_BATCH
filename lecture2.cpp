#include<iostream>
using namespace std;
int main(){
  // int a;
  // cin>>a;
  // cout<<sizeof(a); 
  // cout<<2*a<<" "<<3*a;
  // cout<<2*a<<" ";
  // cout<<3*a;

  // cout<<2*a<<"\n"<<3*a;
  // cout<<2*a<<endl;
  // cout<<3*a;

  // char ch='p';
  // cout<<sizeof(ch)<<"\n";


  // int marks=85;
  // if(marks>=90){
  //   cout<<"A+ Grade"<<"\n";
  // }
  // else if(marks>=80){
  //   cout<<"A Grade"<<"\n";
  // }
  // else if(marks>=70){
  //   cout<<"B Grade"<<"\n";
  // }
  // else{
  //   cout<<"Grade Acche nhi h"<<"\n";
  // }



  // int a,b,c;
  // cin>>a>>b>>c;
  // if(a>b){
  //   if(a>c){
  //     cout<<"Maximum value is "<<a<<"\n";
  //   }
  //   else{
  //     cout<<"Maximum value is "<<c<<"\n";
  //   }
  // }
  // else{
  //   if(b>c){
  //     cout<<"Maximum value is "<<b<<"\n";
  //   }
  //   else{
  //     cout<<"Maximum value is "<<c<<"\n";
  //   }
  // }

  // int i=1;
  // for(;i<=10;){
  //   cout<<i*2<<" ";
  //   i++;
  // }

  // int j=1;
  // while(j<=5){
  //   cout<<j<<" ";
  //   j++;
  // }
  int n=8958946;
  int cnt=0;
  if(n==0) cnt=1;
  while(n!=0){
    n=n/10;
    // n/=10;
    cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}