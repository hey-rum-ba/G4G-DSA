//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        if(K > S.length()) return 0;

        unordered_map<char,int> mp;
        int ans = 0;
    
        int i = 0; 
        for(i;i<K;i++) {
            mp[S[i]]++;
        }
    
        if(mp.size() == K-1) ans++;
    
        for(i; i < S.length(); i++) {
            mp[S[i]]++;
            mp[S[i-K]]--;
            auto it = mp.find(S[i-K]);
            if(it->second == 0) mp.erase(it);
            if(mp.size() == K-1) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends