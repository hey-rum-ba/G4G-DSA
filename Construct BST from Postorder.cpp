//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* BulidBST(int post[],int start,int end){
   if(start>end)
       return NULL;
   Node* temp=new Node(post[end]);
   int i;
   for(i=end;i>=start;i--){
       if(post[i]<temp->data)
           break;
   }
   temp->right=BulidBST(post,i+1,end-1);
   temp->left=BulidBST(post,start,i);
   return temp;
}
Node *constructTree (int post[], int size)
{
//code here
    // sort(post,post+size);
    return BulidBST(post,0,size-1);
}