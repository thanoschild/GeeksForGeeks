//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine().trim());
        while(t-- > 0){
            
            int n; 
            n = Integer.parseInt(br.readLine().trim());
            
            
            int[] price = IntArray.input(br, n);
            
            Solution obj = new Solution();
            int res = obj.maxProfit(n, price);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int maxProfit(int n, int[] price) {
        // code here
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        int least = price[0];
        for(int i = 1; i<n; i++) {
            least = Math.min(least, price[i]);
            int val = price[i] - least;
            dp1[i] = Math.max(dp1[i-1], val);
        }
        
        int highest = price[n-1];
        for(int i = n-2; i>=0; i--) {
            highest = Math.max(highest, price[i]);
            int val = highest - price[i];
            dp2[i] = Math.max(dp2[i+1], val);
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = Math.max(ans, dp1[i] + dp2[i]);
        }
        
        return ans;
    }
}
        
