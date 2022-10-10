//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool isValid(int i, int j, vector<vector<int>>&v, int m, int n)
  {
      if(i < 0 || j < 0 || i >= n || j>= m || v[i][j] == 0)return false;
      return true;
  }
  void DFS(int i, int j, int m, int n, vector<vector<int>>& v)
  {
      v[i][j] = 0;
      if(isValid(i + 1, j, v, m, n))DFS(i + 1, j, m, n, v);
      if(isValid(i, j + 1, v, m, n))DFS(i, j + 1, m, n, v);
      if(isValid(i - 1, j, v, m, n))DFS(i - 1, j, m, n, v);
      if(isValid(i, j - 1, v, m, n))DFS(i, j - 1, m, n, v);
      return;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int>ans;
        vector<vector<int>>v(n, vector<int>(m, 0));
        for(auto q : operators)
        {
            int x = q[0], y = q[1], cnt = 0;
            v[x][y] = 1;
            auto copy = v;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(copy[i][j] == 1)
                    {
                        cnt++;
                        DFS(i, j, m, n, copy);
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends