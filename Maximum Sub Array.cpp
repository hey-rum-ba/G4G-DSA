//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> v;
	    int prefixSum=0,maxSum=0;
	    for(int end=0,start=0;end<n;end++){
	        if(a[end] >=0){
	            prefixSum+=a[end];
	            if(prefixSum == maxSum){
	                // two cases length equal and not equal 
	                if(end-start == v[1]-v[0]){
	                    if(start < v[0]){
	                        v[0] = start;
	                        v[1] = end;
	                    }
	                }else{
	                    if(end-start > v[1]-v[0]){
	                         v[0] = start;
	                        v[1] = end;
	                    }
	                }
	                maxSum=prefixSum;
	            }else if(prefixSum > maxSum){
                    v={start,end};
	                maxSum=prefixSum;
	            }
	        }else{
	            prefixSum =0;
	            start=end+1;
	        }
	    }
	    
	    vector<int> ans;
	    if(v.empty()){
	        ans.push_back(-1);
	    }else{
	        for(int i = v[0];i<=v[1];i++){
	            ans.push_back(a[i]);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends