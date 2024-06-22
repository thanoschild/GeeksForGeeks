//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        // code here
        stringstream ss(sentence);
        string temp;
        vector<string> v;
        while(ss >> temp) {
            v.push_back(temp);
        }
        
        vector<long long> ans;
        for(int i = 0; i<v.size(); i++) {
            if(all_of(v[i].begin(), v[i].end(), ::isdigit)) {
                if(v[i].find('9') == string::npos) {
                    ans.push_back(stoll(v[i]));
                }
            }
        }
        if(!ans.size()) return -1;
        sort(ans.begin(), ans.end());
        return ans[ans.size() - 1];
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends