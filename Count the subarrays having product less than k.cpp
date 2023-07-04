//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int s = 0;//start 
        int m = s;//moving ahead
        long sum = 1;//sum to check
        int count = 0;//answer
        while(s<n && m<n){
            sum*=a[m];
            if(sum<k){
                count++;
            }
            if(sum>=k || m == (n-1)){
                sum = 1;
                s++;
                m = s-1;
            }
            m++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends