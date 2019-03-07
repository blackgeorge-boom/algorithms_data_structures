//
// Created by blackgeorge on 3/8/19.
//

#include <iostream>

#include "adj_list.h"

int main() {
    Vertex u {'u'};
    Vertex v {'v'};

    std::cout << u << "\n";
    u.add_edge_u(v, 3);
    u.print_adj();
    v.print_adj();

    Graph g;
    g.add_vertex(u);
    g.add_vertex(v);
    g.print_vertices();

    BFS_Vertex x {'x'};
    BFS_Vertex y {'y'};
    std::cout << x << "\n";
    x.add_edge_u(y, 4);
    x.print_adj();

    Graph bfs_g;
    bfs_g.add_vertex(x);
    bfs_g.add_vertex(y);
    bfs_g.print_vertices();
}
