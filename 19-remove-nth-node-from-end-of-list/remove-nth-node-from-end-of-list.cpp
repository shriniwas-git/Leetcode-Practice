class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        
        ListNode* deli = slow->next;
        slow->next = slow->next->next;
        // free(deli);
        delete deli;
        return head;
    }
};