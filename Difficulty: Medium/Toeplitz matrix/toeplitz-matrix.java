//{ Driver Code Starts
import java.util.*;

class Check_IsToepliz {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int arr[][] = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) arr[i][j] = sc.nextInt();
            }

            Solution g = new Solution();
            boolean b = g.isToepliz(arr);

            if (b == true)
                System.out.println("true");
            else
                System.out.println("false");

            T--;
        }
    }
}
// } Driver Code Ends


class Solution {
    /*You are required to complete this method*/
    boolean check(int i, int j, int n, int m, int[][] mat) {
        if(i+1 >= n || j+1 >= m) return true;
        if(mat[i][j] == mat[i+1][j+1]) return true;
        return false;
    }
    
    boolean isToepliz(int mat[][]) {
        // Your code here
        int n = mat.length;
        int m = mat[0].length;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!check(i, j, n, m, mat)) return false;
            }
        }
        
        return true;
    }
}