//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        unordered_map<char, int> mp;
        int length = 0;
        int unique = 0;
        for (auto it : str)
        {
            if (it == ' ')
                continue;
            mp[it - 'a']++;
            if (mp[it - 'a'] == 1)
            {
                unique++;
            }
            length++;
        }
        if (length < 26)
            return false;
        return (unique + k) >= 26;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends