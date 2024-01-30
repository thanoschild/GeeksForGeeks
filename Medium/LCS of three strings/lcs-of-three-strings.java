//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException 
    { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0){
            String input_line[] = read.readLine().trim().split("\\s+");
            int n1 = Integer.parseInt(input_line[0]);
            int n2 = Integer.parseInt(input_line[1]);
            int n3 = Integer.parseInt(input_line[2]);
            input_line = read.readLine().trim().split("\\s+");
            String A = input_line[0];
            String B = input_line[1];
            String C = input_line[2];
            Solution obj = new Solution();
            System.out.println(obj.LCSof3(A, B, C, n1, n2, n3));
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java
class Solution 
{   
    int lcs(String s1, String s2, String s3, int i, int j, int k, Integer[][][] dp) {
        if(i == 0 || j == 0 || k == 0) return 0;
        if(dp[i][j][k] != null) return dp[i][j][k];
        
        if(s1.charAt(i-1) == s2.charAt(j - 1) && s2.charAt(j-1) == s3.charAt(k-1)) {
            dp[i][j][k] = 1 + lcs(s1, s2, s3, i-1, j-1, k-1, dp);
            return dp[i][j][k];
        }
        
        int p = lcs(s1, s2, s3, i-1, j, k, dp);
        int q = lcs(s1, s2, s3, i, j-1, k, dp);
        int r = lcs(s1, s2, s3, i, j, k-1, dp);
        
        dp[i][j][k] = Math.max(p, Math.max(q, r));
        return dp[i][j][k];
    }
    
    int LCSof3(String A, String B, String C, int n1, int n2, int n3) { 
        // code here
        Integer[][][] dp = new Integer[22][22][22];
        return lcs(A, B, C, n1, n2, n3, dp);
    }
}