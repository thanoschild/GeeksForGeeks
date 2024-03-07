#User function Template for python3

class Solution:
    def longestSubstring(self, s , n):
        # code here 
        window = 1
        str = ""
        ans = ""
    
        for i in range(n):
            while len(str) != window:
                str += s[i]
    
            if s.find(str, i + 1) != -1:
                window += 1
                ans = str
            else:
                str = str[1:]
    
        if len(ans) == 0:
            return "-1"
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        S=input()
        
        ob = Solution()
        print(ob.longestSubstring(S , N))
# } Driver Code Ends