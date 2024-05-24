    #code here
class Solution:
    def max_Books(self, n, k, a):
        count=0
        maximum=0
        total=0
        
        for i in range(n):
            if a[i]<=k:
                total+=a[i]
            else:
                maximum=max(maximum,total)
                total=0
        maximum=max(maximum,total)
        return maximum

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        temp = list(map(int, input().strip().split()))
        n = temp[0]
        k = temp[1]
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.max_Books(n, k, arr))
# Contributed by:Harshit Sidhwa

# } Driver Code Ends