/**
 * in this project we will implement a graph using adjacency matrix
 * ecording to the README.md file we will implement the graph class and
 * relevant algorithms. the hole project will be test driven development refer
 * to the README.md file and the test files
 *
 * Author: Hagay Cohen :*****6180
 * Email: hagaycohen2@gmail.com
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Algorithms.hpp"
#include "Graph.hpp"
#include "doctest.h"

using namespace std;
using namespace hagay;

TEST_CASE("Test isConnected") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test shortestPath") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->2->3->4");
    CHECK(Algorithms::shortestPath(g, 2, 2) == "2");

    vector<vector<int>> graph4 = {
        {0, -1, 0, 0},
        {0, 0, 0, 0},
        {0, -2, 0, 3},
        {-7, 1, 0, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 2, 1) == "2->3->0->1");
    CHECK(Algorithms::shortestPath(g, 0, 2) == "-1");

    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(Algorithms::shortestPath(g, 0, 5) == "The graph has a negative cycle");
}
TEST_CASE("Test isContainsCycle") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
}

TEST_CASE("Test isBipartite") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 = {
        {0, 1, 0, -6, 0, 17, 0, -1, 0, 4, 0},
        {1, 0, 2, 0, -9, 0, 1, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 8, 0, 0, 0, -11, 0},
        {-6, 0, 0, 0, -3, 0, 0, 0, 9, 0, -4},
        {0, -9, 0, -3, 0, 9, 0, 0, 0, -2, 0},
        {17, 0, 8, 0, 9, 0, 3, 0, 0, 0, 88},
        {0, 1, 0, 0, 0, 3, 0, -7, 0, 66, 0},
        {-1, 0, 0, 0, 0, 0, -7, 0, 9, 0, 0},
        {0, 0, 0, 9, 0, 0, 0, 9, 0, -7, 0},
        {4, 0, -11, 0, -2, 0, 66, 0, -7, 0, 8},
        {0, 0, 0, -4, 0, 88, 0, 0, 0, 8, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4, 6, 8, 10}, B={1, 3, 5, 7, 9}");

    vector<vector<int>> graph5 = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2, 3, 4, 5, 6}, B={}");

    vector<vector<int>> graph6 = {
        {0, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph6);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 6}, B={1, 2, 3, 4, 5}");
}

TEST_CASE("Test negativeCycle") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph2 = {// negative edges but cycle is not negative
                                  {0, 1, -3, 0, 0},
                                  {0, 0, 0, 2, 0},
                                  {0, 0, 0, 0, 3},
                                  {0, -1, 0, 0, 0},
                                  {0, 0, 0, -2, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::negativeCycle(g) == "The negative cycle is: 0->1->2->3->4->5->0");

    vector<vector<int>> graph4 = {
        {0, 1, -1, 2, -2, 3},
        {-3, 0, 4, -4, 5, -5},
        {1, -1, 0, 2, -2, 3},
        {-3, 1, -1, 0, 2, -2},
        {3, -3, 1, -1, 0, 2},
        {-2, 3, -3, 1, -1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::negativeCycle(g) == "The negative cycle is: 0->3->5->0");
}

TEST_CASE("Test invalid graph") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0, 0},
        {1, 1, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    CHECK_THROWS(g.loadGraph(graph2));

    vector<vector<int>> graph3 = {
        {
            0,
            1,
        }};
    CHECK_THROWS(g.loadGraph(graph3));
}
