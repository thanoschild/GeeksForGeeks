//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    int solve(string s1, string s2, int i, int j) {
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s1[i] != s2[j]) {
            dp[i][j] = min({solve(s1, s2, i+1, j) + 1, solve(s1, s2, i, j+1) + 1, solve(s1, s2, i+1, j+1) + 1});
        }
        else dp[i][j] = solve(s1, s2, i+1, j+1);
        
        return dp[i][j];
    }
    
    int editDistance(string str1, string str2) {
        // Code here
        memset(dp, -1, sizeof(dp));
        return solve(str1, str2, 0, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends