//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str = read.readLine().trim();
            String ans = ob.compareFrac(str);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {

    String compareFrac(String str) {
        // Code here
        String[] input=str.split(",");
        
        String fraction[]=input[0].split("/");
        
        String fraction2[]=input[1].split("/");
        
        int numerator1=Integer.parseInt(fraction[0]);
        int denominator1=Integer.parseInt(fraction[1]);
        
        int numerator2=Integer.parseInt(fraction2[0].trim());
        int denominator2=Integer.parseInt(fraction2[1]);
       
        
        float first=(float)numerator1/denominator1;
        float second=(float)numerator2/denominator2;
        
        
        if(first>second)
        return input[0];
        else if(first<second)
        return input[1].trim();
        return "equal";
    }
}
