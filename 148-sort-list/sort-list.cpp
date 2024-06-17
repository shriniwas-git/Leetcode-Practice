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
    ListNode* sortList(ListNode* head) {
        vector<int> a;
        ListNode* cur = head;
        while(cur!=NULL){
            int data = cur->val;
            a.push_back(data);
            cur = cur->next;
        }
        sort(a.begin(),a.end());
        cur = head;
        int i=0;
        while(cur!=NULL){
            cur->val = a[i++];
            cur = cur->next;
        }
        return head;
    }
};