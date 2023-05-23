//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the
// new binary tree formed
class Solution
{
public:
    Node *solve(int pre[], int preMirror[], int l1, int r1, int l2, int r2)
    {
        if (l1 > r1 or l2 > r2)
            return NULL;

        Node *root = new Node(pre[l1]);

        int nr1 = INT_MAX;

        if (l2 + 1 <= r2)
        {
            for (int j = l1; j <= r1; j++)
            {
                if (pre[j] == preMirror[l2 + 1])
                {
                    nr1 = j;
                    break;
                }
            }
        }

        int nr2 = INT_MAX;

        if (l1 + 1 <= r1)
        {
            for (int j = l2; j <= r2; j++)
            {
                if (preMirror[j] == pre[l1 + 1])
                {
                    nr2 = j;
                    break;
                }
            }
        }

        if (nr1 != INT_MAX && nr2 != INT_MAX)
        {
            root->left = solve(pre, preMirror, l1 + 1, nr1 - 1, nr2, r2);
            root->right = solve(pre, preMirror, nr1, r1, l2 + 1, nr2 - 1);
        }

        return root;
    }
    Node *constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        return solve(pre, preMirror, 0, size - 1, 0, size - 1);
    }
};

//{ Driver Code Starts.

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int preOrder[n];
        int preOrderMirror[n];
        for (int i = 0; i < n; i++)
            cin >> preOrder[i];
        for (int i = 0; i < n; i++)
            cin >> preOrderMirror[i];
        Solution obj;
        printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends