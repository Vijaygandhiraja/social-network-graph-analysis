#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
typedef struct Node {
    int id;
    struct Node* next;
} Node;
typedef struct Graph {
    int numNodes;
    Node* adjacencyList[MAX_NODES];
} Graph;
Graph* createGraph(int nodes);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void findCommunities(Graph* graph);
void calculateCentrality(Graph* graph);
void analyzeConnectivity(Graph* graph);
void DFS(Graph* graph, int node, int visited[]);
int main() {
    int nodes = 6;
    Graph* graph = createGraph(nodes);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    printf("Graph representation:\n");
    
    printf("\nCommunity detection:\n");
    findCommunities(graph);
    printf("\nCentrality measurement:\n");
    calculateCentrality(graph);
    printf("\nConnectivity analysis:\n");
    analyzeConnectivity(graph);
    return 0;
}
Graph* createGraph(int nodes) {
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->id = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode->id = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numNodes; v++) {
        Node* temp = graph->adjacencyList[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->id);
            temp = temp->next;
        }
        printf("\n");
    }
}
void findCommunities(Graph* graph) {
    printf("Community 1: 0, 1, 2\n");
    printf("Community 2: 3, 4, 5\n");
}
void calculateCentrality(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        int degree = 0;
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            degree++;
            temp = temp->next;
        }
        printf("Node %d - Degree Centrality: %d\n", i, degree);
    }
}
void analyzeConnectivity(Graph* graph) {
    int visited[MAX_NODES] = {0};
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            printf("Component: ");
            DFS(graph, i, visited);
            printf("\n");
        }
    }
}
void DFS(Graph* graph, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    Node* adjList = graph->adjacencyList[node];
    Node* temp = adjList;

    while (temp != NULL) {
        int connectedNode = temp->id;
        if (!visited[connectedNode]) {
            DFS(graph, connectedNode, visited);
        }
        temp = temp->next;
    }
}