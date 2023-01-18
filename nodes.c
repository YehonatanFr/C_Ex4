#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

pnode NewNode(int id) 
{
    node *a = (pnode) malloc(sizeof(node));
    if (!a) 
    {
        return NULL;
    }
    a->node_num = id;
    a->edges = NULL;
    a->next = NULL;
    return a;
}

pedge NewEdge(int weight, pnode end) 
{
    edge *a = (pedge) malloc(sizeof(edge));
    if (!a) 
    {
        return NULL;
    }
    a->weight = weight;
    a->endpoint = end;
    a->next = NULL;
    return a;
}

void DeleteEdge(edge **edge_to_rm, int dest)
 {
    if (!(*edge_to_rm)) 
    {
        return;
    }

    if ((*edge_to_rm)->endpoint->node_num == dest) 
    {
        edge *temp = *edge_to_rm;
        *edge_to_rm = (*edge_to_rm)->next;
        free(temp);
    }
    if (*edge_to_rm)
    {
        edge *temp = *edge_to_rm;

        while (temp->next) 
        {
            if (temp->next->endpoint->node_num == dest)
            {
                pedge temp2 = temp->next;
                temp->next = temp->next->next;
                free(temp2);
                break;
            }
            temp = temp->next;
        }
    }
}

void DeleteAllEdges(node *target, node **head)
 {
    if ((target->edges)) 
    { 
        edge *temp = target->edges;
        while (temp->next) {
            DeleteEdge(&(temp->next), temp->next->endpoint->node_num);
        }
        DeleteEdge(&temp, temp->endpoint->node_num);
        target->edges = NULL;
    }

    int node_target_id = target->node_num;
    node *node_iter = *head;
    while (node_iter) 
    {
        edge *temp = node_iter->edges;
        if (temp)
         {  
            if (temp->endpoint->node_num == node_target_id) 
            {
                edge *temp2 = temp;
                temp = temp->next;
                if (!(temp)) 
                { 
                    DeleteEdge(&temp2, node_target_id);
                    node_iter->edges = NULL;
                    continue;
                }

                node_iter->edges = temp;
                DeleteEdge(&temp2, node_target_id);
            }

            while (temp->next) 
            {
                if(temp->next->endpoint->node_num == node_target_id) 
                {
                    DeleteEdge(&(temp->next), node_target_id);
                }

                temp = temp->next;
                if (!(temp)) 
                {
                    break;
                }
            }
        }
        node_iter = node_iter->next;
    }
}

void DeleteNode(node **head, int node_to_remove) 
{
    if (!(*head))
     {
        return;
    }
    if ((*head)->node_num == node_to_remove) 
    {
        node *temp = *head;
        if (!(temp->next)) 
        { 
            DeleteAllEdges(temp, head);
            *head = (*head)->next;
            free(temp);
            *head = NULL;
            return;
        }
        DeleteAllEdges(temp, head);
        *head = (*head)->next;
        free(temp);
        return;
    } 
    else 
    {
        node *temp = *head;
        while (temp->next) 
        {
            if (temp->next->node_num == node_to_remove) 
            {
                node *temp2 = temp->next;
                DeleteAllEdges(temp2, head);
                temp->next = temp->next->next;
                free(temp2);
                return;
            }
            temp = temp->next;
        }
    }
}


void AddNode(node **head, int id_of_node_to_add) 
{
    node *node_data;
    if (!*head) 
    { 
        *head = NewNode(id_of_node_to_add);
    }

    node *check = *head;
    int flag = 1;
    while (check) 
    {
        if (check->node_num == id_of_node_to_add) 
        {
            if ((check->edges))
             { 
                edge *temp = check->edges;
                while (temp->next) 
                {
                    DeleteEdge(&(temp->next), temp->next->endpoint->node_num);
                }
                DeleteEdge(&temp,
                           temp->endpoint->node_num);
                check->edges = NULL;
            }

            flag = 0;
            break;
        }
        check = check->next;
    }

    if (flag) 
    {
        node_data = NewNode(id_of_node_to_add);
        if (!node_data) 
        {
            exit(0);
        }

        node *temp4 = *head;
        while (temp4->next) {
            temp4 = temp4->next;
        }
        temp4->next = node_data;
    } 
    else 
    {
        node_data = check;
    }
    int dest;
    while (scanf("%d", &dest)) 
    {
        edge *edge_data = NULL;
        int weight;
        scanf("%d", &weight);
        node *pnod1 = *head;
        int flag2 = 0;
        while (pnod1)
         {
            if (pnod1->node_num == dest) 
            {
                flag2 = 1;
                break;
            }
            pnod1 = pnod1->next;
        }
        if (flag2) 
        {
            edge_data = NewEdge(weight, pnod1);
            if (!edge_data) {
                exit(0);
            }
        }
        else 
        {
            pnod1 = NewNode(dest);
            if (!pnod1)
            {
                exit(0);
            } 
            else 
            {
                node *temp = *head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = pnod1;
            }
            edge_data = NewEdge(weight, pnod1);
            if (!edge_data) 
            {
                exit(0);
            }
        }
        edge *temp = node_data->edges;
        if (!temp) 
        {
            node_data->edges = edge_data;
        } 
        else 
        {
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = edge_data;
        }
    }
}