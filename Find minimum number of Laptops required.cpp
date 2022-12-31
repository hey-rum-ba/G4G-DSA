//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minLaptops(int N, int start[], int end[])
    {
        // Code here
        sort(start, start + N);
        sort(end, end + N);
        int total = 1;
        for (int i = 1, j = 0; i < N && j < N; i++)
        {
            if (end[j] - start[i] > 0)
                total += 1;
            else
                j++;
        }
        return total;
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
        int start[N], end[N];
        for (int i = 0; i < N; i++)
            cin >> start[i];
        for (int i = 0; i < N; i++)
            cin >> end[i];

        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends