// 101. Symmetric Tree
// class Solution {
// public:
//     bool isSymmetric(TreeNode* p,TreeNode* q){
//         if(p==nullptr&&q==nullptr){
//             return true;
//         }
//         if(p==nullptr||q==nullptr){
//             return false;
//         }
//         if(p->val!=q->val){
//             return false;
//         }
//         bool res=true;
//         res=res&&isSymmetric(p->left,q->right);
//         res=res&&isSymmetric(p->right,q->left);
//         return res;
//     }
//     bool isSymmetric(TreeNode* root) {
//        return isSymmetric(root,root);
//     }
// };


// 100. Same Tree
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==nullptr&&q==nullptr){
//             return true;
//         }
//         if(p==nullptr||q==nullptr){
//             return false;
//         }
//         if(p->val!=q->val){
//             return false;
//         }
//         bool res=true;
//         res=res&&isSameTree(p->left,q->left);
//         res=res&&isSameTree(p->right,q->right);
//         return res;
//     }
// };