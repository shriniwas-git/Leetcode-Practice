/**
 * Definition for singly-nexted list.
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int ct=0;
        while(cur!=NULL){
            cur = cur->next;
            ct++;
        }
        int pt = ct/k;
        int rem = ct%k;
        vector<int> size(k,0);
        for(int i=0;i<k;i++){
            size[i] = pt;
        }
        int i=0;
        while(rem!=0){
            size[i++] +=1;
            rem--;
        }
        vector<ListNode*> ans(k);
        cur = head;
        ListNode* prev=NULL;
        for(int i=0;i<k;i++){
            ListNode* temp= new ListNode();
            ListNode* ent = temp;
            int fl=0;
            while(cur!=NULL && size[i]!=0){
                fl=1;
                temp->next=new ListNode(cur->val);
                cur = cur->next;
                temp=temp->next;
                size[i]--;
            }
            ans[i] = ent->next;
        }
        return ans;

        
    }
};