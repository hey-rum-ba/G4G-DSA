//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution
{

public:
    map<int, bool> vis;
    // keep visited node to make sure we dont add the same node twice
    int ans = 0;
    // find sum of the subtree with d distance
    int sum(Node *cur, int d)
    {
        if (cur == NULL)
            return 0;
        if (vis[cur->data])
            return 0; // if we already add the node
        vis[cur->data] = true;
        if (d == 0)
            return cur->data;
        int s = cur->data;
        s += sum(cur->left, d - 1) + sum(cur->right, d - 1);
        return s;
    }
    // search
    void search(Node *cur, int t, vector<Node *> v, int k)
    {
        if (cur == NULL)
            return;
        else
        {
            // found then solve
            v.push_back(cur);
            // v keep track of the parent above(path)
            if (cur->data == t)
            {
                int in = 0;
                for (int i = v.size() - 1; i >= 0; i--)
                {
                    Node *n = v[i];
                    ans += sum(n, k - in); // at parent in above you will have k-in distance left to travel
                    in++;
                    if (in == k + 1)
                        break;
                    // cout<<n->data<<endl;
                }
            }
            else
            {
                search(cur->left, t, v, k);
                search(cur->right, t, v, k);
            }
        }
    }
    int ladoos(Node *root, int home, int k)
    {
        // Your code goes here
        vector<Node *> v;
        search(root, home, v, k);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        int home, k;
        cin >> home >> k;
        getchar();
        Solution obj;
        cout << obj.ladoos(root, home, k) << endl;
    }
    return 0;
}

// } Driver Code Ends