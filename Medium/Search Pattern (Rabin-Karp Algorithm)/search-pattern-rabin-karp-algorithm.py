#User function Template for python3

class Solution:
    def search(self, pattern, text):
        # code here
        ans = []
        n, m= len(pattern), len(text)
        for i in range(m - n + 1):
            if text[i] != pattern[0]:
                continue
            if text[i:i + n] == pattern:
                ans.append(i+1)
            
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends