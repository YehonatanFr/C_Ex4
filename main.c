#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int vertex = 0;

typedef struct GRAPH_NODE_ *pnode;

int main() 
{
    int FLAG = 1;
    node *head = NULL;
    int c =0;
    int first =1;
    while (FLAG) 
    {
        if(first) 
        {
            c = getchar();
        }
        switch (c) {
            case 'A':
                getchar();
                pnode removi = head;
                while(removi!= NULL)
                {
                    DeleteNode(&head , removi->node_num);
                    removi = head;
                }
                scanf("%d", &vertex); // vertex graph.
                char n;
                scanf("%s", &n);
                for (int i = 0; i < vertex; ++i) 
                {
                    int src_id;
                    scanf("%d", &src_id);
                    pnode node_data;//maybe not good declaration.
                    if (i == 0) {
                        head = NewNode(src_id);
                        node_data = head;
                    }
                    pnode checker = head;
                    while (checker) {
                        if (checker->node_num == src_id) {
                            break;
                        }
                        checker = checker->next;
                    }
                    if (!checker) {
                        node_data = NewNode(src_id);
                        if (!node_data) {
                            exit(0);
                        }
                        pnode temp = head;
                        while (temp->next) {
                            temp = temp->next;
                        }
                        temp->next = node_data;
                    } else {
                        node_data = checker;
                    }
                    int dest;
                    while (scanf("%d", &dest)) {
                        pedge edge_data = NULL;
                        int weight;
                        scanf("%d", &weight);
                        pnode destination = head;
                        while (destination) 
                        {
                            if (destination->node_num == dest) 
                            {
                                break;
                            }
                            destination = destination->next;
                        }
                        if (destination) {
                            edge_data = NewEdge(weight, destination);
                            if (!edge_data) {
                                exit(0);
                            }
                        } 
                        else 
                        {
                            destination = NewNode(dest);
                            if (!destination) {
                                exit(0);
                            } else {
                                pnode temp = head;
                                while (temp->next) {
                                    temp = temp->next;
                                }
                                temp->next = destination;
                            }
                            edge_data = NewEdge(weight, destination);
                            if (!edge_data) {
                                exit(0);
                            }
                        }
                        
                        pedge temp = node_data->edges;
                        if (!temp) {
                            node_data->edges = edge_data;
                        } else {
                            while (temp->next) {
                                temp = temp->next;
                            }
                            temp->next = edge_data;
                        }
                    }
                    c = getchar();
                    if (c != 'n') {
                        first=0;
                        break;
                    }
                }
                break;
            case 'B':
                getchar();
                int to_add;
                scanf("%d", &to_add);
                AddNode(&head, to_add);
                first=1;
                break;
            case 'D':
                getchar();
                int node_to_remove;
                scanf("%d", &node_to_remove);
                DeleteNode(&head, node_to_remove);
                first=1;
                break;
            case 'S':
                getchar();
                int dest, src;
                scanf("%d %d", &src, &dest);
                printf("Dijsktra shortest path: ");
                dijkstra(&head, src, dest, 1);
                first=1;
                break;
            case 'T':
                getchar();
                TSP(&head);
                first=1;
                break;
            case ' ':
                break;
            default:
                FLAG = 0;
                break;
        }
    }
    node *removie = head;
    while(removie!=NULL){
        DeleteNode(&head , removie->node_num);
        removie = head;
    }
}