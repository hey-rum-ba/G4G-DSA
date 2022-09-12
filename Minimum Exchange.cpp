//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int MinimumExchange(vector<vector<char>>matrix){
    // Code here
    int n=matrix.size();
   int m=matrix[0].size();
   int c1=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if((i%2==0 && ((j%2==0 && matrix[i][j]!='A')||(j%2!=0 && matrix[i][j]!='B')))||(i%2!=0 &&((j%2==0 && matrix[i][j]!='B')||(j%2!=0 && matrix[i][j]!='A'))))
           c1++;
       }
   }
   if(((n*m)-c1)%2==1)
   return c1/2;
   return min(c1/2,((n*m)-c1)/2);
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MinimumExchange(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends