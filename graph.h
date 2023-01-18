#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

int min(const int arr[],int n);
int factorial(int size);
int FindShortestPath(pnode * head,int values[], int size);
int dijkstra(pnode* head , int src , int dest , int bool);
void TSP(node **head);
void per(node **head, int *values, int right, int left, int *permutat, int *n);
void swap(int *x, int *y);
void clean(int **ShortestPath,int size);
pnode NewNode(int id);
pedge NewEdge(int weight, pnode end);
void DeleteEdge(edge **edge_to_rm, int dest);
void DeleteAllEdges(pnode target, pnode *head);
void DeleteNode(node **head, int node_to_remove);
void AddNode(node **head, int id_of_node_to_add);

#endif
