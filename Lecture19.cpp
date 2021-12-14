#include<iostream>
using namespace std;
void fun1(int val){
  val=val*2;
  cout<<val<<"\n";
}
void fun2(int *val){
  *val=*val*2;
  cout<<*val<<"\n";
}
void pointer(){
  // int a=10;
  // int *p=&a;
  // // p=&a;
  // *p=15;
  // cout<<p<<"\n";
  // cout<<a<<"\n";
  // int **q=&p;
  // int ***r=&q;
  // cout<<*p<<" "<<**q<<" "<<*r<<"\n";
  // cout<<p<<" "<<**r<<"\n";

  // int arr[]={10,20,30,40,50,60};
  // cout<<*arr<<"\n";
  // int *w=arr;
  // cout<<*(w+0)<<" "<<*(arr+0)<<" "<<arr[0]<<"\n";
  // cout<<*(w+1)<<" "<<*(arr+1)<<" "<<arr[1]<<"\n";
  // cout<<*(w+2)<<" "<<*(arr+2)<<" "<<arr[2]<<"\n";
  // cout<<*(w+3)<<" "<<*(arr+3)<<" "<<arr[3]<<"\n";
  // cout<<*(w+4)<<" "<<*(arr+4)<<" "<<arr[4]<<"\n";
  // cout<<*(w+5)<<" "<<*(arr+5)<<" "<<arr[5]<<"\n";


  int val=10;
  // fun1(val);
  // cout<<val<<"\n";
  fun2(&val);
  cout<<val<<"\n";
}

int main(){
  pointer();
  return 0;
}