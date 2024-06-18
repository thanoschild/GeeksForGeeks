#User function template for Python

class Solution:
    def rectanglesInCircle(self,r):
        #code here
        ans=0
        for x in range(1,2*r):
            for y in range(x,2*r):
                if x*x+y*y<=4*r*r and x==y:
                    ans+=1
                elif x*x+y*y<=4*r*r and x!=y:
                    ans+=2
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python

import math

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.rectanglesInCircle(N)
        print(ans)

# } Driver Code Ends