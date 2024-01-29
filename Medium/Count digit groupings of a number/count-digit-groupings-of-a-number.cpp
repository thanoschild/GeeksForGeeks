//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int idx, string s, vector<vector<int>> &dp, int sum) {
	    if(idx >= s.size()) return 1;
	    if(dp[idx][sum] != -1) return dp[idx][sum];
	    
	    int currSum = 0;
	    dp[idx][sum] = 0;
	    
	    for(int i = idx; i<s.size(); i++) {
	        currSum += (s[i] - '0');
	        if(currSum >= sum) dp[idx][sum]  += solve(i+1, s, dp, currSum);
	    }
	    
	    return dp[idx][sum];
	}
	
	int TotalCount(string str) {
	    int n = str.size();
	    vector<vector<int>> dp(n, vector<int>(902, -1));
	    return solve(0, str, dp, 0);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends