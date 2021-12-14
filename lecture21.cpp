#include<iostream>
#include<stack>
#include<string>
using namespace std;
template<typename T>

class customStack{
  public:
  T *arr;
  int defaultSize=10;
  int peek;
  customStack(){
    arr= new T[defaultSize];
    peek=-1;
  }
  T *resize(){
    // defaultSize*=2;
    defaultSize=defaultSize*2;
    T *newArr= new T[defaultSize];
    for(int i=0;i<=peek;i++){
      newArr[i]= arr[i];
    }
    return newArr;
  }
  void push(T data){
    if(peek+1==defaultSize){
      arr= resize();
    }
    peek++;
    arr[peek]=data;
  }
  void pop(){
    if(peek==-1){
      cout<<"Empty Stack"<<"\n";
      return;
    }
    peek--;
  }
  T top(){
    if(peek==-1){
      cout<<"Empty Stack"<<"\n";
      return EXIT_FAILURE;
    }
    return arr[peek];
  }
  int size(){
    return peek+1;
  }
};
int main(){
  customStack<char> cs1;
  cs1.push('1');
  cs1.push('2');
  cs1.push('3');
  cs1.push('4');

  cout<<cs1.top()<<"\n";

  // stack<int> st;
  // st.push(12);
  // st.push(18);
  // st.push(22);
  // st.push(1);
  // st.push(17);
  // st.push(97);
  // cout<<"Currently size of stack is "<<st.size()<<"\n";
  // cout<<"Currently top of the stack is "<<st.top()<<"\n";
  // while(st.size()!=0){
  //   cout<<st.top()<<" ";
  //   st.pop();
  // }
  return 0;
}