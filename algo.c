#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

int dijkstra(node **head , int src , int dest , int bool)
{
    int max = INT_MIN;
    node *temp = *head;
    while(temp){
        if(temp->node_num >max){
            max= (temp->node_num);
        }
        temp = temp->next;
    }
    int *Queue = (int*) malloc(sizeof (int) * (max+1));
    int *dist = (int*) malloc(sizeof (int) * (max+1));
    if((!Queue) || (!dist)){
        return -1;
    }
    temp = *head;
    for (int i = 0; i <max+1 ; ++i) {
        dist[i] = INT_MAX;
        Queue[i] = -1;
    }
    dist[src]=0;

    while(temp){
        int index = temp->node_num;
        Queue[index]=1;
        temp = temp->next;
    }

    while(1)
    {
        int min = INT_MAX;
        int curr_node_id = -1;
        for (int i = 0; i <max+1; ++i) 
        {
            if(Queue[i]==1)
            {
                if(dist[i]<min)
                {
                    min = dist[i];
                    curr_node_id = i;
                }
            }
        }

        if(min==INT_MAX)
        {
            break;
        }
        Queue[curr_node_id]=-1;
        temp= *head;

        while(temp)
        {
            if(temp->node_num==curr_node_id)
            {
                break;
            }
            temp=temp->next;
        }

        edge *edge_of_neighbor = temp->edges;
        while(edge_of_neighbor)
        {
            int neighbors_id = edge_of_neighbor->endpoint->node_num;
            int alternative = dist[curr_node_id]+ (edge_of_neighbor->weight);
            if(alternative<dist[neighbors_id])
            {
                dist[neighbors_id]= alternative;
            }
            edge_of_neighbor = edge_of_neighbor->next;
        }
    }
    if(bool){
        if(dist[dest]!=INT_MAX){
            printf("%d \n" , dist[dest]);
        }
        else{
            int a = -1;
            printf("%d \n" , a);
        }
    }

    free(Queue);
    int ret = dist[dest];
    free(dist);
    return  ret;
}

void TSP(node **head)
{
    int NumberOfNodes = 0;
    scanf("%d", &NumberOfNodes);
    int values[NumberOfNodes];

    for (int i = 0; i < NumberOfNodes; ++i) 
    {
        scanf("%d", &values[i]);
    }

    int f = factorial(NumberOfNodes);
    int permutations[f];
    int temp = 0;
    per(head,values,0,NumberOfNodes-1,permutations,&temp);
    int n = min(permutations,f);
    
    if(permutations[n] == INT_MAX)
    {
        printf("TSP shortest path: %d \n",-1);
    }
    else
    {
        printf("TSP shortest path: %d \n",permutations[n]);
    }
}