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

// void build_graph_cmd(pnode *head);
// void insert_node_cmd(pnode *head);
// void delete_node_cmd(pnode *head);
// void printGraph_cmd(pnode head); //for self debug
// void deleteGraph_cmd(pnode* head);
// void shortsPath_cmd(pnode head);
// void TSP_cmd(pnode head);

void CreateLinkedList (int n, pnode *head);
void UpdateEdge (pnode *head, int sorceEdge, int EdgeTarget, int weight);
void PrintGraph(node **head);
node* FindPnode(node **head, int num);
void FreeEdge(node *sorce);
pnode NewNode (int num, pnode next);
void printGraph(pnode head);
void DeleteEdges(node **head, int NodeToDelte);
void DeleteNode(node **head, int NodeToDelete);
void DeleteSingleEdge(edge **head, int NodeToDelete);
int FindMinWeight(edge **head);
void printMinWeight(node **head);
void swap(int *x, int *y);
int factorial(int size);
int min(const int arr[],int n);
int arrayc(node **head,int values[], int size);
int dijkstra(node **head , int src , int dest , int bool);
void per(node **head, int *values, int right, int left ,int *permutat, int *n);
void TSP(node **head);
void deleteGraph_cmd(node **head);

#endif
