#include "Controller.hpp"

int main()
{
	auto controller = Controller();
	controller.runGame();

	return EXIT_SUCCESS;
}

// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
//#include "Bfs.hpp"
//
//// Driver program to test methods of graph class
//int main()
//{
//    // Create a graph given in the above diagram
//    Graph g(4);
//    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(1, 2);
//    g.addEdge(2, 0);
//    g.addEdge(2, 3);
//    g.addEdge(3, 3);
//
//    cout << "Following is Breadth First Traversal "
//        << "(starting from vertex 2) \n";
//    g.BFS(2);
//
//    return 0;
//}