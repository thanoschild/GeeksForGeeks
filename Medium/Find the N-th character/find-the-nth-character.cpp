//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    char nthCharacter(string s, int r, int n) {
        //code here
        if(r==0)  return s[n];
        
        string ss;
        int ind = n/(1<<r);
        if(s[ind]=='1')  ss="10";
        else  ss="01";
        
        return nthCharacter(ss, r-1, n % (1<<r) );
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends