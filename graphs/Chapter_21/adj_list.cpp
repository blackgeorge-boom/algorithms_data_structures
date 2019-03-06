//
// Created by blackgeorge on 3/6/19.
//

#include <iostream>
#include <vector>

class Vertex {
    char n;
    std::vector<std::pair<Vertex, int>> adj;
public:
    Vertex(): n{'0'}, adj{} {};
    explicit Vertex(char c): n{c}, adj{} {};
    ~Vertex() = default;

    char name() const { return n; }
    std::vector<std::pair<Vertex, int>> const adjacents() const { return adj; }

    void add_edge(const Vertex& v, int w);
    void add_edge_u(Vertex& v, int w);
    void print_adj() const;
};

std::ostream& operator<<(std::ostream& os, const Vertex& u)
{
    return os << "{\'" << u.name() << "\'} \n";
}

void Vertex::print_adj() const {
    Vertex v;
    int w;
    std::cout << "Neighbors of " << n << ": \n";
    for (auto& i : adj) {
        v = i.first;
        w = i.second;
        std::cout << "(" << v.name() << ", " << w << ") ";
    }
    std::cout << '\n';
}

void Vertex::add_edge(const Vertex& v, int w) {
    std::pair<Vertex, int> edge {v, w};
    adj.push_back(edge);
}

void Vertex::add_edge_u(Vertex& v, int w) {
    std::pair<Vertex, int> edge {v, w};
    adj.push_back(edge);
    v.add_edge(*this, w);
}

class Graph {
    std::vector<Vertex> vv;
public:
    Graph() = default;

    std::vector<Vertex> const vertices() { return vv; }

    void add_vertex(const Vertex& v) { vv.push_back(v); }
    void print_vertices() const;
};

void Graph::print_vertices() const {
    for (auto& i : vv) i.print_adj();
}

Graph reverse_graph(Graph& g) {
    Graph rev_g;
    for (auto& u : g.vertices())
        rev_g.add_vertex(Vertex(u.name()));
    for (auto& u : g.vertices()) {
        for (auto& v : u.adjacents()) {

        }
    }
}

int main() {
    Vertex u {'u'};
    Vertex v {'v'};

    std::cout << u;
    u.add_edge_u(v, 3);
    u.print_adj();
    v.print_adj();

    Graph g;
    g.add_vertex(u);
    g.add_vertex(v);
    g.print_vertices();

}
