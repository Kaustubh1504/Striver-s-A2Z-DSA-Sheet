//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    // if(head==NULL || head->next==NULL) return 0;
    
    // Node* temp=head;
    
    // int n=0;
    // while(temp!=NULL){
    //     n++;
    //     temp=temp->next;
    // }
    
    // Node* slow=head;
    // Node* fast=head;
    // Node* entry=head;
    // int len=0;
    
    // while(fast->next!=NULL && fast->next->next!=NULL){
    //     slow=slow->next;
    //     fast=fast->next->next;
        
    //     if(slow==fast){
    //         while(slow!=entry){
    //             len++;
    //             slow=slow->next;
    //             entry=entry->next;
    //         }
            
    //         break;
    //     }
    // }
    
    
    // return n-len;
    
    
    
    map<Node*,int> nodeIndex;
    int i=1;
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL){
        nodeIndex.insert({temp,cnt});
        temp=temp->next;
        cnt++;
        
        if(nodeIndex.find(temp)!=nodeIndex.end()){
            return cnt-nodeIndex[temp] ;
        }
        
        
        
    }
    
    
    return 0;
    
    
    
}
