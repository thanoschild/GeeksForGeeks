//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String input_line[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int[][] a = new int[n][n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            String ans = ob.pattern(a);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
     public boolean isPalindrome(String str, int n){
        int i=0;           //Used two pointer approach.
        int j=n-1;
        while(i<=j){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    public String pattern(int[][] arr) {
        // Code here
        int n = arr.length;
        
        // for checking Row first
        for(int i=0;i<n;i++){
            String str = "";
            for(int j=0; j<n; j++){
                str += arr[i][j];
            }
            if(isPalindrome(str, n)){
                return Integer.toString(i) + " R";
            }
        }

        //for checking Column
        for(int i=0;i<n;i++){
            String str = "";
            for(int j=0; j<n; j++){
                str += arr[j][i];
            }
            if(isPalindrome(str, n)){
                return Integer.toString(i) + " C";
            }
        }
        return Integer.toString(-1);
    }
}
