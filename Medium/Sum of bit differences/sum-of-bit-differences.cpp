//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    ll ans = 0;
	    for(int i = 0; i<=31; i++) {
	        ll zeros = 0;
	        ll ones = 0;
	        for(int j = 0; j<n; j++) {
	            if(arr[j] & (1 << i)) ones++;
	            else zeros++;
	        }
	        ans += (zeros * ones);
	    }
	    
	    return ans * 2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends