//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(), arr.end());
        int N = arr.size();
        string ans;
        for(int i=0;i<arr[0].length();i++){
            string x=arr[0];
            string y=arr[N-1];
            if(x[i]==y[i]){
                ans.push_back(x[i]);
            }else{
                break;
            }
        }
        return ans==""?"-1":ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends