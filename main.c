#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    graph *my_graph = graph_alloc();
    char c;
    scanf("%c", &c);
    while (c != '\0') {
        graph_print(my_graph);
        if (c == 'A') {
            graph_free_elements(my_graph);
            int size;
            scanf("%d", &size);
            for (int i = 0; i < size; i++) {
                printf("%d\n", i);
                graph_insertFirst_node(my_graph, i);
            }
            scanf("%c", &c);
            scanf("%c", &c);
        }

        while (c == 'n') {
            printf("%c\n", c);
            int id;
            scanf("%d", &id);
            printf("%d\n", id);
            int dest, weight;
            scanf("%c", &c);
            printf("%c\n", c);
            scanf("%c", &c);
            printf("%c\n", c);
            while (char_to_int(c) < 10 && char_to_int(c) > -1) {
                printf("pair_pair\n");
                printf("%c\n", c);
                dest = char_to_int(c);
                scanf("%d", &weight);
                printf("%d\n", weight);
                graph_insertFirst_edge(my_graph, id, dest, weight);
                scanf("%c", &c);
                scanf("%c", &c);
            }
        }

        if (c == 'B') {
            int id;
            scanf("%d", &id);
            if (!is_in(my_graph, id)) {
                graph_insertFirst_node(my_graph, id);
            } else {
                free_edge_by_src(my_graph, id);
            }
            int dest, weight;
            scanf("%c", &c);
            scanf("%c", &c);
            while (char_to_int(c) < 10 && char_to_int(c) > -1) {
                dest = char_to_int(c);
                scanf("%d", &weight);
                printf("%d\n", weight);
                graph_insertFirst_edge(my_graph, id, dest, weight);
                scanf("%c", &c);
                scanf("%c", &c);
            }

        }
        if (c == 'D') {
            int id;
            scanf("%d", &id);
            free_node_by_id(my_graph, id);
            free_edge_by_id(my_graph, id);

        }
        scanf("%c", &c);
//        graph_print(my_graph);
    }
    return 0;
}

