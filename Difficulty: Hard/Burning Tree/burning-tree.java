//{ Driver Code Starts
//Initial Template for Java


import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
	int data;
	Node left;
	Node right;

	Node(int data) {
		this.data = data;
		left = null;
		right = null;
	}
}

class GfG {

	static Node buildTree(String str) {

		if (str.length() == 0 || str.charAt(0) == 'N') {
			return null;
		}

		String ip[] = str.split(" ");
		// Create the root of the tree
		Node root = new Node(Integer.parseInt(ip[0]));
		// Push the root to the queue

		Queue<Node> queue = new LinkedList<>();

		queue.add(root);
		// Starting from the second element

		int i = 1;
		while (queue.size() > 0 && i < ip.length) {

			// Get and remove the front of the queue
			Node currNode = queue.peek();
			queue.remove();

			// Get the current node's value from the string
			String currVal = ip[i];

			// If the left child is not null
			if (!currVal.equals("N")) {

				// Create the left child for the current node
				currNode.left = new Node(Integer.parseInt(currVal));
				// Push it to the queue
				queue.add(currNode.left);
			}

			// For the right child
			i++;
			if (i >= ip.length)
				break;

			currVal = ip[i];

			// If the right child is not null
			if (!currVal.equals("N")) {

				// Create the right child for the current node
				currNode.right = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				queue.add(currNode.right);
			}
			i++;
		}

		return root;
	}

	static void printInorder(Node root) {
		if (root == null)
			return;

		printInorder(root.left);
		System.out.print(root.data + " ");

		printInorder(root.right);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while (t > 0) {
			String s = br.readLine();
			int target = Integer.parseInt(br.readLine());
			Node root = buildTree(s);

			Solution g = new Solution();
			System.out.println(g.minTime(root, target));
			t--;

		}
	}
}



// } Driver Code Ends


//User function Template for Java

class Solution
{
    /*class Node {
    	int data;
    	Node left;
    	Node right;
    
    	Node(int data) {
    		this.data = data;
    		left = null;
    		right = null;
    	}
    }*/
    
    private static int getTime(Node target, HashMap<Node, Node> parentMap) {
        Queue<Node> pq = new LinkedList<>();
        pq.add(target);
 
        HashMap<Node, Boolean> visited = new HashMap<>();
        visited.put(target, true);
        
        int time = 0;

        while (!pq.isEmpty()) {
            int n = pq.size();
            boolean spreadOccurred = false; 
            
            for (int i = 0; i < n; i++) {
                Node currentNode = pq.poll();

                if (currentNode.left != null && !visited.containsKey(currentNode.left)) {
                    pq.add(currentNode.left);
                    visited.put(currentNode.left, true);
                    spreadOccurred = true;
                }
      
                if (currentNode.right != null && !visited.containsKey(currentNode.right)) {
                    pq.add(currentNode.right);
                    visited.put(currentNode.right, true);
                    spreadOccurred = true;
                }

                if (parentMap.containsKey(currentNode) && !visited.containsKey(parentMap.get(currentNode))) {
                    pq.add(parentMap.get(currentNode));
                    visited.put(parentMap.get(currentNode), true);
                    spreadOccurred = true;
                }
            }

            if (spreadOccurred) {
                time++;
            }
        }
        
        return time;
    }
    
    private static Node findTargetNode(Node root, HashMap<Node, Node> mp, int target) {
        Queue<Node> pq = new LinkedList<>();
        pq.add(root);
        Node ans = null;
        while(!pq.isEmpty()) {
            Node t = pq.poll();
            if(t.data == target) ans = t;
            if(t.left != null) {
                mp.put(t.left, t);
                pq.add(t.left);
            }
            if(t.right != null) {
                mp.put(t.right, t);
                pq.add(t.right);
            }
        }
        return ans;
    }
    
    public static int minTime(Node root, int target) {
        if(root == null) return 0;
        HashMap<Node, Node> mp = new HashMap<>();
        Node targetNode = findTargetNode(root, mp, target);
        int time = getTime(targetNode, mp);
        return time;
    }
}