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
    ListNode* middleNode(ListNode* head) {
        int ct = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            ct++;
            cur = cur->next;
        }
        int mid = ct/2;
        ListNode* ans = head;
        while(mid--){
            ans = ans->next;
        }
        return ans;
    }
};