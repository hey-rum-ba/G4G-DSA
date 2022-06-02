// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n<m)
            return kthElement(arr2,arr1,m,n,k);
        int low=0,high=n-1;   
        
        while(low<=high)
        {
            int mid = (low+high)/2;
           
            if(mid>k)
            {
                high=mid-1;
                continue;
            }
            if(mid+m<k)
            {
                low=mid+1;
                continue;
            }
            
            int l1 = (mid==0)?INT_MIN:arr1[mid-1];
            int l2 = (k-mid==0||k-mid>m)?INT_MIN:arr2[k-mid-1];
            
            int r1 = (mid==n)? INT_MAX : arr1[mid];
            int r2 = (k-mid==m)? INT_MAX : arr2[k-mid];
            
            if(l1<=r2&&l2<=r1)
            return max(l2,l1);
            if(l1>r2)
                high=mid-1;
            else
                low=mid+1;
        }
        return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends