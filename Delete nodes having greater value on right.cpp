//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *compute(Node *head)
    {
        // your code goes here
        deque<int> q;
        Node *curr = head;
        while (curr != NULL)
        {
            int ans = curr->data;
            while (q.empty() == false && q.back() < ans)
            {
                q.pop_back();
            }
            q.push_back(curr->data);
            curr = curr->next;
        }
        Node *temp = new Node(q.front());
        head = temp;
        q.pop_front();
        while (q.empty() == false)
        {
            Node *key = new Node(q.front());
            temp->next = key;
            temp = temp->next;
            q.pop_front();
        }
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends