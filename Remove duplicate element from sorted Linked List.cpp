// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
  /*
  Node *removeDuplicates(Node *head)
  {
   // your code goes here
      Node *prevNode = nullptr, *currNode = head;

      while(currNode) {
          if(prevNode && prevNode->data == currNode->data) {
              prevNode->next = currNode->next;
              currNode = prevNode->next;
              continue;
          }

          prevNode = currNode;
          currNode = currNode->next;
      }

      return head;
  }
  */
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
   Node* p = head;
        while( p != NULL ){
             Node* q = p->next;
            while( q != NULL ){
                if( q->data != p->data ){
                    break;
                }
                q = q->next;
            }
            p->next = q;
            p = q;
        }
        return head;
}