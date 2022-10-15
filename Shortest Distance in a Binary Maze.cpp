//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
         if(source==destination)return 0;

        if(grid[destination.first][destination.second]==0||grid[source.first][source.second]==0)return -1;

        int c=0;int t1=1,t2,x,y;

        queue<pair<int,int>> q;

        int n=grid.size(),m=grid[0].size();

        q.push(source);

        grid[source.first][source.second]=2;

        while(q.empty()==0)

        {

            ++c;

            t2=0;

            while(t1)

            {

                x=q.front().first;y=q.front().second;

                q.pop();

                if(y-1>=0&&grid[x][y-1]==1){q.push({x,y-1});grid[x][y-1]=2;++t2;if(q.back()==destination)return c;}

                if(x-1>=0&&grid[x-1][y]==1){q.push({x-1,y});grid[x-1][y]=2;++t2;if(q.back()==destination)return c;}

                if(x+1<n&&grid[x+1][y]==1){q.push({x+1,y});grid[x+1][y]=2;++t2;if(q.back()==destination)return c;}

                if(y+1<m&&grid[x][y+1]==1){q.push({x,y+1});grid[x][y+1]=2;++t2;if(q.back()==destination)return c;}

                --t1;

            }

            t1=t2;

            

        }

        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends