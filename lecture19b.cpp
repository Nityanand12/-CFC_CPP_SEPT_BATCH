#include<iostream>
using namespace std;


// 876. Middle of the Linked List
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode *slow=head,*fast=head;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
// };





//206. Reverse Linked List
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *prev=nullptr,*curr=head,*forw=head;
//         while(forw!=nullptr){
//             forw=curr->next;
//             curr->next=prev;
//             prev= curr;
//             curr=forw;
//         }
//         return prev;
//     }
// };




class Node{
  public:
  int val;
  Node *next;
  Node(int val){
    this->val=val;
    this->next=nullptr;
  }
};
class customLinkedList{
  public:
  int size;
  Node *head,*tail;
  customLinkedList(){
    size=0;
    head=nullptr;
    tail=nullptr;
  }
  void addLast(int data){
    Node *node = new Node(data);
    if(size==0){
      head=node;
      tail=node;
      size++;
      return;
    }
    tail->next=node;
    tail=node;
    size++;
  }
  void addFirst(int data){
    if(size==0){
      addLast(data);
      return;
    }
    Node *node = new Node(data);
    node->next=head;
    head=node;
    size++;
  }
  void display(){
    Node *w=head;
    while(w!=nullptr){
      cout<<w->val<<" ";
      w=w->next;
    }
    cout<<"\n";
  }

  void removeLast(){
    if(size==0){
      cout<<"Linkedlist is empty "<<"\n";
      return;
    }
    if(size==1){
      head=nullptr;
      tail=nullptr;
      size--;
      return;
    }
    Node *w=head;
    while(w->next!=tail){
      w=w->next;
    }
    w->next=nullptr;
    tail=w;
    size--;
  }
  void removeFirst(){
    if(size<=1){
      removeLast();
      return;
    }
    size--;
    head=head->next;
  }
};
int main(){
  customLinkedList *cl1= new customLinkedList();
  cl1->addLast(10);
  cl1->addLast(8);
  cl1->addLast(12);
  cl1->addFirst(20);
  cl1->addFirst(2);
  cl1->addLast(81);
  cl1->addLast(121);
  cl1->addFirst(-43);
  cl1->addFirst(67);
  cout<<"Size is "<<cl1->size<<"\n";
  cl1->removeFirst();
  cout<<"Size is "<<cl1->size<<"\n";
  cl1->removeLast();
  cl1->removeFirst();
  cout<<"Size is "<<cl1->size<<"\n";
  cl1->display();
  return 0;
}