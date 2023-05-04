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
    void insert(ListNode** root, int item)
    {
        ListNode* temp = new ListNode();
        temp->val = item;
        temp->next = *root;
        *root = temp;
    }
    ListNode *arrayToList(vector<int>arr, int n)
    {
        ListNode *root = NULL;
        for (int i = n-1; i >= 0 ; i--)
            insert(&root, arr[i]);
        return root;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> sorted;
        for(auto list: lists){
            ListNode* temp=list;
            while(temp!=NULL){
                sorted.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(sorted.begin(),sorted.end());

        ListNode* head=arrayToList(sorted,sorted.size());

        return head;
    }
};
