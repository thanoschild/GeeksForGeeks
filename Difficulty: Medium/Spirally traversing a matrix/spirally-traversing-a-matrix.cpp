//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &a) {
        int n = a.size(), m = a[0].size();
        int start_row = 0, end_row = n - 1, start_column = 0, end_column = m - 1;
        vector<int> ans; 

        while (start_row <= end_row && start_column <= end_column) {
            for (int col = start_column; col <= end_column; col++) {
                ans.push_back(a[start_row][col]);
                
            }
            start_row++;
            if(start_row>end_row) break;
     
            for (int row = start_row; row <= end_row; row++) {
                ans.push_back(a[row][end_column]);
            }
            end_column--;
            if(end_column<start_column) break;
    
            for (int col = end_column; col >= start_column; col--) {
                ans.push_back(a[end_row][col]);
            }
            end_row--;
            if(end_row<start_row) break;
    
            for (int row = end_row; row >= start_row; row--) {
                ans.push_back(a[row][start_column]);
            }
            start_column++;
            if(start_column>end_column) break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends