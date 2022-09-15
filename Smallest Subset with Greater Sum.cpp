//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(), Arr.end());
        long long sum =0;
        for(int i =0;i<N;i++){
            sum += Arr[i];
        }
        long long sumBack = 0,cnt = 0;
        for(int i = N-1;i>=0;i--){
            sumBack += Arr[i];
            sum -= Arr[i];
            cnt++;
            if(sumBack > sum){
                return cnt;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends