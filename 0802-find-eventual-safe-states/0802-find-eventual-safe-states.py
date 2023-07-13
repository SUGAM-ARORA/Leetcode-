class Solution:
    def dfs(self, adj, src, vis, recst):
        vis[src] = True
        recst[src] = True
        for x in adj[src]:
            if not vis[x] and self.dfs(adj, x, vis, recst):
                return True
            elif recst[x]:
                return True
        recst[src] = False
        return False

    def eventualSafeNodes(self, graph):
        n = len(graph)
        adj = [[] for _ in range(n)]
        for i in range(n):
            for j in range(len(graph[i])):
                adj[i].append(graph[i][j])

        vis = [False] * n
        recst = [False] * n
        for i in range(n):
            if not vis[i]:
                self.dfs(adj, i, vis, recst)

        ans = []
        for i in range(len(recst)):
            if not recst[i]:
                ans.append(i)
        return ans
        