#User function Template for python3
class Solution:
	def countPairs(self, mat1, mat2, n, x):
		# code here
		r1, c1, r2, c2, ans = 0, 0, n-1, n-1, 0
		
		while r1 < n and r2 >= 0:
		    _sum = mat1[r1][c1] + mat2[r2][c2]
		    if _sum <= x:
		        if _sum == x:
		            ans += 1
		        if c1 < n - 1:
		            c1 += 1
		        else:
		            c1 = 0
		            r1 += 1
		    elif _sum > x:
		        if c2 > 0:
		            c2 -= 1
		        else:
		            c2 = n - 1
		            r2 -= 1
		  
		return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n , x = input().split()
		n,x = int(n), int(x)
		mat1 = []
		for _ in range(n):
			a = [int(x) for x in input().split()]
			mat1.append(a)

		mat2 = []
		for _ in range(n):
			a = [int(x) for x in input().split()]
			mat2.append(a)

		ob = Solution()
		ans = ob.countPairs(mat1, mat2, n, x)
		print(ans)

# } Driver Code Ends