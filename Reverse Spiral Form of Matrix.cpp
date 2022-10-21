//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>>&a)  {
        // code here
        int rs=0, cs=0, re=r-1, ce=c-1;
        vector<int> ans;
        
        while(rs<=re && cs<=ce){
            
            for(int j=cs;j<=ce;j++){
                ans.push_back(a[rs][j]);
            }rs++;
            
            for(int i=rs;i<=re;i++){
                ans.push_back(a[i][ce]);
            }ce--;
            
            if(rs<=re){
                for(int j=ce;j>=cs;j--){
                    ans.push_back(a[re][j]);
                }re--;
            }
            
            if(cs<=ce){
                for(int i=re;i>=rs;i--){
                    ans.push_back(a[i][cs]);
                }cs++;
            }
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
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends