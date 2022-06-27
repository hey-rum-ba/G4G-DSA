// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long bitCount(int N)
    {
        vector<int> ans;
        long long dec = 0;
        while (N)
        {
            if (N % 2 == 0)
                ans.push_back(1);
            else
                ans.push_back(N % 2);
            N /= 2;
        }
        for (int i = 0; i < ans.size(); i++)
        {
            dec += pow(2, (i * ans[i]));
        }

        return dec;
    }
    
    vector<int> changeBits(int N) {
        // code here
        vector<int> ans;
        ans.push_back((bitCount(N) - N));
        ans.push_back(bitCount(N));

        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends