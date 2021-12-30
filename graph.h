#ifndef GRAPH_
#define GRAPH_

typedef struct NODE_ *pnode;

typedef struct edge_ {
    int weight;
    int src;
    int dest;
    struct edge_ *next;
} edge, *pedge;


typedef struct NODE_ {
    int id;
    struct NODE_ *next;
} node, *pnode;

typedef struct graph_ {
    pedge edges;
    pnode nodes;
} graph, *pgraph;

void deleteGraph_cmd(pgraph g);
void delete_node_cmd(pgraph g, int id);
void delete_edge_cmd(pgraph g, int src, int dest);
void insert_node_cmd(int id, pgraph g);
void insert_edge_cmd(int src, int dest, int weight, pgraph g);
void delete_edges_by_one_par(int id, pgraph g);
void printGraph_cmd(pgraph g); //for self debug
int char_to_int(char c);




void shortsPath_cmd();
void TSP_cmd();

#endif
