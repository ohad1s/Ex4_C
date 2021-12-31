#ifndef GRAPH_
#define GRAPH_

struct _graph;
typedef struct _graph graph;

typedef struct _node {
    int id;
    struct _node *_next;
} Node;

typedef struct _edge {
    int src;
    int dest;
    int weight;
    struct _edge *_next;
} Edge;


struct _graph {
    Node *_head_node;
    Edge *_head_edge;
    int _size;
};

Node *Node_alloc(int data, Node *next);

Edge *Edge_alloc(int src, int dest, int weight, Edge *next);

graph *graph_alloc();

void Node_free(Node *node);

void Edge_free(Edge *edge);

void graph_free_elements(graph *graph);

void graph_insertFirst_node(graph *graph, int data);

void graph_print(const graph *g);

void graph_insertFirst_edge(graph *graph, int src, int dest, int weight);

int char_to_int(char c);

int is_in(graph *g, int id);

void free_edge_by_src(graph *g, int src);

void free_node_by_id(graph *g, int id);

void free_edge_by_id(graph *g, int id);










//typedef struct NODE_ *pnode;
//
//typedef struct edge_ {
//    int weight;
//    int src;
//    int dest;
//    struct edge_ *next;
//} edge, *pedge;
//
//
//typedef struct NODE_ {
//    int id;
//    struct NODE_ *next;
//} node, *pnode;
//
//typedef struct graph_ {
//    pedge edges;
//    pnode nodes;
//} graph, *pgraph;
//
//void deleteGraph_cmd(pgraph g);
//void delete_node_cmd(pgraph g, int id);
//void delete_edge_cmd(pgraph g, int src, int dest);
//void insert_node_cmd(int id, pgraph g);
//void insert_edge_cmd(int src, int dest, int weight, pgraph g);
//void delete_edges_by_one_par(int id, pgraph g);
//void printGraph_cmd(pgraph g); //for self debug
//int char_to_int(char c);
//
//
//
//
//void shortsPath_cmd();
//void TSP_cmd();

#endif
