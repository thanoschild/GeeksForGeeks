#User function Template for python3

class Solution:
    
    def lcs(self, s1, s2, s3, i, j, k, dp):
        if i == 0 or j == 0 or k == 0:
            return 0
        if dp[i][j][k] != -1:
            return dp[i][j][k]
        
        if s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]:
            dp[i][j][k] = 1 + self.lcs(s1, s2, s3, i-1, j-1, k-1, dp)
            return dp[i][j][k]
        
        p = self.lcs(s1, s2, s3, i-1, j, k, dp)
        q = self.lcs(s1, s2, s3, i, j-1, k, dp)
        r = self.lcs(s1, s2, s3, i, j, k-1, dp)
        
        dp[i][j][k] = max(p, q, r)
        return dp[i][j][k]
        

    def LCSof3(self,A,B,C,n1,n2,n3):
        # code here
        dp = [[[-1 for _ in range(22)] for _ in range(22)] for _ in range(22)]
        return self.lcs(A, B, C, n1, n2, n3, dp)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        n1,n2,n3 = map(int,input().split())
        A,B,C = input().split()

        solObj = Solution()

        ans = solObj.LCSof3(A,B,C,n1,n2,n3)

        print(ans)
# } Driver Code Ends