//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void dfs(vector<vector<int>> &edges, int i, vector<bool> &visited, string &ans){
        visited[i] = true;
        for(auto it : edges[i]){
            if(!visited[it]){
                dfs(edges, it, visited, ans);
            }
        }
        char c = i + 'a';
        ans = c + ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<vector<int>> edges(k);
        for(int i = 0; i<n-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            for(int i = 0, j = 0; i<s1.size()&&j<s2.size(); i++, j++){
                if(s1[i] != s2[j]){
                    edges[s1[i] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<bool> visited(k, false);
        string ans = "";
        for(int i = 0; i<k; i++){
           if(!visited[i]){
               dfs(edges, i, visited, ans);
           } 
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends