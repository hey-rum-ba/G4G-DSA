// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    int sumOfOtherTwo(int sum,int arr[], int i, int n){
       for(int y = i+1;y<n-1;y++){
           for(int k=y+1;k<n;k++){
               if((sum + arr[y]+ arr[k])==0){
                   return 0;
               }
           }
       }
       return -1;
        
    }
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
         for(int i=0;i<n-2;i++){
           if(sumOfOtherTwo(arr[i],arr,i,n)==0){
               return true;
           }
       }
       return false;

    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends