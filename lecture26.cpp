#include<iostream>
using namespace std;

// 543. Diameter of Binary Tree
// class Solution {
// public:
//     int ans=0;
//     int diameterOfBinaryTree2(TreeNode* root){
//         if(root==nullptr){
//             return -1;
//         }
//         int left= diameterOfBinaryTree2(root->left);
//         int right= diameterOfBinaryTree2(root->right);
//         ans=max(ans,left+right+2);
//         return max(left,right)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==nullptr){
//             return 0;
//         }
//         diameterOfBinaryTree2(root);
//         return ans;
//     }
// };

// 145. Binary Tree Postorder Traversal
// class Solution {
// public:
//     void postorderTraversal(TreeNode* root,vector<int>&ans){
//         if(root==nullptr){
//             return;
//         }
//         postorderTraversal(root->left,ans);
//         postorderTraversal(root->right,ans);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//          vector<int>ans;
//         postorderTraversal(root,ans);
//         return ans;
//     }
// };


// 94. Binary Tree Inorder Traversal
// class Solution {
// public:
//     void inorderTraversal(TreeNode* root,vector<int>&ans){
//         if(root==nullptr){
//             return;
//         }
//         inorderTraversal(root->left,ans);
//         ans.push_back(root->val);
//         inorderTraversal(root->right,ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//          vector<int>ans;
//         inorderTraversal(root,ans);
//         return ans;
//     }
// };


// 144. Binary Tree Preorder Traversal
// class Solution {
// public:
//     void preorderTraversal(TreeNode* root,vector<int>&ans){
//         if(root==nullptr){
//             return;
//         }
//         ans.push_back(root->val);
//         preorderTraversal(root->left,ans);
//         preorderTraversal(root->right,ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         preorderTraversal(root,ans);
//         return ans;
//     }
// };


// 111. Minimum Depth of Binary Tree
// class Solution {
// public:
//     int minDepth2(TreeNode* root){
//         if(root==nullptr){
//             return INT_MAX;
//         }
//         if(root->left==nullptr&&root->right==nullptr){
//             return 1;
//         }
//         return min(minDepth2(root->left),minDepth2(root->right))+1;
//     }
//     int minDepth(TreeNode* root) {
//         if(root==nullptr){
//             return 0;
//         }
//         return minDepth2(root);
//     }
// };



// Maximum Depth of Binary Tree
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==nullptr){
//             return 0;
//         }
//         int left= maxDepth(root->left);
//         int right= maxDepth(root->right);
//         return max(left,right)+1;
//     }
// };


// 450. Delete Node in a BST
// class Solution {
// public:
//     int minimum(TreeNode* root){
//         if(root->left==nullptr){
//             return root->val;
//         }
//         return minimum(root->left);
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root==nullptr){
//             return nullptr;
//         }
//         if(root->val==key){
//             if(root->left==nullptr&&root->right==nullptr){
//                 return nullptr;
//             }
//             else if(root->left!=nullptr&&root->right!=nullptr){
//                 int minV= minimum(root->right);
//                 root->val=minV;
//                 root->right=deleteNode(root->right,minV);
//             }
//             else if(root->left!=nullptr){
//                 return root->left;
//             }
//             else{
//                 return root->right;
//             }
//         }
//         else if(root->val<key){
//             root->right=deleteNode(root->right,key);
//         }
//         else{
//             root->left=deleteNode(root->left,key);
//         }
//         return root;
//     }
// };






// 236. Lowest Common Ancestor of a Binary Tree
// class Solution {
// public:
//     vector<TreeNode*> path(TreeNode* root, TreeNode* p){
//         if(root==nullptr){
//             vector<TreeNode*>baseCase;
//             return baseCase;
//         }
//         if(root==p){
//             vector<TreeNode*>baseCase;
//             baseCase.push_back(p);
//             return baseCase;
//         }
//         vector<TreeNode*> left= path(root->left,p);
//         vector<TreeNode*> right= path(root->right,p);
//         if(left.size()!=0){
//             left.push_back(root);
//             return left;
//         }
//         else if(right.size()!=0){
//             right.push_back(root);
//             return right;
//         }
//         else{
//             return left;
//         }
        
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         TreeNode* finalAns= nullptr;
//         vector<TreeNode*>p1= path(root,p);
//         vector<TreeNode*>p2= path(root,q);
//         int id1=p1.size()-1;
//         int id2=p2.size()-1;
//         while(id1>=0&&id2>=0&&p1[id1]==p2[id2]){
//             finalAns= p1[id1];
//             id1--;
//             id2--;
//         }
//         return finalAns;
//     }
// };


// 235. Lowest Common Ancestor of a Binary Search Tree
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         while(root!=nullptr){
//             if(p->val>root->val&&q->val>root->val){
//                 root=root->right;
//             }
//             else if(p->val<root->val&&q->val<root->val){
//                 root=root->left;
//             }
//             else{
//                 break;
//             }
//         }
//         return root;
//     }
// };



// 669. Trim a Binary Search Tree
// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if(root==nullptr){
//             return nullptr;
//         }
//         if(root->val<low){
//             return trimBST(root->right,low,high);
//         }
//         else if(root->val>high){
//             return trimBST(root->left,low,high);
//         }
//         else{
//             root->left=trimBST(root->left,low,high);
//             root->right=trimBST(root->right,low,high);
//         }
//         return root;
//     }
// };



class binaryTree{
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
  Node *insert(Node *node,int value,string dirs,int idx){
    if(node==nullptr){
      Node *base= new Node(value);
      return base;
    }
    if(idx==dirs.length()){
      node->val=value;
      return node;
    }
    if(dirs[idx]=='R'){
      node->right=insert(node->right,value,dirs,idx+1);
    }
    else{
      node->left=insert(node->left,value,dirs,idx+1);
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
  public:
  void insert(int value,string dirs){
    this->root=insert(root,value,dirs,0);
  }
  public:
  void display(){
    display(root);
  }
};
int main(){
  binaryTree bt1;
  bt1.insert(10,"");
  bt1.insert(15,"R");
  bt1.insert(25,"L");
  bt1.insert(18,"LR");
  bt1.insert(51,"R");
  bt1.insert(16,"LL");
  bt1.insert(21,"RL");
  bt1.display();
  return 0;
}