//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s) {
	    // code here 
	    unordered_map<char, int> mp;
	    unordered_map<int, int> freq;
	    for(char c : s) {
	        mp[c]++;
	    }
	    
	    int min_freq = 1e8, max_freq = -1;
	    for(auto it : mp) {
	        freq[it.second]++;
	        max_freq = max(max_freq, it.second);
	        min_freq = min(min_freq, it.second);
	    }
	    
	    if(max_freq - min_freq > 1) return false;
	    if(freq.size() != 1 && freq[max_freq] != 1) return false;
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends