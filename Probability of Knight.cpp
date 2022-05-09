// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	bool isSafe(int x, int y, int n) {
        if(x >= 0 && x < n && y >= 0 && y < n) return true;
        else return false;
    }
    
	double solve(int i , int j, int n, int k, vector<vector<vector<double>>> &dp) {
	    pair<int,int> dir[] = {{-2,-1}, {-2,1}, {-1,-2}, {1, -2}, {2,-1}, {2,1}, {1,2}, {-1,2}};
	    
	    if(k == 0){
            return 1;
        }
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        double ans = 0;
        
        for(int d = 0; d < 8; d++) {
            int p = i + dir[d].first;
            int q = j + dir[d].second;
            
            if(isSafe(p,q,n)) {
                ans += (solve(p,q,n,k-1,dp)/8);
            }
        }
        
        dp[i][j][k] = (double)ans;
        
        return (double)dp[i][j][k];
	}
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // Code here
	   vector<vector<vector<double>>> 
	   dp(N, vector<vector<double>>(N, vector<double>(steps+1, -1)));
	   
	   return solve(start_x, start_y, N, steps, dp);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends