#include "Graph.hpp"

Graph::Graph() : size(0) {}

std::ostream& operator<<(std::ostream& o, Graph const& graph) {
    o << "Graph size: " << graph.size << std::endl;
    o << "TODO" << std::endl;
    return o;
}
