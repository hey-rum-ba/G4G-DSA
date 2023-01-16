//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<int> s;
        vector<long long> nge(n,-1);
        s.push(0);
        for(int i=0 ; i<n ; i++)
        {
                while ( !s.empty() && arr[s.top()] < arr[i] ){
                    nge[s.top()]=arr[i]; s.pop();
                }
            s.push(i);
        }

        return nge;
    }

//     vector<long long> nextLargerElement(vector<long long> &arr, int n)
//     {
//         // Your code here
//         vector<long long> ans(n, 0);
//         stack<long long> stk;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             while (stk.size() > 0 && stk.top() <= arr[i])
//             {
//                     stk.pop();
//             }
//             if (stk.size() == 0)
//             {
//                     ans[i] = -1;
//             }
//             else
//             {
//                     ans[i] = stk.top();
//             }
//             stk.push(arr[i]);
//         }
//         return ans;
//     }
// };
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends