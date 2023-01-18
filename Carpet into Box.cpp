//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int carpetBox(int A, int B, int C, int D)
    {
        // code here
        int sum1 = A + B;
        A = min(A, B);
        B = sum1 - A;
        int sum2 = C + D;
        C = min(C, D);
        D = sum2 - C;

        if (A <= C and B <= D)
            return 0;
        else if (B > D)
            return 1 + carpetBox(A, B / 2, C, D);
        else if (A > C)
            return 1 + carpetBox(A / 2, B, C, D);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        Solution ob;

        int ans = ob.carpetBox(A, B, C, D);

        cout << ans << endl;
    }
}
// } Driver Code Ends