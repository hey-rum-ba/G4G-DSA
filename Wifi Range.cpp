//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool wifiRange(int N, string S, int X)
    {
        // code here
        for (int i = 0; i < N; i++)
        {
            if (S[i] == '1')
            {
                int k = 1;
                while (i - k >= 0 && k <= X)
                {
                    if (S[i - k] == '0')
                        S[i - k] = '2';
                    k++;
                }
                k = 1;
                while (i + k < N && k <= X)
                {
                    if (S[i + k] == '0')
                        S[i + k] = '2';
                    k++;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (S[i] == '0')
            {
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends