//
// Created by blackgeorge on 3/8/19.
//

#include <vector>

#ifndef CLRS_ADJ_LIST_H
#define CLRS_ADJ_LIST_H

class Vertex {
protected:
    char n;
    std::vector<std::pair<Vertex, int>> adj;
public:
    Vertex(): n{'0'}, adj{} {};
    explicit Vertex(char c): n{c}, adj{} {};
    ~Vertex() = default;

    char name() const { return n; }
    std::vector<std::pair<Vertex, int>> adjacents() { return adj; }

    void add_edge(const Vertex& v, int w);
    void add_edge_u(Vertex& v, int w);
    void print_adj() const;
};

std::ostream& operator<<(std::ostream& os, const Vertex& u);

class Graph {
    std::vector<Vertex> vv;
public:
    Graph() = default;

    std::vector<Vertex> const vertices() { return vv; }

    void add_vertex(const Vertex& v) { vv.push_back(v); }
    void print_vertices() const;
};

enum class Color { white, grey, black };

class BFS_Vertex: public Vertex {
    Color col;
    int dist;
    char pred;
public:
    BFS_Vertex(): col{Color::white}, dist{0}, pred{} {};
    BFS_Vertex(char c);

    Color color() const { return col; }
    void set_col(Color c) { col = c; }
    int distance() const { return dist; }
    void set_dist(int d) { dist = d; }
    char predecessor() const { return pred; }
    void set_pred(char p) { pred = p; }

    void print_adj() const;
};

std::ostream& operator<<(std::ostream& os, const BFS_Vertex& u);

#endif //CLRS_ADJ_LIST_H
