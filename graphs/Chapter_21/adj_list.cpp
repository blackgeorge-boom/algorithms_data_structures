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
    std::vector<std::pair<Vertex, int>> const adjacents() { return adj; }

    void add_edge(Vertex v, int w);
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

void Vertex::add_edge(Vertex v, int w) {
    std::pair<Vertex, int> edge1 {v, w};
    adj.push_back(edge1);
}

int main() {
    Vertex u {'u'};
    Vertex v {'v'};

    std::cout << u;
    u.add_edge(v, 3);
    u.print_adj();
    v.print_adj();

}
