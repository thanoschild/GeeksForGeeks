//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            String S = read.readLine();

            Solution ob = new Solution();
            System.out.println(ob.longestSubstring(S, N));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    static String longestSubstring(String s, int n) {
        // code here
        int window = 1;
        StringBuilder str = new StringBuilder();
        String ans = "";
        
        for(int i = 0; i<s.length(); i++) {
            while(str.length() != window) str.append(s.charAt(i));
            
            if(s.indexOf(str.toString(), i+1) != -1) {
                window++;
                ans = str.toString();
            }
            else {
                str.deleteCharAt(0);
            }
        }
        
        return ans.length() == 0 ? "-1" : ans;
    }
};