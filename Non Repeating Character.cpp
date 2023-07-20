//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        // Your code here
        vector<int> freq(26, 0);
        int n = S.length();
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            freq[S[right] - 'a']++;
            while (left < n && freq[S[left] - 'a'] > 1)
            {
                left++;
            }
        }
        if (left == n)
        {
            return '$';
        }
        return S[left];
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends