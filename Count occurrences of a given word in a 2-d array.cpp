//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    int n, m;
    
    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};
    
    bool isValid(int i, int j) {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    void dfs(int i, int j, string target, vector<vector<char> > &mat, int &count) {
        if(!isValid(i, j)||mat[i][j]!=target[0]) {return;}
        if(target.size()==1&&mat[i][j]==target[0]) {count++; return;}
        char temp=mat[i][j];
        mat[i][j]='*';
        for(int k=0; k<4; k++) {
            int x=i+dx[k], y=j+dy[k];
            dfs(x, y, target.substr(1), mat, count);
        }
        mat[i][j]=temp;
    }
    
    public:
    int findOccurrence(vector<vector<char> > &mat, string &target){
        n=mat.size(), m=mat[0].size();
        int count=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==target[0]) {
                    dfs(i, j, target, mat, count);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends