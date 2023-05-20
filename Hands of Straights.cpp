//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand)
    {
        // code here
        if (groupSize == 1)
        {
            return true;
        }

        if (N % groupSize != 0)
        {
            return false;
        }

        sort(hand.begin(), hand.end());

        int current = hand[0];
        hand.erase(hand.begin() + 0);
        int g = 1;
        int i = 0;
        while ((!hand.empty()) && i < N)
        {
            if (current + 1 == hand[i] && g < groupSize)
            {
                current = hand[i];
                hand.erase(hand.begin() + i);
                g++;
                if (g == groupSize && (!hand.empty()))
                {
                    i = 0;
                    current = hand[i];
                    hand.erase(hand.begin() + i);
                    g = 1;
                }
            }
            else
            {
                i++;
            }
        }
        if (hand.size() == 0)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++)
            cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends