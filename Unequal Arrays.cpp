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
    long long solve(int N, vector<int> &A, vector<int> &B)
    {
        // code here
        long long sum_a = 0, sum_b = 0;
        vector<int> odd_a, odd_b, even_a, even_b;
        for (int i = 0; i < N; i++)
        {
            sum_a += A[i];
            sum_b += B[i];
            if (abs(A[i]) % 2 == 0)
                even_a.push_back(A[i]);
            else
                odd_a.push_back(A[i]);
            if (abs(B[i]) % 2 == 0)
                even_b.push_back(B[i]);
            else
                odd_b.push_back(B[i]);
        }

        // Check if the sums are equal and odd elements of A and B are of the same size
        if (sum_a != sum_b || odd_a.size() != odd_b.size())
            return -1;

        // Sort even and odd elements of A and B separately
        sort(odd_a.begin(), odd_a.end());
        sort(odd_b.begin(), odd_b.end());
        sort(even_a.begin(), even_a.end());
        sort(even_b.begin(), even_b.end());

        // Calculate the minimum number of operations needed to make A and B equal
        long long ans = 0;
        for (int i = 0; i < odd_a.size(); i++)
        {
            if (abs(odd_a[i] - odd_b[i]) % 2 == 0)
                ans += abs(odd_a[i] - odd_b[i]) / 2;
        }
        for (int i = 0; i < even_a.size(); i++)
        {
            if (abs(even_a[i] - even_b[i]) % 2 == 0)
                ans += abs(even_a[i] - even_b[i]) / 2;
        }

        return ans / 2;
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

        vector<int> A(N);
        Array::input(A, N);

        vector<int> B(N);
        Array::input(B, N);

        Solution obj;
        long long res = obj.solve(N, A, B);

        cout << res << endl;
    }
}

// } Driver Code Ends