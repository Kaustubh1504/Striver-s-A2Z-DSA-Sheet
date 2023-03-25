//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node* head) {
        Node* temp=head;
        Node* prev=NULL;
        Node* nex = NULL;        
        while(temp!=NULL){
            nex=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }

        return prev;
        
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head->next==NULL){
            head->data=head->data+1;
            return head;
        }
        Node* temp=head;
        int len=0;
    
        Node* rev = reverseList(head);
        
        temp=rev;
        int cy=0;
        temp->data=temp->data+1;
        while(temp!=NULL){
            if(temp->next==NULL) temp->data=temp->data+cy;
            else {
                int data= temp->data;
                if(data+cy>9) {
                    temp->data=0;
                    cy=1;
                }else{
                    temp->data=temp->data+cy;
                    cy=0;
                }
                
            }
            
            temp=temp->next;
        }
        
        head=reverseList(rev);
        
        return head;
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
