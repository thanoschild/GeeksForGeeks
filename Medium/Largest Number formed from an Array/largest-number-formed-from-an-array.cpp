//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
bool comp(string &a, string &b) {
    return (a+b) > (b+a);
}

class Solution{
public:
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    sort(arr.begin(), arr.end(), comp);
	    string ans = "";
	    for(auto s : arr) {
	        ans += s;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends