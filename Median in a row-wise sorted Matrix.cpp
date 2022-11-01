//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int cntsmall(vector<int>mat,int mid,int C){
        int start = 0,end = C;
        while(start<end){
            int m = start+(end-start)/2;
            if(mat[m]<=mid){
                start = m+1;
            }
            else{
                end = m;
            }
        }
        return start;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here      
        int start = INT_MAX,end = INT_MIN;
        for(int i = 0; i<R; i++){
            start = min(start,matrix[i][0]);
            end = max(end,matrix[i][C-1]);
        }
        int req = (R*C+1)/2;
        while(start<end){
            int mid = start+(end-start)/2,smaller = 0;
            for(int i = 0; i<R; i++){
                smaller+=cntsmall(matrix[i],mid,C);
            }
            if(smaller<req){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return start;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends