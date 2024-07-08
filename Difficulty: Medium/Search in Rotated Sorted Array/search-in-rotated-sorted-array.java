//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line = in.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int key = Integer.parseInt(in.readLine().trim());

            out.println(new Solution().search(arr, key));
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int search(int[] arr, int key) {
        // Complete this function
        int n = arr.length;
        int l = 0, h = n - 1;
        
        while(l <= h) {
            int mid = (h - l)/2 + l;
            if(arr[mid] == key) return mid;
            else if(arr[l] <= arr[mid]) {
                if(key >= arr[l] && key < arr[mid]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(arr[h] >= arr[mid]) {
                if(key <= arr[h] && key > arr[mid]) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
        }
        
        return -1;
    }
}