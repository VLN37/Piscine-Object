#include <algorithm>
#include <iostream>

#include "Graph.hpp"
#include "Vector2.hpp"

template <typename T>
void out(T const& obj) {
    std::cout << obj;
}

int main(void) {
    std::cout << Graph();
    std::cout << Vector2();

    Graph graph = Graph();
    graph.add_point(4, 4);
    graph.add_point(3, 3);
    graph.add_point(2, 2);
    graph.add_point(1, 1);
    graph.add_point(Vector2(0, 0));

    std::sort(graph.points.begin(), graph.points.end());
    std::for_each(graph.points.begin(), graph.points.end(), out<Vector2>);
    std::cout << graph;
}
