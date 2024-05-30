//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(string &s1, string &s2, int i, int j, int n, int m) {
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]) ans = solve(s1, s2, i+1, j+1, n, m) % mod;
        ans = (ans + solve(s1, s2, i+1, j, n, m)) % mod;
        return dp[i][j] = ans;
    }
    
    int countWays(string s1, string s2) {
        // code here
        int n = s1.size(), m = s2.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, 0, 0, n, m);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends