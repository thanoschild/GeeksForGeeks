//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int dp[22][22][22];
        int lcs(string &s1, string &s2, string &s3, int i, int j, int k) {
            if(i == 0 || j == 0 || k == 0) return 0;
            if(dp[i][j][k]  != -1) return dp[i][j][k];
            
            if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                dp[i][j][k] = 1 + lcs(s1, s2, s3, i - 1, j - 1, k - 1);
                return dp[i][j][k];
            }
            else {
                int p = lcs(s1, s2, s3, i - 1, j, k);
                int q = lcs(s1, s2, s3, i, j - 1, k);
                int r = lcs(s1, s2, s3, i, j, k - 1);
                dp[i][j][k] = max({p, q, r});
            }
            
            return dp[i][j][k];
        }
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
            // your code here
            memset(dp, -1, sizeof(dp));
            return lcs(A, B, C, n1, n2, n3);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends