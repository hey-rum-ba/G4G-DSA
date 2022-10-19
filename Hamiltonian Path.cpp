//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int node, int N, vector<vector<int>>& adj, unordered_set<int> &st){
        st.insert(node);
        if(st.size() == N) return true;
        for(int child : adj[node]){
            if(st.find(child) == st.end() && dfs(child, N, adj, st)){
                    return true;
            }
        }
        st.erase(node);
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>> adj(N + 1);
        for(vector<int> &e : Edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> st;
        for(int i = 1; i <= N; i++){
            if(dfs(i, N, adj, st)){
                return true;
            }
        }      
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends