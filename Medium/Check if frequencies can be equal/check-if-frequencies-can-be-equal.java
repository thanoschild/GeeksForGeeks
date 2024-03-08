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
            
            String input[] = read.readLine().split(" ");
            String a = input[0];
            
            Solution ob = new Solution();
            if(ob.sameFreq(a)){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    boolean sameFreq(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        HashMap<Integer, Integer> freq = new HashMap<>();
        
        for(char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        
        int minFreq = Integer.MAX_VALUE, maxFreq = Integer.MIN_VALUE;
        for(int it : mp.values()) {
            freq.put(it, freq.getOrDefault(it, 0) + 1);
            minFreq = Math.min(minFreq, it);
            maxFreq = Math.max(maxFreq, it);
        }
        
        if(freq.size() != 1 && freq.get(maxFreq) != 1) return false;
        if(maxFreq - minFreq > 1) return false;
        return true;
    }
}