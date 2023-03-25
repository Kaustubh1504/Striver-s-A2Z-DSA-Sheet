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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<prev->val<<" "<<slow->val<<" "<<fast->next;

        // prev->next=slow->next;
        // slow->next=slow->next->next;
        if(fast->next==NULL){
            prev->next=slow->next;
        }else{
            slow->next=slow->next->next;
        }
        


        return head;
    }
};
