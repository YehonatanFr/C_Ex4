#include <stdio.h>
#include "graph.h"

void build_graph_cmd(pnode *head)
{

}

int main()
{
    int numNode = 0;
    pnode *Head = NULL;
    char choice;

    while(scanf("%c",&choice)!=EOF)
    {
        if(choice=='A')
        {
            scanf("%d",&numNode);
            *Head = CreateLinkedList(numNode);  

            // deleteGraph_cmd(head);
            // build_graph_cmd(head);
        }

    }
    

    

    return 0;
}