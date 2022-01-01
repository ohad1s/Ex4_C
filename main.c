#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    printf("Hello World\n");
//    Queue *q=queue_alloc();
//    queue_insert_first(q,1);
//    queue_insert_first(q,2);
//    queue_insert_first(q,3);
//    queue_print(q);
//    queue_pop_last(q);
//    queue_print(q);
//    queue_pop_last(q);
//    queue_print(q);
//    queue_pop_last(q);
//    queue_print(q);




    graph *my_graph = graph_alloc();

    graph_insertFirst_node(my_graph, 0);
    graph_insertFirst_node(my_graph, 1);
//    graph_insertFirst_node(my_graph, 2);
//    graph_insertFirst_node(my_graph, 3);
    graph_insertFirst_edge(my_graph, 0, 1, 5);
//    graph_insertFirst_edge(my_graph, 2, 0, 4);
//    graph_insertFirst_edge(my_graph, 0, 3, 3);
//    graph_insertFirst_edge(my_graph, 2, 1, 1);
//    graph_insertFirst_edge(my_graph, 1, 0, 2);
//    graph_insertFirst_edge(my_graph, 1, 3, 7);
    graph_print(my_graph);

    int s_p = shortestPathDist(my_graph, 0, 1);
    printf("\nbdika  %d\n", s_p);

//    char c;
//    scanf("%c", &c);
//    while (c != '\0') {
//        graph_print(my_graph);
//        if (c == 'A') {
//            graph_free_elements(my_graph);
//            int size;
//            scanf("%d", &size);
//            for (int i = 0; i < size; i++) {
//                printf("%d\n", i);
//                graph_insertFirst_node(my_graph, i);
//            }
//            scanf("%c", &c);
//            scanf("%c", &c);
//        }
//
//        while (c == 'n') {
//            printf("%c\n", c);
//            int id;
//            scanf("%d", &id);
//            printf("%d\n", id);
//            int dest, weight;
//            scanf("%c", &c);
//            printf("%c\n", c);
//            scanf("%c", &c);
//            printf("%c\n", c);
//            while (char_to_int(c) < 10 && char_to_int(c) > -1) {
//                printf("pair_pair\n");
//                printf("%c\n", c);
//                dest = char_to_int(c);
//                scanf("%d", &weight);
//                printf("%d\n", weight);
//                graph_insertFirst_edge(my_graph, id, dest, weight);
//                scanf("%c", &c);
//                scanf("%c", &c);
//            }
//        }
//
//        if (c == 'B') {
//            int id;
//            scanf("%d", &id);
//            if (!is_in(my_graph, id)) {
//                graph_insertFirst_node(my_graph, id);
//            } else {
//                free_edge_by_src(my_graph, id);
//            }
//            int dest, weight;
//            scanf("%c", &c);
//            scanf("%c", &c);
//            while (char_to_int(c) < 10 && char_to_int(c) > -1) {
//                dest = char_to_int(c);
//                scanf("%d", &weight);
//                printf("%d\n", weight);
//                graph_insertFirst_edge(my_graph, id, dest, weight);
//                scanf("%c", &c);
//                scanf("%c", &c);
//            }
//
//        }
//        if (c == 'D') {
//            int id;
//            scanf("%d", &id);
//            free_node_by_id(my_graph, id);
//            free_edge_by_id(my_graph, id);
//        }
//        if (c == 'S') {
//            int src, dest;
//            scanf("%d", &src);
//            scanf("%d", &dest);
//            int ShortestPath = shortestPathDist(my_graph, src, dest);
//            printf("ShortestPath:%d\n", ShortestPath);
//        }
//        scanf("%c", &c);
//        graph_print(my_graph);
//    }
    return 0;
}

