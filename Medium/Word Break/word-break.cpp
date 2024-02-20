//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int getMaxLength(vector<string> &dict) {
        int max_len = 0;
        for(string s : dict) {
            max_len = max(max_len, (int)s.size());
        }
        return max_len;
    }
    
    int wordBreak(int n, string s, vector<string> &dict) {
        //code here
        if(n == 0) return 0;
        int m = s.size();
        int max_len = getMaxLength(dict);
        unordered_set<string> st(dict.begin(), dict.end());
        vector<bool> dp(m+1, 0);
        dp[0] = 1;
        
        for(int i = 1; i<=m; i++) {
            for(int j = i - 1; j>=0 && j - i < max_len; j--) {
                if(dp[j]) {
                    if(st.count(s.substr(j, i - j))) dp[i] = 1;
                }
            }
        }
        
        return dp[m];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends