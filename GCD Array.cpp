//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    int solve(int N, int K, vector<int> &arr)
    {
        // code here
        int preSum[N];
        preSum[0] = arr[0];
        for (int i = 1; i < N; i++)
            preSum[i] = arr[i] + preSum[i - 1];

        vector<int> factors;
        int sum = preSum[N - 1];

        for (int i = 1; i <= sqrt(sum); i++)
        {
            if (sum % i == 0)
            {
                factors.push_back(i);
                if (i != sum / i)
                    factors.push_back(sum / i);
            }
        }
        int maxi = INT_MIN;
        for (auto i : factors)
        {
            int c = 0;

            for (int j = 0; j < N; j++)
            {
                if (preSum[j] % i == 0)
                    c++;
            }

            if (c >= K)
            {
                maxi = max(maxi, i);
                c = 0;
            }
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        vector<int> arr(N);
        Array::input(arr, N);

        Solution obj;
        int res = obj.solve(N, K, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends