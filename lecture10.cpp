#include<vector>
#include<iostream>
using namespace std;
void exitPoint(vector<vector<int>>&arr){
  int dir=0;
  int sr=0,sc=0;
  while(true){
    dir=(dir+arr[sr][sc])%4;
    if(dir==0){
      sc++;
    }
    else if(dir==1){
      sr++;
    }
    else if(dir==2){
      sc--;
    }
    else{
      sr--;
    }
    if(sr==arr.size()){
      sr=sr-1;
      break;
    }
    else if(sc==arr[sr].size()){
      sc=sc-1;
      break;
    }
    else if(sc==-1){
      sc++;
      break;
    }
    else if(sr==-1){
      sr++;
      break;
    }
  }
  cout<<sr<<" "<<sc<<"\n";
}





void printIncreasing(int n){
  if(n==0){
    return;
  }
  printIncreasing(n-1);
  cout<<n<<" ";
}
void printDecreasing(int n){
  if(n==0){
    return;
  }
  cout<<n<<" ";
  printDecreasing(n-1);
}
int factorial(int n){
  if(n==0){
    return 1;
  }
  int ans= n*factorial(n-1);
  return ans;
}
int fibonacci(int num){
  if(num<=1){
    return num;
  }
  int left= fibonacci(num-1);
  int right= fibonacci(num-2);
  int ans= left+right;
  return ans;
}

void display(vector<int>&arr,int idx){
  // if(idx==arr.size()){
  //   return;
  // }
  if(idx<arr.size()){
    cout<<arr[idx]<<" ";
    display(arr,idx+1);
  }
}
int main(){
  // vector<vector<int>>arr={{0,0,1,0},{1,0,0,1},{1,0,1,0}};
  // exitPoint(arr);
  // printIncreasing(5);
  // printDecreasing(5);
  // cout<<factorial(5)<<"\n";
  // cout<<fibonacci(6)<<"\n";
  vector<int>arr={7,19,27,6,4,9};
  // display(arr,0);
  return 0;
}