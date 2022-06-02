// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int arr1[], int arr2[], int n) {
            // code here 
            if (n == 1) return arr1[0] + arr2[0];
            if (n == 2) return max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]);
            int i = (n-1)/2;
            int j = n-i-2;
            int d = max(1, i/2);
            while (true){
                if (arr1[i] <= arr2[j+1] && arr2[j] <= arr1[i+1])
                    break; 
                else if (arr1[i] > arr2[j+1]){
                    i -= d;
                    j += d;
                } else {
                    i += d;
                    j -= d;
                }
                d = max(d/2, 1);
            }
            return max(arr1[i], arr2[j]) + min(arr1[i+1], arr2[j+1]);
            }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends