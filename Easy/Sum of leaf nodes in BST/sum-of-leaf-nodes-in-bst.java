//{ Driver Code Starts
import java.util.*;

class Node
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}

class leaf_nodes
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node root = null;
            for(int i = 0; i < n; i++)
            {
                int data = sc.nextInt();
                root = insert(root, data);
            }
            Solution gfg = new Solution();
            System.out.println(gfg.sumOfLeafNodes(root));
        }
    }
    
    public static Node insert(Node root, int x)
    {
        
        if(root == null)
          {
              return (new Node(x));
          }
          
          if(x < root.data)
          {
              root.left = insert(root.left, x);
          }
          else if(x >= root.data)
          {
              root.right = insert(root.right, x);
          }
          
      return root;      
    }
    
}

// } Driver Code Ends


/*node class of the binary ssearch tree
class Node
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}*/
class Solution
{
    private static void solve(Node root, int[] sum) {
        if(root == null) return;
        if(root.left == null && root.right == null) sum[0] += root.data;
        solve(root.left, sum);
        solve(root.right, sum);
    }
    
    public static int sumOfLeafNodes(Node root) {
        // code here 
        int[] sum = new int[1];
        solve(root, sum);
        return sum[0];
    }
}
