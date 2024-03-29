//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
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

/*The function below returns an int denoting
the length of the longest palindrome list. */
int count(Node* left, Node* right){
    if(left==NULL || right==NULL) return 0;
    
    int res=0;
    while(left!=NULL && right!=NULL){
        
        if(left->data==right->data){
            res++;
            left=left->next;    right=right->next;
        }else{ break;}
        
    }
    
    return res;
}

int maxPalindrome(Node *head)
{
    //Your code here
    if(head==NULL) return 0;
    int maxLen=1;
    Node* prev=NULL,*cur=head,*next=NULL;
    
    while(cur){
        next=cur->next;
        cur->next=prev;
        
        //exclude cur
        int count1=2*count(prev,next)+1;
        int count2=2*count(cur,next);
        
        maxLen=max(maxLen,max(count1,count2));
        
        prev=cur;
        cur=next;
    }
    
    return maxLen;
}