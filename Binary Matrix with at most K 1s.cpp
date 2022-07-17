//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        // code here
        for(int i=1; i<R; i++) M[i][0]+=M[i-1][0];
        for(int i=1; i<C; i++)  M[0][i]+=M[0][i-1];

        for(int i=1; i<R; i++){
            for(int j=1; j<C; j++){
                M[i][j] = M[i-1][j]+M[i][j-1] - M[i-1][j-1] + M[i][j];
            }
        }
       
        vector<int> ans(Q,0);
        for(int k=0; k<Q; k++){
            int i = q_i[k];
            int j = q_j[k];
            int l=0;
            while(l+i<R && l+j<C && i-l>=0 && j-l>=0){
                int a=0,b=0,c=0;
                if(j-l-1>=0) a=M[i+l][j-l-1];
                if(i-l-1>=0) b=M[i-l-1][j+l];
                if(j-l-1>=0 && i-l-1>=0) c=M[i-l-1][j-l-1];
               
                int res = M[i + l][j + l] - a - b + c;
                if(res>K) break;
                else ans[k] = 2*l+1;
                l++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends