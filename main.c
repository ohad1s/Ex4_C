#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    graph * my_graph=graph_alloc();
    char c;
    while (scanf("%c",&c)!='\0'){
        if (c=='A') {
//            deleteGraph_cmd(my_graph);
            int size;
            scanf("%d", &size);
            for (int i = 0; i < size; i++) {
                graph_insertFirst_node(my_graph,i);
                scanf("%c", &c);
                scanf("%c", &c);
            }
        }

        while(c=='n'){
            int id;
                scanf("%d", &id);
            int dest,weight;
            scanf("%c", &c);
            scanf("%c", &c);
            while (char_to_int(c)<10 && char_to_int(c)>-1) {
                dest= char_to_int(c);
                scanf("%d", &weight);
                graph_insertFirst_edge(my_graph,id,dest,weight);
                scanf("%c", &c);
                scanf("%c", &c);
            }
        }
    }
    graph_print(my_graph);
//    printGraph_cmd(my_graph);
//    deleteGraph_cmd(my_graph);
//    free(my_graph);
    return 0;
}

