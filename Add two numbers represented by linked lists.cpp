// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
        struct Node *reverse(struct Node *head) {
           struct Node *curr, *tmp = head->next, *res;
           res = head;
           res->next = NULL;
           while(tmp) {
               curr = tmp;
               tmp = tmp->next;
               curr->next = res;
               res = curr;
           }
           return res;
        }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
           // code here
           int sum, carry, digit1, digit2;
           struct Node *res = NULL, *last = NULL;
    
           first = reverse(first);
           second = reverse(second);
           
           carry = 0;
           while(first != NULL || second != NULL) {
               digit1 = (first != NULL) ? first->data : 0;
               digit2 = (second != NULL) ? second->data : 0;
               sum = carry + digit1 + digit2;
               if(last == NULL) {
                   res = new Node(sum % 10);
                   last = res;
               }
               else {
                   last->next = new Node(sum % 10);
                   last = last->next;
               }
               carry = sum / 10;
               if(first != NULL) first = first->next;
               if(second != NULL) second = second->next;
           }
           if(carry > 0) {
               last->next = new Node(carry);
           }
           res = reverse(res);
           
           return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends