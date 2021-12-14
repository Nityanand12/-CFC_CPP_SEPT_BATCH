#include<vector>
#include<iostream>
#include<string>
using namespace std;
vector<string> mazePathWithReturnType(int sr,int sc,int er,int ec){
  if(sr==er&&sc==ec){
    vector<string>base;
    base.push_back("");
    return base;
  }
  vector<string>ans;
  if(sc+1<=ec){
    vector<string>east=mazePathWithReturnType(sr,sc+1,er,ec);
    for(int i=0;i<east.size();i++){
      ans.push_back("H"+east[i]);
    }
  }
  if(sr+1<=er){
    vector<string>south=mazePathWithReturnType(sr+1,sc,er,ec);
    for(int i=0;i<south.size();i++){
      ans.push_back("V"+south[i]);
    }
  }
  return ans;
}
void mazePath(){
  mazePathWithReturnType(0,0,2,2);
}

void permutationWithRepetition(vector<int>&arr,int target,int sum,string ans){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }
  for(int i=0;i<arr.size();i++){
    if(sum+arr[i]<=target){
      permutationWithRepetition(arr,target,sum+arr[i],ans+to_string(arr[i])+" ");
    }
  }
}
int combinationWithRepetition(vector<int>&arr,int target,int sum,string ans,int id){
  if(sum==target){
    cout<<ans<<"\n";
    return 1;
  }
  int count=0;
  for(int i=id;i<arr.size();i++){
    if(sum+arr[i]<=target){
      count=count+combinationWithRepetition(arr,target,sum+arr[i],ans+to_string(arr[i])+" ",i);
    }
  }
  return count;
}

int combinationWithoutRepetition(vector<int>&arr,int target,int sum,string ans,int id){
  if(sum==target){
    cout<<ans<<"\n";
    return 1;
  }
  int count=0;
  for(int i=id;i<arr.size();i++){
    if(sum+arr[i]<=target){
      count=count+combinationWithoutRepetition(arr,target,sum+arr[i],ans+to_string(arr[i])+" ",i+1);
    }
  }
  return count;
}

int permutationWithoutRepetition(vector<int>&arr,int target,int sum,string ans,vector<int>&vis){
  if(sum==target){
    cout<<ans<<"\n";
    return 1;
  }
  int count=0;
  for(int i=0;i<arr.size();i++){
    if(arr[i]+sum<=target&&vis[i]==0){
      vis[i]=1;
      count+=permutationWithoutRepetition(arr,target,sum+arr[i],ans+to_string(arr[i])+
      " ",vis);
      vis[i]=0;
    }
  }
}
void fourImpQuestions(){
  vector<int>arr={1,2,3,4};
  int target=4;
  // permutationWithRepetition(arr,target,0,"");
  // cout<<"Total combination with repetition is "<<combinationWithRepetition(arr,target,0,"",0)<<"\n";
  // cout<<"Total combination without repetition is "<<combinationWithoutRepetition(arr,target,0,"",0)<<"\n";

  // vector<int>vis(arr.size(),0);
  //  cout<<"Total permutation without repetition is "<<permutationWithoutRepetition(arr,target,0,"",vis)<<"\n";
}

int main(){
  // mazePath();
  fourImpQuestions();
  return 0;
}