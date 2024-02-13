#User function Template for python3

class Solution:
    def criticalConnections(self, V, adj):
        # code here
        
        disc = [-1 for i in range(V)]
        low = [-1 for i in range(V)]
        self.time = 0
        bridges = []

        def SCC(u, par = -1):
            disc[u] = self.time
            low[u] = self.time
            self.time += 1

            for v in adj[u]:
                if v == par:
                    continue
                if disc[v] == -1:
                    SCC(v, u)
                    low[u] = min(low[u], low[v])
                    if low[v] > disc[u]:
                        if v > u:
                            bridges.append([u, v])
                        else:
                            bridges.append([v, u])
                else:
                    low[u] = min(low[u], disc[v])

        for i in range(V):
            if disc[i] == -1:
                SCC(i)
        bridges.sort()
        return bridges


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':

	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.criticalConnections(V, adj)
		for i in range(len(ans)):
		    print(ans[i][0],ans[i][1])

# } Driver Code Ends