#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&arr){
  for(int i=0;i<arr.size();i++){
    bool swap=false;
    for(int j=0;j<arr.size()-i-1;j++){
      if(arr[j]>arr[j+1]){
        swap=true;
        int t= arr[j];
        arr[j]= arr[j+1];
        arr[j+1]=t;
      }
    }
    if(swap==false){
      break;
    }
  }
  for(int ele: arr){
    cout<<ele<<" ";
  }
}
void selectionSort(vector<int>&arr){
  for(int i=0;i<arr.size()-1;i++){
    int id=i;
    for(int j=i+1;j<arr.size();j++){
      if(arr[j]<arr[id]){
        id=j;
      }
    }
    if(id!=i){
      int t= arr[id];
      arr[id]=arr[i];
      arr[i]=t;
    }
  }
  for(int ele: arr){
    cout<<ele<<" ";
  }
}
int main(){
  vector<int>arr={4,1,15,2,7,8,3};
  // bubbleSort(arr);
  // selectionSort(arr);
  return 0;
}