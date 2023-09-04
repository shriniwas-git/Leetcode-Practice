/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
        fast = fast!=NULL?fast->next:NULL;
        while(slow!=NULL && fast!=NULL){
            if(slow==fast){
                return true;
            }
            slow = slow->next;
        fast = fast->next;
        fast = fast!=NULL?fast->next:NULL;
        
        }
        return false;
    }
};