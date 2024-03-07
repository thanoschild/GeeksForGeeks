//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        int window = 1;
        string str = "";
        string ans;
        
        for(int i = 0; i<n; i++) {
            while(str.length() != window) str += s[i];
            
            if(s.find(str, i+1) != string::npos) {
                window++;
                ans = str;
            } 
            else {
                str.erase(0, 1);
            }
        }
        
        if(ans.size() == 0) return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends