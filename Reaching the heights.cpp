// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    vector<int> temp; 
   
    if(n==2 && a[0]==a[1]) return {-1};
    else 
    {
        for (int i=0; i<n; i++) 
            temp.push_back(a[i]); 
        sort(temp.begin(),temp.end());
        int j=0,k=0;
        while(j!=n/2 && k!=n/2){
            for(int i=0;i<n;i+=2){
                a[i]=temp[n-j-1];
                j++;
            }
        for(int i=1;i<n;i+=2){
            a[i]=temp[k];
            k++;
        }
    }
    vector<int> ans;

    for (int i=0; i<n; i++) 
        ans.push_back(a[i]); 
   
    return ans;
    }
}
