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
        // ListNode * slow=head;
        // ListNode * fast=head;
        // while(fast!=NULL && fast->next!=NULL){
        //     fast=(fast->next)->next;
        //     slow=slow->next;
        // }
        // return slow;

        // ListNode* temp=head;
        // int len=0;
        // while(temp!=NULL){
        //     len++;
        //     temp=temp->next;
        // }

        // if(len==1) return head;

        // temp=head;
        // int i=0;
        // while(temp!=NULL){
        //     i++;
        //     temp=temp->next;
        //     if(i==len/2) return temp;
        // }

        // return temp;



        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=(fast->next)->next;
            slow=slow->next;
        }

        return slow;
        
    }
};
