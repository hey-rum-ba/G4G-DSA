//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        int count = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
    
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
    
        while (!pq.empty()) {
            if (pq.top() >= k)
                return count;
    
            int firstMin = 0, secondMin = 0;
            if (pq.size() == 1) {
                if (pq.top() < k)
                    return -1;
                else
                    return count;
            }
    
            firstMin = pq.top();
            pq.pop();
            secondMin = pq.top();
            pq.pop();
            pq.push(firstMin + secondMin);
            count++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends