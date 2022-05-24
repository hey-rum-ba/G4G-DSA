// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       if (n == 0) 
        return 0;

    vector<int> tail(n, 0);
    int length = 1; 

    tail[0] = a[0];

    for (int i = 1; i < n; i++) {

        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, a[i]);

        if (it == tail.begin() + length)
            tail[length++] = a[i];
        else
            *it = a[i];
    }

    return length;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends