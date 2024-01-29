//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String str = br.readLine().trim();
            Solution ob = new Solution();
            int ans = ob.TotalCount(str);
            System.out.println(ans);           
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public int solve(int idx, String s, Integer[][] dp, int sum) {
        if(idx >= s.length()) return 1;
        if(dp[idx][sum] != null) return dp[idx][sum];
        
        int currSum = 0;
        dp[idx][sum] = 0;
        
        for(int i = idx; i<s.length(); i++) {
            currSum += (s.charAt(i) - '0');
            if(sum <= currSum) dp[idx][sum] += solve(i+1, s, dp, currSum);
        }
        
        return dp[idx][sum];
    }
    
    public int TotalCount(String str) {
        Integer[][] dp = new Integer[str.length()][902];
        return solve(0, str, dp, 0);
    }
}