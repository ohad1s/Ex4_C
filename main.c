#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    graph * my_graph=graph_alloc();
    graph_insertFirst_node(my_graph,0);
    graph_insertFirst_node(my_graph,1);
    graph_insertFirst_node(my_graph,2);
    graph_insertFirst_node(my_graph,3);
    graph_insertFirst_edge(my_graph,0,2,2);
    graph_insertFirst_edge(my_graph,1,3,3);
    graph_insertFirst_edge(my_graph,2,1,7);
    graph_insertFirst_edge(my_graph,3,0,21);
    graph_insertFirst_edge(my_graph,0,1,28);
    graph_insertFirst_edge(my_graph,1,2,9);
    graph_print(my_graph);


//    pgraph my_graph = (graph *) malloc(sizeof(graph));
//    my_graph->edges=NULL;
//    my_graph->nodes=NULL;
//    insert_node_cmd(0,my_graph);
//    insert_node_cmd(1,my_graph);
//    insert_node_cmd(2,my_graph);
//    insert_node_cmd(3,my_graph);
//    insert_edge_cmd(1,2,5,my_graph);
//    insert_edge_cmd(2,1,3,my_graph);
//    insert_edge_cmd(3,0,4,my_graph);
//    insert_edge_cmd(3,1,1,my_graph);
//    insert_edge_cmd(2,3,2,my_graph);

//    char c;
//    while (scanf("%c",&c)!='\0'){
//        if (c=='A') {
//            deleteGraph_cmd(my_graph);
//            int size;
//            scanf("%d", &size);
//            for (int i = 0; i < size; i++) {
//                insert_node_cmd(i, my_graph);
//                scanf("%c", &c);
//                scanf("%c", &c);
//            }
//        }
//
//        while(c=='n'){
//            int id;
//                scanf("%d", &id);
//            int dest,weight;
//            scanf("%c", &c);
//            scanf("%c", &c);
//            while (char_to_int(c)<10 && char_to_int(c)>-1) {
//                dest= char_to_int(c);
//                scanf("%d", &weight);
//                insert_edge_cmd(id,dest,weight,my_graph);
//                scanf("%c", &c);
//                scanf("%c", &c);
//            }
//        }
//    }
//    printGraph_cmd(my_graph);
//    deleteGraph_cmd(my_graph);
//    free(my_graph);
    return 0;
}

