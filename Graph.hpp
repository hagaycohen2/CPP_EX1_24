/**
 * in this project we will implement a graph using adjacency matrix
 * ecording to the README.md file we will implement the graph class and
 * relevant algorithms. the hole project will be test driven development refer
 * to the README.md file and the test files
 *
 * Author: Hagay Cohen : *****6180
 * Email: hagaycohen2@gmail.com
 */
#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace hagay {
class Graph {
   private:
    vector<vector<int>> matrix;
    size_t vertices;
    size_t edges;

   public:
    // constructor
    Graph();

    void loadGraph(vector<vector<int>> graph);
    void printGraph();
    vector<vector<int>> getMatrix();
    size_t getVertices();
};
}  // namespace hagay