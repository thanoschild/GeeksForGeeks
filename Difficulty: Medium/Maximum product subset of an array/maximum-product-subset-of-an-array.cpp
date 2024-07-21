//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n = arr.size();
        if(n == 1) return arr[0];
        long long int ans = 1,mod = pow(10,9)+7;
        int mx = -11,c = 0,z = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                c++;
                mx = max(mx,arr[i]);
            }
            if(arr[i]) ans = (ans*arr[i])%mod;
            else z++;
        }
        if(c == 1 && z == n-1 || z == n) return 0;
        return c%2 ? ans/mx : ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends