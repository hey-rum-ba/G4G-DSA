//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestPerfectPiece(int arr[], int N)
    {
        // code here
        map<int, int> m;

        int low = 0;

        int high = 0;

        int ans = 0;

        for (high = 0; high < N; high++)

        {

            m[arr[high]]++;

            while ((--m.end())->first - m.begin()->first > 1)

            {

                m[arr[low]]--;

                if (m[arr[low]] == 0)
                    ;

                {

                    m.erase(arr[low]);
                }

                low++;
            }

            ans = max(ans, high - low + 1);
        }

        return ans;
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends