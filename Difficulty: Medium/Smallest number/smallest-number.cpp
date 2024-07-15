//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        int num = 0, place = 1;
    
        for (int i=d; i>1; i--) {
            int n = min(s-1, 9);
            num = n * place + num;
            
            s -= n;
            place *= 10;
        }
        
        if (s/10 != 0) return to_string(-1);
        
        return to_string(place * max(1, s) + num);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends