#User function Template for python3
class Solution:
    def numberOfConsecutiveOnes (ob,n):
        # code here 
        a, b = 1, 1
        count = 1
        K = 10 ** 9 + 7
        
        while count < n:
            a, b = a+b, a
            count += 1
            a %= K
            b %= K
        
        non_consecutive = (a + b) % K
        ans = (2 ** n) % K - non_consecutive
        return ans % K  


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        N = int(input())

        ob = Solution()
        print(ob.numberOfConsecutiveOnes(N))

# } Driver Code Ends