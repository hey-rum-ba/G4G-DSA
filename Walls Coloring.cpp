//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int Ai_1 = colors[0][0], Bi_1 = colors[0][1], Ci_1 = colors[0][2];

        for(int i = 1; i< N; i++){

            int t1 = colors[i][0] + min(Bi_1, Ci_1);

            int t2 = colors[i][1] + min(Ai_1, Ci_1);

            int t3 = colors[i][2] + min(Bi_1, Ai_1);

            Ai_1 = t1, Bi_1 = t2, Ci_1 = t3;

        }

        return min(Ai_1, min(Bi_1, Ci_1));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends