// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	    priority_queue< pair<long double , pair<long long,long long>> > pq;
	    
	    for(int i=0; i<N; i++){
	        long double ratio= (double)p[i]/w[i];
	        pq.push({ratio , {p[i] , w[i]} }); 
	    }
	    
	    long double TotalProfit =0;
	    
	    while(!pq.empty() && C>0){
	        long long profit=pq.top().second.first;
	        long long weight=pq.top().second.second;
	        
	        long double ratio=pq.top().first;
	        pq.pop();
	        
	        long long x=sqrt(weight);
	        if(x*x==weight)
	         continue;
	        
	        if( C > weight){
	            TotalProfit +=  double(profit);
	            C  -= weight;
	        }else{
	            TotalProfit +=  double(ratio*C);
	            C -=C;
	        }
	    }
	    return TotalProfit;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends