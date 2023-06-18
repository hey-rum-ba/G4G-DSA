//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int distributeTicket(int N, int K)
    {
        // code here
        int i = 1;
        int j = N;
        while (true)
        {
            if (i + K <= j)
                i += K;
            else
                return j;
            if (j - K >= i)
                j -= K;
            else
                return i;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        Solution obj;
        int res = obj.distributeTicket(N, K);

        cout << res << endl;
    }
}

// } Driver Code Ends