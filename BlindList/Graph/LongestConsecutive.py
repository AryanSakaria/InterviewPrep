class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #create dictionaries for graph 
        #and visit
        graph = {}
        visited = {}
        for x in nums:
            graph[x] = []
            visited[x] = False
            
        #create graph
        for x in graph:
            if x-1 in graph:
                #Each node will have at max 2 neighbours
                #One before and one after
                graph[x-1].append(x)
                graph[x].append(x-1)
                
        count = 0
        #The largest connected component will have 
        for x in graph:
            if not visited[x]:
                count = max(count, self.cc(visited, graph,x))
                
        return count
    
    def cc(self, visited, graph, node):
        #This is DFS to get length of connected component
        visited[node] = True
        count = 1
        for x in graph[node]:
            if not visited[x]:
                count += self.cc(visited, graph, x)
        return count
