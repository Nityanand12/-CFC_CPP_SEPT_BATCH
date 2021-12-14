// 102. Binary Tree Level Order Traversal
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         queue<TreeNode*>que;
//         vector<vector<int>>ans;
//         if(root==nullptr){
//             return ans;
//         }
//         que.push(root);
//         int d=1;
//         while(que.size()!=0){
//             ans.push_back(vector<int>());
//             int count=0;
//             for(int i=1;i<=d;i++){
//                 TreeNode* remove= que.front();
//                 que.pop();
//                 ans[ans.size()-1].push_back(remove->val);
//                 if(remove->left!=nullptr){
//                     count++;
//                     que.push(remove->left);
//                 }
//                 if(remove->right!=nullptr){
//                     count++;
//                     que.push(remove->right);
//                 }
//             }
//             d=count;
//         }
//         return ans;
//     }
// };



#include<iostream>
using namespace std;

class binarySearchTree{
  public:
  class Node{
    public:
    int val;
    Node *left,*right;
    Node(int val){
      this->val=val;
      left=nullptr;
      right=nullptr;
    }
  };
  private:
  Node *root=nullptr;
  Node *insert(Node *node,int value){
    if(node==nullptr){
      Node *base= new Node(value);
      return base;
    }
    if(node->val<=value){
      node->right= insert(node->right,value);
    }
    else{
      node->left= insert(node->left,value);
    }
    return node;
  }
  void display(Node *node){
    if(node==nullptr){
      return;
    }
    if(node->left!=nullptr){
      cout<<node->left->val<<" -> ";
    }
    else{
      cout<<" -> ";
    }
    cout<<node->val<<" ";
    if(node->right!=nullptr){
      cout<<" <- "<<node->right->val;
    }
    else{
      cout<<" <- ";
    }
    cout<<"\n";
    display(node->left);
    display(node->right);
  }
  bool find(Node *node,int value){
    if(node==nullptr){
      return false;
    }
    if(node->val==value){
      return true;
    }
    if(node->val>value){
      return find(node->left,value);
    }
    else{
      return find(node->right,value);
    }
  }
  public:
  void insert(int value){
    this->root=insert(root,value);
  }
  void display(){
    display(root);
  }
  bool find(int value){
    return find(root,value);
  }
};

int main(){
  binarySearchTree bst1;
  // bst1.insert(15);
  // bst1.insert(27);
  // bst1.insert(22);
  // bst1.insert(10);
  // bst1.insert(3);
  // bst1.insert(14);
  // bst1.insert(12);
  // bst1.insert(20);
  // bst1.insert(21);
  // bst1.display();
  // cout<<bst1.find(28)<<"\n";
  for(int i=1;i<=10;i++){
    bst1.insert(i);
  }
  bst1.display();
  return 0;
}