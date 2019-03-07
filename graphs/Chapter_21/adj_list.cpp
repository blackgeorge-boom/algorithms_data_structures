//
// Created by blackgeorge on 3/6/19.
//

#include <iostream>
#include <vector>
#include <boost/range/combine.hpp>
#include <boost/tuple/tuple.hpp>

#include "adj_list.h"

/*
 * Implementation of Vertex class methods
 */

void Vertex::print_adj() const {
    Vertex v;
    int w;
    std::cout << "Neighbors of " << n << ": \n";
    for (auto& i : adj) {
        v = i.first;
        w = i.second;
        std::cout << "(" << v << ", " << w << ") ";
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

std::ostream& operator<<(std::ostream& os, const Vertex& u)
{
    return os << u.name();
}

/*
 * Implementation of Graph class methods
 */

void Graph::print_vertices() const {
    for (auto& i : vv) i.print_adj();
}

// TODO:
/*
void reverse_graph(Graph& g) {
    Graph rev_g;
    for (auto& u : g.vertices())
        rev_g.add_vertex(Vertex(u.name()));
}

void mult_to_undir(Graph& g) {
    auto vert_num = g.vertices().size();
    int A[vert_num];
    for (auto& u : g.vertices()) {
        for (auto i = 0; i < u.adjacents().size(); i++) {
            if (u.name() == u.adjacents()[i].first.name())
                u.adjacents().erase(u.adjacents().begin() + i);
        }
    }
}
*/

BFS_Vertex::BFS_Vertex(char c) : Vertex(c) {
    col = Color::white;
    dist = 0;
    pred = '0';
}

void BFS_Vertex::print_adj() const {
    BFS_Vertex v;
    int w;
    std::cout << "Neighbors of " << n << ": \n";
    for (auto& i : adj) {
        v = i.first;
        w = i.second;
        std::cout << "(" << v << ", " << w << ") ";
    }
    std::cout << '\n';
}

std::ostream& operator<<(std::ostream& os, const BFS_Vertex& u)
{
    os << u.name() << ", ";
    switch (u.color()) {
        case Color::white:
            os << "white";
            break;
        case Color::grey:
            os << "GREY";
            break;
        case Color::black:
            os << "BLACK";
            break;
        default:
            os << "Something's wrong";
    }
    return os << ", " << u.distance() << ", " << u.predecessor();
}

