//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool isPrime(int n){
        if(n == 1 || n == 2 || n == 3)return true;
        
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0)return false;
        }
        
        return true;
    }
    string isSumOfTwo(int N){
        // code here
        for(int i = 1; i <= N/2; i++){
            if(isPrime(i) && isPrime(N-i))return "Yes";
        }
        
        return "No";

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends