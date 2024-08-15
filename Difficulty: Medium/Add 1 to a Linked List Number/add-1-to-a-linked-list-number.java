//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class GfG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution obj = new Solution();
            head = obj.addOne(head);
            printList(head);
        }
    }
}
// } Driver Code Ends


/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {
    Node reverse(Node head) {
        if(head == null) return head;
        Node prev = null, curr = head, next;
        
        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    public Node addOne(Node head) {
        // code here.
        Node temp = reverse(head);
        Node curr = temp;
        
        int carry = 0, value = 0;
        curr.data += 1;
        
        while(curr != null) {
            carry = (curr.data)/10;
            value = (curr.data)%10;
            curr.data = value;
            
            if(carry != 0 && curr.next != null) {
                curr = curr.next;
                curr.data += carry;
            }
            else if(carry != 0 && curr.next == null) {
                Node newNode = new Node(carry);
                curr.next = newNode;
                curr = curr.next;
            }
            else break;
        }
        
        return reverse(temp);
    }
}
