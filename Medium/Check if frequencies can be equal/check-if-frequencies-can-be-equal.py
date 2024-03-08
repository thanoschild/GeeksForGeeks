#User function Template for python3
class Solution:
    def sameFreq(self, s):
        mp, freq = {}, {}
        
        for c in s:
            if c in mp:
                mp[c] += 1
            else:
                mp[c] = 1
        
        max_freq, min_freq = float('-inf'), float('inf')
        for key, value in mp.items():
            if value in freq:
                freq[value] += 1
            else:
                freq[value] = 1
            max_freq = max(max_freq, value)
            min_freq = min(min_freq, value)
            
        if len(freq) != 1 and freq[max_freq] != 1:
            return False
        if max_freq - min_freq > 1:
            return False
        
        return True


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
	T=int(input())

	for _ in range(T):
		s = input()
		ob = Solution()
		answer = ob.sameFreq(s)
		if answer:
			print(1)
		else:
			print(0)

# } Driver Code Ends