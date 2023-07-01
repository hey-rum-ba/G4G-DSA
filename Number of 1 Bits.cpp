//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        int c = 0, ctr = 32, i = 1;
        while (ctr != 1)
        {
            int x = N & i;
            if (x == i)
                c++;
            i = i << 1;
            ctr--;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends