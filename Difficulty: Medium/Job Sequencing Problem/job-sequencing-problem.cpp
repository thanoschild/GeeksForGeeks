//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
    public:
    vector<int> JobScheduling(Job arr[], int n) { 
       vector<Job> v;
       int mx = -1;
       for(int i = 0; i<n; i++) {
           v.push_back(arr[i]);
           mx = max(mx, arr[i].dead);
       }
       
       sort(v.begin(), v.end(), [&](Job &a, Job &b) {
           return a.profit > b.profit;
       });
       int ans = 0, count = 0;
       vector<int> visited(mx+1, -1);
       
       for(auto it : v) {
           int id = it.id;
           int dead = it.dead;
           int profit = it.profit;
           int day = dead;
           
           while(day > 0) {
               if(visited[day] == -1) break;
               day--;
           }
           
           if(day != 0) {
               count++;
               ans += profit;
               visited[day] = 1;
           }
       } 
       
       return {count, ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends