//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int final_count=0;
	    for(int i=1;i<nums.size()-1;i++)
	    {
	        int j = i-1,flag=0,count_small=0,k=i+1,count_big=0; 
	        int val = nums[i];
	        while(j>=0)
	        {
	            if(nums[j]<val)
	            {
                         count_small++;
	            }
	            j--;
	        }
	        while(k<nums.size())
	        {
	            if(nums[k]>val)
	            {
	                count_big++;
	            }
	            k++;
	        }
	        final_count+=(count_small*count_big);
	    }
	    return final_count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends