#include<iostream>
#include<math.h>
using namespace std;
void pattern7(int n)
{
  int id = 1, nsp = n - 1, nst = 1;
  while (id <= 2 * n - 1){
    int csp = 1;
    while (csp <= nsp){
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst){
      cout << cst;
      cst++;
    }
    cout << "\n";
    if (id < n){
      nst = nst + 2;
      nsp--;
    }
    else
    {
      nst = nst - 2;
      nsp++;
    }
    id++;
  }
}

void pattern8(int n)
{
  int id = 1, nsp = n - 1, nst = 1;
  while (id <= 2 * n - 1){
    int csp = 1;
    while (csp <= nsp){
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst){
      if(cst<=(nst+1)/2){
        cout << cst;
      }
      else{
        cout<<nst-cst+1;
      }
      cst++;
    }
    cout << "\n";
    if (id < n){
      nst = nst + 2;
      nsp--;
    }
    else
    {
      nst = nst - 2;
      nsp++;
    }
    id++;
  }
}
int base10tobase2(int num){
  int ans=0,cnt=0;
  while(num!=0){
    int rem= num%2;
    ans= ans+pow(10,cnt)*rem;
    cnt++;
    num=num/2;
  }
  return ans;
}
int base2tobase10(int num){
  int ans=0,cnt=0;
  while(num!=0){
    int rem= num%10;
    ans= ans+pow(2,cnt)*rem;
    cnt++;
    num=num/10;
  }
  return ans;
}
void array(){
  int arr[]= {12,5,2,5,76,87};
  // int len= sizeof(arr)/sizeof(arr[0]);
  // for(int i=0;i<len;i++){
  //   cout<<arr[i]<<" ";
  // }
  // for(int ele: arr){
  //   cout<<ele<<" ";
  // }

  // int n=5;
  // int arr1[n];
  // for(int i=0;i<n;i++){
  //   cin>>arr1[i];
  // }
  // for(int ele: arr1){
  //   cout<<ele<<" ";
  // }
  
}
int main(){
  // pattern7(5);
  // pattern8(5);
  // int ans1=base10tobase2(98);
  // cout<<ans1<<"\n";
  // int ans2=base2tobase10(ans1);
  // cout<<ans2<<"\n";

  array();
  return 0;
}