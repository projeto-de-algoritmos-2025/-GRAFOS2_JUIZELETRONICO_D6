#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class DSU {
private:
    std::vector<int> pai;
    int componentes;

public:
    DSU(int n) {
        pai.resize(n);
        std::iota(pai.begin(), pai.end(), 0);
        componentes = n;
    }

    int encontrar(int i) {
        if (pai[i] == i) {
            return i;
        }
        return pai[i] = encontrar(pai[i]);
    }

    bool unir(int i, int j) {
        int raiz_i = encontrar(i);
        int raiz_j = encontrar(j);
        if (raiz_i != raiz_j) {
            pai[raiz_i] = raiz_j;
            componentes--;
            return true;
        }
        return false;
    }
    
    bool estaConectado() {
        return componentes == 1;
    }
};

class Solution {
public:

    std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& arestas) {
        for (int i = 0; i < arestas.size(); ++i) {
            arestas[i].push_back(i);
        }

        std::sort(arestas.begin(), arestas.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });

        int peso_mst_base = 0;
        DSU dsu_base(n);
        for (const auto& aresta : arestas) {
            if (dsu_base.unir(aresta[0], aresta[1])) {
                peso_mst_base += aresta[2];
            }
        }

        std::vector<int> arestas_criticas;
        std::vector<int> arestas_pseudo_criticas;

        for (int i = 0; i < arestas.size(); ++i) {
            int peso_sem_aresta = 0;
            DSU dsu_sem_aresta(n);
            for (int j = 0; j < arestas.size(); ++j) {
                if (i == j) continue;
                const auto& aresta = arestas[j];
                if (dsu_sem_aresta.unir(aresta[0], aresta[1])) {
                    peso_sem_aresta += aresta[2];
                }
            }

            if (!dsu_sem_aresta.estaConectado() || peso_sem_aresta > peso_mst_base) {
                arestas_criticas.push_back(arestas[i][3]);
                continue;
            }

            DSU dsu_com_aresta(n);
            dsu_com_aresta.unir(arestas[i][0], arestas[i][1]);
            int peso_com_aresta = arestas[i][2];

            for (int j = 0; j < arestas.size(); ++j) {
                if (i == j) continue;
                const auto& aresta = arestas[j];
                if (dsu_com_aresta.unir(aresta[0], aresta[1])) {
                    peso_com_aresta += aresta[2];
                }
            }
            
            if (peso_com_aresta == peso_mst_base) {
                arestas_pseudo_criticas.push_back(arestas[i][3]);
            }
        }

        return {arestas_criticas, arestas_pseudo_criticas};
    }
};
