//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dp[101][10000];
    void solve(int ind, int sum, vector<int> &nums, set<int> &ans){
        if(ind >= nums.size()){
            ans.insert(sum);
            return;
        }
        
        if(dp[ind][sum] == true) return;
        
        solve(ind+1,sum,nums,ans);
        solve(ind+1,sum+nums[ind],nums,ans);
        
        dp[ind][sum] = true;
    }

	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    set<int> ans;
        memset(dp,false,sizeof(dp));
        solve(0,0,nums,ans);
        vector<int> final_ans(ans.begin(),ans.end());
        
        return final_ans;
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
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends