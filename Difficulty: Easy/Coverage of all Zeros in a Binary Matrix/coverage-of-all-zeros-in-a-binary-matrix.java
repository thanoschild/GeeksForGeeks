//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int[][] matrix = new int[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution ob = new Solution();
            int ans = ob.findCoverage(matrix);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    int[] dir = {-1, 0, 1, 0, -1};
    private int getCoverage(int i, int j, int n, int m, int[][] mat) {
        int count = 0;
        for(int k = 0; k<4; k++) {
            int x = i + dir[k];
            int y = j + dir[k+1];
            if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1) {
                count++;
            }
        }
        return count;
    }
    
    public int findCoverage(int[][] matrix) {
        // code here
        int n = matrix.length;
        int m = matrix[0].length;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    ans += getCoverage(i, j, n, m, matrix);
                }
            }
        }
        
        return ans;
    }
}