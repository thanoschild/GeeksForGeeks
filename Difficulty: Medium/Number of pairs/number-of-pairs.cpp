//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long findIndex(vector<int> &y, int val, int m) {
        long long ans = -1L;
        int lo = 0, hi = m - 1;
        while(lo <= hi) {
            int mid = (hi - lo)/2 + lo;
            if(y[mid] > val) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
    
    long long countPairs(vector<int> &x, vector<int> &y) {
        // Your Code goes here.
        int n = x.size(), m = y.size();
        // sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        long long ones = 0, twos = 0, threeFours = 0, ans = 0;
        for(auto it : y) {
            if(it == 1) ones++;
            else if(it == 2) twos++;
            else if(it == 3 || it == 4) threeFours++;
        }
        
        for(auto it : x) {
            if(it == 1) continue;
            else if(it == 2) {
                long long idx = findIndex(y, it, m);
                if(idx != -1) ans += m - idx;
                ans += ones;
                ans -= threeFours;
            }
            else {
                long long idx = findIndex(y, it, m);
                if(idx != -1) ans += m - idx;
                if(it == 3) ans += twos;
                ans += ones;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends