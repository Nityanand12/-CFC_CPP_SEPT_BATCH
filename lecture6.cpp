#include<vector>
#include<iostream>
using namespace std;
void productOfArrayExceptItself(vector<int>&arr){
  int prod=1;
  vector<int>ans(arr.size(),1);
  for(int i=1;i<arr.size();i++){
    ans[i]=arr[i-1]*ans[i-1];
  }
  for(int i=arr.size()-1;i>=0;i--){
    ans[i]= ans[i]*prod;
    prod= prod*arr[i];
  }
  for(int ele: ans){
    cout<<ele<<" ";
  }
  cout<<"\n";
}
void gcdAndLcm(int a,int b){
  int m=a,n=b;
  while(m%n!=0){
    int rem= m%n;
    m=n;
    n=rem;
  }
  cout<<"GCD of "<<a<<" and "<<b<<" is "<<n<<"\n";
  cout<<"LCM of "<<a<<" and "<<b<<" is "<<(a*b)/n<<"\n";
}
void insertionSort(vector<int>&arr){
  for(int i=1;i<arr.size();i++){
    int key= arr[i];
    int j= i-1;
    while(j>=0&&arr[j]>key){
      arr[j+1]= arr[j];
      j--;
    }
    arr[j+1]= key;
  }
  for(int ele: arr){
    cout<<ele<<" ";
  }
  cout<<"\n";
}
int main(){
  vector<int>arr={5,2,3,6};
  // productOfArrayExceptItself(arr);
  // gcdAndLcm(18,27);
  insertionSort(arr);
  return 0;
}