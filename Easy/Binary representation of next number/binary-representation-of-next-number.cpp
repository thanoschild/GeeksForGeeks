//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        s = "0" + s;
        int n = s.size();
        for(int i = n - 1; i>=0; i--) {
            if(s[i] == '0') {
                s[i] = '1';
                for(int j = i + 1; j<n; j++) s[j] = '0';
                break;
            }
        }
        
        for(int i = 0; i<n; i++) {
            if(s[i] != '0') return s.substr(i);
        }
        
        return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends