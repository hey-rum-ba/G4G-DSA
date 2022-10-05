//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    char a='a';
    class Trie{
        public:
        vector<Trie*>trie;
        int count;
        bool isTerm;
        char a='a';
        Trie(){
            trie.resize(26);
            count=0;
            isTerm=false;
        }
    };
    
    void add(string s,Trie* cur){
            for(auto i:s){
                if(cur->trie[i-a]){
                    cur->trie[i-a]->count++;
                    cur=cur->trie[i-a];
                }
                else{
                    cur->trie[i-a]=new Trie;
                    cur->trie[i-a]->count++;
                    cur=cur->trie[i-a];
                }
            }
            cur->isTerm=true;
        }
        
    int find(string s,Trie* cur){
        for(auto i:s){
            if(cur->trie[i-a])
            cur=cur->trie[i-a];
            else return 0;
        }
        return cur->count;
    }

    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        auto trie=new Trie;
        for(auto i=0;i<N;i++)
            add(li[i],trie);
        vector<int>ans;
        
        for(int i=0;i<Q;i++){
            ans.push_back(find(query[i],trie));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends