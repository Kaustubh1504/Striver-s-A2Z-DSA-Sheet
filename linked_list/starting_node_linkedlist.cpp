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
    ListNode *detectCycle(ListNode *head) {
        // ListNode* slow=head;
        // ListNode* fast=head;

        // while(fast->next!=NULL && fast->next->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;

        //     if(fast==slow) return fast->next;
        // }

        // return NULL;

        // map<ListNode*,int> valIndex;

        // ListNode* temp=head;
        // int i=0;

        // while(temp!=NULL){
        //     if(valIndex.find(temp)!=valIndex.end()){
        //         return temp;
        //     }
        //     // valIndex.insert({temp->val,temp->next});
        //     valIndex.insert({temp,i});
        //     temp=temp->next;
        //     i++;
        // }

        // // for(auto itr: valIndex) cout<<itr.first<<":"<<itr.second<<endl;



        // return NULL;

        if(head==NULL || head->next==NULL) return NULL;

        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* entry=head;


        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow){
                while(slow != entry) {              
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }   


        return NULL;     
    }
};
