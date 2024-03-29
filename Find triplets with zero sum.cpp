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
/*
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        //Your code here
        int cnt=0;
        sort(arr, arr+n);
        for(int i=0;i<n-2;i++){
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

             if (sum == 0) {

                left++;
                right--;
                cnt=1;
                break;
             }else if(sum<0){
                 left++;
             }else{
                 right--;
             }
            }
        }
        if(cnt==1){
            return 1;
        }else{
            return 0;
        }
    }
};
*/

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