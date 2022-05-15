// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int>> res;
    void solve(vector<int> &A,vector<int> &v,int idx){
        res.push_back(v);
        if(idx==A.size()) return;
        for(int i=idx;i<A.size();i++){
            if(i!=idx and A[i]==A[i-1]) continue;
            v.push_back(A[i]);
            solve(A,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int> > AllSubsets(vector<int> A, int n) {
        vector<int> v;
        sort(begin(A),end(A));
        solve(A,v,0);
        sort(begin(res),end(res));
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends