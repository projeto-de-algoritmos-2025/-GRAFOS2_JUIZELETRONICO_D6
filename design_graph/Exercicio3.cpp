class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    int num_nodes;

    Graph(int n, vector<vector<int>>& edges) {
        num_nodes = n;
        adj.resize(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        const int INF = 1000000000;
        vector<int> dist(num_nodes, INF);
        
        dist[node1] = 0;
        
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;
        
        pq.push({0, node1});
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dist[u]) {
                continue;
            }
            
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int custo = edge.second;
                
                if (dist[u] + custo < dist[v]) {
                    dist[v] = dist[u] + custo;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if (dist[node2] == INF) {
            return -1;
        }
        
        return dist[node2];
    }
};

