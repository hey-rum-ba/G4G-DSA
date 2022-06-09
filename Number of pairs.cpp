// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
       //Your code here
       int c = count(Y, Y+N, 3);
       long long s = (M-count(X, X+M, 1))*count(Y, Y+N, 1); 
       sort(Y, Y+N);
       	for(int i = 0; i<M; i++){
            if(X[i] == 1) continue;
            if(X[i] == 2) X[i] = 4;
            if(X[i] == 3) X[i] = 1, s -= c;
            s += N-(upper_bound(Y, Y+N, X[i])-Y);
        }
        return s; 
        
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends