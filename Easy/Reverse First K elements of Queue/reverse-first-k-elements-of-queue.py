from collections import deque

'''
Function Arguments :
		@param  : q ( given queue to be used), k(Integer )
		@return : list, just reverse the first k elements of queue and return new queue
'''

#Function to reverse first k elements of a queue.
class Solution:
    def modifyQueue(self, pq, k):
        st = deque()
        ans = deque()
        
        while pq and k > 0:
            st.append(pq.popleft())
            k -= 1
            
        while st:
            ans.append(st.pop())
            
        while pq:
            ans.append(pq.popleft())
            
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
from collections import deque

#Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,k = map(int,input().strip().split())
        a = list(map(int,input().strip().split()))

        queue = deque() # our queue to be used
        for i in range(n):
            queue.append(a[i]) # enqueue elements of array in our queue
        
        ob = Solution()
        result = ob.modifyQueue(queue,k)
        list_result = []
        while result:
            list_result.append(result.popleft())
        print(*list_result)
        
# } Driver Code Ends