//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    
    int solve(int n, int w, vector<int> &wt, vector<int> &val) {
        if(w <= 0) return 0;
        if(n <= 0) return 0;
        if(dp[n][w] != -1) return dp[n][w];
        
        if(w < wt[n-1]) dp[n][w] = solve(n-1, w, wt, val);
        else {
            dp[n][w] = max(solve(n-1, w, wt, val), solve(n-1, w-wt[n-1], wt, val) + val[n-1]);
        }
        
        return dp[n][w];
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        memset(dp, -1, sizeof(dp));
        int n = val.size();
        return solve(n, W, wt, val);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends