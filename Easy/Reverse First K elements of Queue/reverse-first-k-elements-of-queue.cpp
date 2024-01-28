//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> pq, int k) {
        // add code here.
        stack<int> st;
        queue<int> ans;
        
        while(!pq.empty() && k > 0) {
            st.push(pq.front());
            k--;
            pq.pop();
        }
        
        while(!st.empty()) {
            ans.push(st.top());
            st.pop();
        }
        
        while(!pq.empty()) {
            ans.push(pq.front());
            pq.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends