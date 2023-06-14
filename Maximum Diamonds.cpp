//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long maxDiamonds(int A[], int N, int K)
    {
        // code here
        priority_queue<int> q(A, A + N);
        long long int count = 0;
        for (int i = K; i > 0; i--)
        {
            int y = q.top();
            count += y;
            q.pop();
            q.push(y / 2);
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;

        cin >> N >> K;
        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxDiamonds(A, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends