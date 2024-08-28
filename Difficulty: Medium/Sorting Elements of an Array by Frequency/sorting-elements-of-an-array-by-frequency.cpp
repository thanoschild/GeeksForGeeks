//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        vector<int> v;
        priority_queue<pair<int, int>> hp;
        for(auto it : mp) {
            hp.push({it.second, -1*it.first});
        }
        
        while(!hp.empty()) {
          pair<int, int> p = hp.top();
          hp.pop();
          while(p.first--) {
              v.push_back(-1*p.second);
          }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends