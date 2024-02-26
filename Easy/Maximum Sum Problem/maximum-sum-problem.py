#User function Template for python3

class Solution:
    def maxSum(self, n): 
        # code here 
        if n < 12: return n
        n1 = self.maxSum(n//2);
        n2 = self.maxSum(n//3);
        n3 = self.maxSum(n//4);
        return n1 + n2 + n3;



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.maxSum(n))
# } Driver Code Ends