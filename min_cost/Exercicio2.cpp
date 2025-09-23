class Solution {
public:

    vector<int> pai;
    vector<int> nivel;

    int find(int i) {
        if (pai[i] == i) return i;
        return pai[i] = find(pai[i]);
    }

    void unite(int i, int j) {
        int raiz_i = find(i);
        int raiz_j = find(j);
        
        if (raiz_i != raiz_j) {
            if (nivel[raiz_i] < nivel[raiz_j]) {
                pai[raiz_i] = raiz_j;
            } else if (nivel[raiz_j] < nivel[raiz_i]) {
                pai[raiz_j] = raiz_i;
            } else {
                pai[raiz_j] = raiz_i;
                nivel[raiz_i]++;
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;

        vector<array<int, 3>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        pai.resize(n);
        nivel.assign(n, 0);
        iota(pai.begin(), pai.end(), 0);

        int custo_total = 0;
        int edges_count = 0;

        for (const auto& edge : edges) {
            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (find(u) != find(v)) {
                unite(u, v);
                custo_total += cost;
                edges_count++;
                if (edges_count == n - 1) break;
            }
        }
        
        return custo_total;
    }
};
