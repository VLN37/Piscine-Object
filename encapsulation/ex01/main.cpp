#include <unistd.h>

#include "Graph.hpp"
#include "Vector2.hpp"

template <typename T>
void out(const T &obj) {
    std::cout << obj;
}

std::string cwd() {
    char buf[200];
    if (getcwd(buf, 200) == NULL) throw std::runtime_error("getcwd");
    return std::string(buf);
}

void simple_graph() {
    std::cout << "SIMPLE GRAPH\n";
    std::cout << Graph();
    std::cout << Vector2();

    Graph graph;
    graph.add_point(4, 4);
    graph.add_point(3, 3);
    graph.add_point(2, 2);
    graph.add_point(1, 1);
    graph.add_point(Vector2(0, 0));

    std::cout << graph;
    std::cout << std::endl;
}

void file_graph() {
    std::string line;
    Graph       graph(cwd().append("/assets/points.txt"));

    std::cout << "FILE GRAPH\n";
    graph.add_point(7, 7);
    std::cout << graph;
    std::cout << std::endl;
}

int main(void) {
    simple_graph();
    file_graph();
}
