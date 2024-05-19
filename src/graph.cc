#include<../include/graph.h>


int main() {
    Graph<int, int> graph;

    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);

    graph.add_edge(2, 1, 1);
    graph.add_edge(3, 1, 3);
    graph.add_edge(1, 4, 3);
    graph.add_edge(4, 3, 1);
    graph.add_edge(2, 3, 2);
    graph.add_edge(3, 5, 1);
    graph.add_edge(4, 5, 1);
    graph.add_edge(5, 2, 2);

    auto action = [](const int& v) {
        std::cout << v << " ";
    };

    std::cout << "Test BFS:\n";
    graph.bfs(1, action);
    cout << endl;

    cout << "\nTest dijstra." << endl;
    std::vector<Graph<int, int>::Edge> path = graph.dijkstra(1, 3);
    std::cout << "Shortest path for from 1, to 3:" << std::endl;
    if (path.empty()) {
        std::cout << "No path found." << std::endl;
    }
    else {
        for (const auto& edge : path) {
            std::cout << "From: " << edge.from << " To: " << edge.to << " Distance: " << edge.distance << std::endl;
        }
    }

    cout << "\nFind optimal location." << endl;
    int optimalLocation = graph.find_center();

    cout << "Optimal warehouse location: " << optimalLocation << endl;

    return 0;
}
