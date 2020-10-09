
from collections import defaultdict 
  

class Graph: 
 
    def __init__(self): 
  
       
        self.graph = defaultdict(list) 
  
   
    def addEdge(self,u,v): 
        self.graph[u].append(v)
        self.graph[v].append(u) 
  
  
    def BFS(self, s): 
  
      
        visited = [False] * (len(self.graph)) 
  
       
        queue = [] 
  
       
        queue.append(s) 
        visited[s] = True
  
        while queue: 
  
          
            s = queue.pop(0) 
            print (s, end = " ") 
  
            for i in self.graph[s]: 
                if visited[i] == False: 
                    queue.append(i) 
                    visited[i] = True
  

g = Graph() 
TotalVertexs = int(input("Enter Total Vertexs: \n"))
TotalEdges = int(input("Enter Total Edges: \n"))

for i in range(TotalEdges):
    x, y = input("Enter two space seperated Conected Vertex: \n").split()
    g.addEdge(int(x),int(y))

  
print ("Following is Depth First Traversal"
                  " (starting from vertex 0)") 
g.BFS(0) 
  
# This code is contributed by Amar Shankar 

