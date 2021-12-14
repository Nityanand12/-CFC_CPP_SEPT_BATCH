#include<iostream>
using namespace std;
class customQueue{
  public:
  int defaultSize=10,size,front,rear;
  int *arr;
  customQueue(){
    arr= new int[defaultSize];
    size=0;
    rear=-1;
    front=0;
  }
  int *resize(){
    int *newArr= new int[defaultSize*2];
    for(int i=0;i<defaultSize;i++){
      newArr[i]= arr[front];
      front=(front+1)%defaultSize;
    }
    rear=defaultSize-1;
    front=0;
    defaultSize*=2;
    return newArr;
  }
  void push(int val){
    if(size==defaultSize){
      arr=resize();
    }
    rear=(rear+1)%defaultSize;
    size++;
    arr[rear]=val;
  }
  bool isEmpty(){
    if(size==0) return true;
    return false;
  }
  void pop(){
    if(isEmpty()){
      cout<<"Queue is empty";
      return;
    }
    front=(front+1)%defaultSize;
    size--;
  }
  int Front(){
    if(isEmpty()){
      cout<<"Queue is empty";
      return EXIT_FAILURE;
    }
    return arr[front];
  }
};
int main(){
  customQueue cq;
  cq.push(10);
  cq.push(12);
  cq.push(1);
  cq.push(9);
  cq.pop();
  cq.push(11);
  cq.pop();
  cq.pop();
  cq.push(7);
  cq.push(45);
  cq.push(12);
  cq.push(45);
  cq.push(12);
  for(int i=1;i<=10;i++){
    cq.push(i);
  }
  while(cq.size!=0){
    cout<<cq.Front()<<" ";
    cq.pop();
  }
  return 0;
}