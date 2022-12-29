//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids)
    {
        // code here
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0)
                st.push(asteroids[i]);
            else
            {
                bool flag = false;
                while (!st.empty())
                {
                    if (st.top() < 0)
                    {
                        st.push(asteroids[i]);
                        break;
                    }
                    else if (st.top() < -1 * asteroids[i])
                        st.pop();
                    else
                        break;
                }

                if (!st.empty() && st.top() == -1 * asteroids[i])
                    st.pop();

                if (st.empty())
                    st.push(asteroids[i]);
            }
        }
        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++)
            cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends