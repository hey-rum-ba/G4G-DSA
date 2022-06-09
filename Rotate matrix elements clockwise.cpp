// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // code here
        int l=0,r=N-1,b=M-1,t=0;
        while(l<r && t<b){
           int x=Mat[t+1][l];
           for(int i=l;i<=r;i++)swap(x,Mat[t][i]);
           t++;
           for(int i=t;i<=b;i++)swap(x,Mat[i][r]);
           r--;
           for(int i=r;i>=l;i--)swap(x,Mat[b][i]);
           b--;
           for(int i=b;i>=t;i--)swap(x,Mat[i][l]);
           l++;
       }
       return Mat;
       
       
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends