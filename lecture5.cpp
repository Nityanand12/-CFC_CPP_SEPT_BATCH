#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void vec(){
  // vector<int>arr={11,54,76,12,67};
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";
  // arr.push_back(85);
  // arr.push_back(71);
  // arr.push_back(15);
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";

  // sort(arr.begin(),arr.end());
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";

  // arr.pop_back();
  // arr.pop_back();
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";

  // // set
  // arr[3]=21;
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";

  // // insert
  // arr.insert(arr.begin()+2,15);
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";

  // // erase
  // arr.erase(arr.begin()+3);
  // for(int i=0;i<arr.size();i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";



  // vector<int>narr(10,15);
  // for(int i=0;i<narr.size();i++){
  //   cout<<narr[i]<<" ";
  // }
  // cout<<"\n";
  // narr.push_back(20);
  // for(int i=0;i<narr.size();i++){
  //   cout<<narr[i]<<" ";
  // }
  // cout<<"\n";
  
  // for(int ele: narr){
  //   cout<<ele<<" ";
  // }



  // vector<int>narr2;
  // for(int i=1;i<=20;i++){
  //   narr2.push_back(i*10);
  //   cout<<narr2.size()<<" "<<narr2.capacity()<<"\n";
  // }
}

void rotate(vector<int>&arr){
  int low=0,high=arr.size()-1;
  while(low<high){
    int temp= arr[low];
    arr[low]= arr[high];
    arr[high]= temp;
    low++;
    high--;
  }
  for(int ele: arr){
    cout<<ele<<" ";
  }

}

void linearSearch(vector<int>&arr,int val){
  int flag=0;
  for(int i=0;i<arr.size();i++){
    if(val==arr[i]){
      flag=1;
      break;
    }
  }
  if(flag==0){
    cout<<"Element not found"<<"\n";
  }
  else{
    cout<<"Element found"<<"\n";
  }
}
void binarySearch(vector<int>&arr,int val){
  int flag=0,low=0,high= arr.size()-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==val){
      flag=1;
      break;
    }
    else if(arr[mid]>val){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  if(flag==0){
    cout<<"Element not found"<<"\n";
  }
  else{
    cout<<"Element found"<<"\n";
  }
}

int main(){
  // vec();
  
  // int n;
  // cin>>n;
  // vector<int>arr(n,0);
  // for(int i=0;i<n;i++){
  //   cin>>arr[i];
  // }
  // for(int ele: arr){
  //   cout<<ele<<" ";
  // }
  // cout<<"\n";

  vector<int>narr={7,8,1,15,16,6};
  // rotate(narr);
  // linearSearch(narr,9);

  vector<int>narr2={1,12,45,76,79,111,456};
  binarySearch(narr2,112);


  return 0;
}

