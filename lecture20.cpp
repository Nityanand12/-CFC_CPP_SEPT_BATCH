// 21. Merge Two Sorted Lists
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1==nullptr){
//             return l2;
//         }
//         if(l2==nullptr){
//             return l1;
//         }
//         ListNode *ans= new ListNode(-1);
//         ListNode *temp= ans;
//         while(l1!=nullptr&&l2!=nullptr){
//             if(l1->val<=l2->val){
//                 temp->next=l1;
//                 l1=l1->next;
//             }
//             else{
//                 temp->next=l2;
//                 l2=l2->next;
//             }
//             temp= temp->next;
//         }
//         if(l1!=nullptr){
//             temp->next=l1;
//         }
//         if(l2!=nullptr){
//             temp->next=l2;
//         }
//         return ans->next;
//     }
// };



// 234. Palindrome Linked List
// class Solution {
// public:
//     ListNode* middle(ListNode* head){
//         ListNode *slow= head,*fast=head;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
//     ListNode* reverse(ListNode* head){
//         ListNode *prev= nullptr,*curr=head,*forw=head;
//         while(forw!=nullptr){
//             forw=curr->next;
//             curr->next= prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//         ListNode* mid= middle(head);
//         ListNode* head2= reverse(mid);
//         while(head!=nullptr&&head2!=nullptr){
//             if(head->val!=head2->val){
//                 return false;
//             }
//             head=head->next;
//             head2=head2->next;
//         }
//         return true;
//     }
    
// };



//142. Linked List Cycle II
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *slow=head,*fast=head;
//         ListNode *temp=nullptr;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             fast=fast->next->next;
//             slow=slow->next;
//             if(fast==slow){
//                 temp=slow;
//                 break;
//             }
//         }
//         if(temp==nullptr){
//             return nullptr;
//         }
//         while(head!=temp){
//             head=head->next;
//             temp=temp->next;
//         }
//         return temp;
//     }
// };











//141. Linked List Cycle
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode *slow=head,*fast=head;
//         while(fast!=nullptr&&fast->next!=nullptr){
//             fast=fast->next->next;
//             slow=slow->next;
//             if(fast==slow) return true;
//         }
//         return false;
//     }
// };



// Intersections of 2 linkedlist
// class Solution {
// public:
//     int length(ListNode *head){
//         int size=0;
//         while(head!=nullptr){
//             head=head->next;
//             size++;
//         }
//         return size;
//     }
//     ListNode *sizeManaze(ListNode *head,int len){
//         while(len!=0){
//             head=head->next;
//             len--;
//         }
//         return head;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int la= length(headA);
//         int lb= length(headB);
//         if(la>lb){
//             headA= sizeManaze(headA,la-lb);
//         }
//         if(la<lb){
//             headB= sizeManaze(headB,lb-la);
//         }
//         while(headA!=headB){
//             headA=headA->next;
//             headB=headB->next;
//         }
//         return headA;
//     }
// };