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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* after = NULL;
        ListNode* last = NULL;
        ListNode* cur = head;
        while(cur!=NULL){
            after = cur->next;
            cur->next =last;
            last = cur;
            cur = after;
        }
        return last;
    }
};