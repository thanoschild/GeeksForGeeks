#User function Template for python3

class Solution:
    def solve(self, idx, s, dp, sum):
        if idx >= len(s): return 1
        if dp[idx][sum] != -1: return dp[idx][sum]
        
        curr_sum, dp[idx][sum] = 0, 0
        for i in range(idx, len(s)):
            curr_sum += (ord(s[i]) - ord('0'))
            if curr_sum >= sum:
                dp[idx][sum] += self.solve(i+1, s, dp, curr_sum)
        return dp[idx][sum]
        
	def TotalCount(self, s):
		n = len(s)
		dp = [[-1] * 902 for _ in range(n)] 
		return self.solve(0, s, dp, 0)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()
		ob = Solution()
		ans = ob.TotalCount(s)
		print(ans)
# } Driver Code Ends