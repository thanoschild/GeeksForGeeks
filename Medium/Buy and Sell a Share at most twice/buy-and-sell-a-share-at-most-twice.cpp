//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n = price.size();
            vector<int> dp1(n, 0), dp2(n, 0);
            int least = price[0];
            for(int i = 1; i<n; i++) {
                least = min(least, price[i]);
                int val = price[i] - least;
                dp1[i] = max(dp1[i-1], val);
            }
            
            int highest = price[n-1];
            for(int i = n-2; i>=0; i--) {
                highest = max(highest, price[i]);
                int val = highest - price[i];
                dp2[i] = max(dp2[i+1], val);
            }
            
            int ans = 0;
            for(int i = 0; i<n; i++) {
                ans = max(ans, dp1[i] + dp2[i]);
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends