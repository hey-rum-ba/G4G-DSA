//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int minSteps(string str)
{
    // Write your code here.
    int a = 0, b = 0, ans = 0;
    if (str[0] == 'a')
        a++;
    else
        b++;
    char last = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] != last)
        {
            if (str[i] == 'a')
                a++;
            else
                b++;
        }
        last = str[i];
    }
    int mini = min(a, b);
    ans += mini + 1;
    return ans;
}

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends