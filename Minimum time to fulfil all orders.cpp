//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class cmp{
   public:
   bool operator()(pair<int,vector<int>>&a,pair<int,vector<int>>&b){
        return a.first>b.first;
   }
};
class Solution{
    public:
    typedef pair<int,vector<int>> type;
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
    
       priority_queue<type,vector<type>,cmp> mini;
       int final=0;
       
       for(int i=0;i<L;i++){
       
           mini.push({A[i],{A[i],A[i],i}});
       }
       
       unordered_map<int,int> store;
       
       for(int i=0;i<N;i++){
           
           int finaltime=mini.top().first;
           int factor=mini.top().second[0];
           int timetaken=mini.top().second[1];
           int index=mini.top().second[2];
           

            store[mini.top().second[2]]+=timetaken;
           mini.pop();
           
          
           
           timetaken+=factor;
           finaltime+=timetaken;
           
           mini.push({finaltime,{factor,timetaken,index}});
       }
       
       for(auto i:store){
           final=max(final,i.second);
       }
       
       return final;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends