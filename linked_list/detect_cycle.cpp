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
        // int l=0,r=0;
        // bool isPresent=false;
        // ListNode* left=head;
        
        // while(left!=NULL){
        //     r=l+1;
        //     ListNode* right=left->next;
            
        //     while(right!=NULL){
                
        //         if(right->next==left){
        //             if(r!=l) isPresent = true;
        //         }
        //         r++;
        //     }
            
        //     left=left->next;
        //     l++;
        // }
        // return isPresent;

        ListNode* fast=head;
        ListNode* slow=head;

        if(head==NULL || head->next==NULL) return false;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast) return true;
        }

        return false;








    }
};
