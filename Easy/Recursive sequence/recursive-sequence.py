#User function Template for python3

class Solution:
    def sequence(self, n):
        # code here
        ans, count, mod = 0, 1, 10**9 + 7
        for i in range(1, n+1):
            num = 1
            for j in range(1, i+1):
                num = (num * count) % mod;
                count += 1
            ans = (ans + num) % mod;
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        
        ob = Solution()
        print(ob.sequence(N))
# } Driver Code Ends