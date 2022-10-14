//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        multiset<int, greater<int>> ms;
        for(int i = 0; i < n; i++) ms.insert(a[i]);
        
        int sum = 0;
        
        while(ms.size() > 0){
            int mx = *ms.begin();
         
            //remove mx
            ms.erase(ms.find(mx));
            
            
            //remove mx-1
            auto it = ms.find(mx-1);
            if(it != ms.end())
                ms.erase(it);
                
            sum += mx;
        }
        
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends