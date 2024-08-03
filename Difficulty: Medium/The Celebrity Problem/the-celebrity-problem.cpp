//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int row = mat.size();
        int celebrity = -1;
        for(int i = 0; i<row; i++) {
            int sum = 0;
            for(int j = 0;j<row;j++) {
                sum += mat[i][j];
            }
            if(sum == 0) {
                celebrity = i; break;
            }
        }
        if(celebrity == -1) return -1;
        for(int i = 0;i<row;i++) {
            if(celebrity == i) continue;
            if(mat[i][celebrity] != 1) return -1;
        }
        
        return celebrity;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends