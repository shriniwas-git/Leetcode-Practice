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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;

        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        // deleting head node
        if(len == n){
            return head->next;
        }

        int ct = 1;
        ListNode* cur = head;
        ListNode* prev = NULL;

        while(cur != NULL){

            if(ct == len - n + 1){
                prev->next = cur->next;
                break;
            }

            prev = cur;
            cur = cur->next;
            ct++;
        }

        return head;
    }
};