#User function Template for python3
class Solution:
	def getCount(self, n):
        dp = [1]*10
       
        for i in range(1, n):
            temp = [0]*10
            temp[0] = dp[0] + dp[8]
            temp[1] = dp[1] + dp[2] + dp[4]
            temp[2] = dp[1] + dp[2] + dp[3] + dp[5]
            temp[3] = dp[2] + dp[3] + dp[6]
            temp[4] = dp[1] + dp[4] + dp[5] + dp[7]
            temp[5] = dp[2] + dp[4] + dp[5] + dp[6] + dp[8]
            temp[6] = dp[3] + dp[5] + dp[6] + dp[9]
            temp[7] = dp[4] + dp[7] + dp[8]
            temp[8] = dp[5] + dp[7] + dp[8] + dp[9] + dp[0]
            temp[9] = dp[6] + dp[8] + dp[9]
            dp = temp
       
        return sum(dp)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.getCount(n)
        print(ans)

# } Driver Code Ends