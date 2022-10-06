//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string s, int k) {
        // code here
        int n = s.size();
        
        if((n&n-1) == 0) k /= 2;
        else k *= 2;
        
        if(k >= n) return "-1";
        
        stack<char> stk;
        string ans = "";
        
        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            while(!stk.empty() && stk.top() > ch && k > 0){
                stk.pop();
                k--;
            }
            
            stk.push(ch);
        }
        
        while(k > 0 && !stk.empty()){
            stk.pop();
            k--;
        }
        
        while(!stk.empty()){
            ans += (char)stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends