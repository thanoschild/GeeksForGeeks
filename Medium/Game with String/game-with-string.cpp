//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);
    
        for(char c : s) {
            freq[c - 'a']++;
        }
        for(int i = 0; i<26; i++) {
            if(freq[i] != 0) {
                pq.push({freq[i], (char) (i + 'a')});
            }
        }
        
        while(k && !pq.empty()) {
            pair<int, char> t = pq.top();
            pq.pop();
            int x = t.first;
            char y = t.second;
            x--, k--;
            pq.push({x, y});
        }
        
        int count = 0;
        while(!pq.empty()) {
            pair<int, char> t = pq.top();
            pq.pop();
            count += (t.first * t.first);
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends