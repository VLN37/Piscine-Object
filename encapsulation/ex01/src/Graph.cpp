#include "Graph.hpp"

Graph::Graph() : size(0), height(0), length(0) {}

Graph::Graph(std::string filename) : size(0), height(0), length(0) {
    std::ifstream     file(filename.c_str());
    std::stringstream ss;
    std::string       line;
    float             x;
    float             y;

    while (std::getline(file, line)) {
        std::cout << "line: " << line << "\n";
        int space = line.find(' ');
        std::cout << "|" << line.substr(0, space) << "|\n";
        ss << line.substr(0, space);
        ss >> x;
        ss.clear();
        ss.str("");
        std::cout << "|" << line.substr(space + 1) << "|\n";
        ss << line.substr(space + 1);
        ss >> y;
        ss.clear();
        ss.str("");
        std::cout << "x: " << x << " y: " << y << "\n";
        this->add_point(x, y);
    }
    std::cout << std::endl;
}

void Graph::add_point(float x, float y) {
    this->update_size(x, y);
    this->points.push_back(Vector2(x, y));
}

void Graph::add_point(Vector2 const& point) {
    this->update_size(point.x, point.y);
    this->points.push_back(point);
}

void Graph::update_size(float x, float y) {
    if (x + 1 > this->length) this->length = x + 1;
    if (y + 1 > this->height) this->height = y + 1;
    this->size = this->height * this->length;
}

std::ostream& operator<<(std::ostream& o, Graph const& graph) {
    if (graph.points.size() == 0) {
        o << "Empty graph.\n";
        return o;
    }
    o << "Graph size: " << graph.size << std::endl;
    std::vector<std::string> matrix;
    matrix.resize(graph.length);

    // empty the matrix
    std::vector<std::string>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); ++it) {
        for (size_t i = 0; i < graph.length; i++) it->append(" .");
    }

    // fill the points
    std::vector<Vector2>::const_iterator it2;
    for (it2 = graph.points.begin(); it2 != graph.points.end(); ++it2)
        matrix[it2->x][(it2->y * 2) + 1] = 'x';

    // output
    std::reverse(matrix.begin(), matrix.end());
    for (size_t i = 0; i < matrix.size(); ++i) {
        o << ">& " << std::setw(3) << matrix.size() - i - 1 << matrix[i] << std::endl;
    }
    o << ">&    ";
    for (size_t i = 0; i < graph.length; ++i) o << " " << i;
    o << std::endl;
    return o;
}
