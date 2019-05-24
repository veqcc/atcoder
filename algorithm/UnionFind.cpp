#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    int src, dest;
};

struct Graph {
    int V, E;
    struct Edge *edge;
};

struct subset {
    int parent;
    int rank;
};

struct Graph *createGraph(int V, int E) {
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *) malloc(E * sizeof(struct Edge));
    return graph;
}

int find(subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int isCycle(Graph *graph) {
    int V = graph->V;
    int E = graph->E;

    subset *subsets = (subset *) malloc(V * sizeof(subsets));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (int e = 0; e < E; e++) {
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);
        if (x == y) return 1;
        Union(subsets, x, y);
    }
    return 0;
}

int main() {
    int V = 3, E = 3;
    Graph *graph = createGraph(V, E);

    graph->edge[0] = (Edge) {0, 1};
    graph->edge[1] = (Edge) {1, 2};
    graph->edge[2] = (Edge) {0, 2};

    if (isCycle(graph)) {
        printf("graph contains cycle");
    } else {
        printf("graph doesn't contain cycle");
    }

    return 0;
}
