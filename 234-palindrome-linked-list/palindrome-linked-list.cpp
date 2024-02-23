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
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast->next!=NULL&& fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseList(slow->next);
        slow->next = rev;
        slow = slow->next;
        ListNode* dummy = head;
        while(slow){
            if(dummy->val!=slow->val){
                return false;
                
            }else{
                slow = slow->next;
                dummy = dummy->next;
            }
        }
        return true;


    }
};