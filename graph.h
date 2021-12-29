#ifndef GRAPH_
#define GRAPH_

typedef struct NODE_ *pnode;

typedef struct edge_ {
    int weight;
    int endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct NODE_ {
    int node_num;
    pedge edges;
    struct NODE_ *next;
} node, *pnode;

typedef struct graph_ {
    int sum;
    pnode start;
} graph, *pgraph;

void build_graph_cmd(pgraph g, int sum, int to_add,int arr_nodes[]);
void insert_node_cmd(pgraph g, int id, int sum_edges,int arr_edges[]);
void delete_node_cmd(int id,pgraph g);
void insert_edge_cmd(int weight, int endpoint, pedge edges);
void deleteGraph_cmd(pgraph g);
void printGraph_cmd(graph g); //for self debug
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
