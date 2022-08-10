//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    bool isValid(bool graph[101][101], int n,vector<int> &color,int in,int c)
    {
        int i;
        
        for(i=0;i<n;i++)
        {
            if(i!=in && graph[in][i]==1 && color[i]==c)
            return 0;
        }
        
        return 1;
    }
    
    bool dfs(bool graph[101][101], int m, int n,vector<int> &color,int in)
    {
        if(in==n || color[in]!=-1)
        return 1;
        
        int i,j;
        
        for(i=0;i<m;i++)
        {
            color[in]=i;
            
            if(isValid(graph,n,color,in,i) && dfs(graph,m,n,color,in+1))
            return 1;
            
            color[in]=-1;
        }
        
        return 0;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n,-1);
        return dfs(graph,m,n,color,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends