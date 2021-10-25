#include<iostream>
#include<vector>
using namespace std;
int maxOfArray(vector<int>&arr,int idx){
  if(idx==arr.size()-1){
    return arr[idx];
  }
  int m=maxOfArray(arr,idx+1);
  if(m>arr[idx]){
    return m;
  }
  else{
    return arr[idx];
  }
}
void fun(int n,int level){
  if(n<=2){
    cout<<"Base "<<n<<" @ "<<level<<"\n";
    return;
  }
  cout<<"Pre "<<n<<" @ "<<level<<"\n";
  fun(n-1,level+1);
  cout<<"In "<<n<<" @ "<<level<<"\n";
  fun(n-2,level+1);
  cout<<"Post "<<n<<" @ "<<level<<"\n";
}
void mazePath(int sr,int sc,int er,int ec,string ans){
  if(sr==er&&sc==ec){
    cout<<ans<<"\n";
    return;
  }
  if(sc+1<=ec){
    mazePath(sr,sc+1,er,ec,ans+"H");
  }
  if(sr+1<=er){
    mazePath(sr+1,sc,er,ec,ans+"V");
  }
}
int main(){
  vector<int>arr={7,19,27,6,4,9};
  // cout<<maxOfArray(arr,0)<<"\n";
  // fun(5,0);
  mazePath(0,0,2,2,"");
  return  0;
}