//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int travel(string &str, vector<vector<int>> &dp, int i, int j){
        if(i >= j ){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(str[i] == str[j]){
            return dp[i][j] = travel(str, dp, i + 1, j - 1);
        }
        else{
            return dp[i][j] = 1 + min(travel(str, dp, i + 1, j), travel(str, dp, i, j - 1));
        }
    }
    
    int countMin(string str){
        //complete the function here
        int i = 0;
        int n = str.length();
        int j = n - 1;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return travel(str, dp, i, j);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends