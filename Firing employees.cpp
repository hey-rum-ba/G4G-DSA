//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
vector<bool> isPrime(100000, 1);

class Solution{   
public:
    void seive() {
        int n = 100000;
        
        isPrime[0] = 0;
        isPrime[1] = 0;
        
        for(int i = 2; i*i <= n; i++) {
            for(int j = i*i; j <= n; j += i){
                isPrime[j] = 0;
            }
        }
    }
    
    int firingEmployees(vector<int> &arr, int n){
        // code here
        seive();
        unordered_map<int,vector<int>> m;
        int src = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) src = i+1;
            
            m[arr[i]].push_back(i+1);
        }
        
        queue<pair<int,int>> q;
        int ans = 0;
        
        q.push({src,0});
        
        while(!q.empty()) {
            int cur = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(level != 0) {
                if(isPrime[cur+level])
                    ans++;
            }
            
            for(int x : m[cur]){
                q.push({x,level+1});
            }
        }
        
        return ans; 
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends