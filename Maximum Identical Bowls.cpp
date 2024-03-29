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
    int getMaximum(int N, vector<int> &arr)
    {
        // code here
        if (N == 1)
            return 1;
        long long sum = 0;
        for (auto elem : arr)
            sum += elem;
        while (N != 0 && sum % N-- != 0)
            ;
        return N + 1;
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

        vector<int> arr(N);
        Array::input(arr, N);

        Solution obj;
        int res = obj.getMaximum(N, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends