/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
 }

 ListNode* merge(ListNode* left,ListNode* right){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(left!=NULL && right!=NULL){
        if(left->val<=right->val){
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left!=NULL){
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }
    return dummy->next;
 }
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};