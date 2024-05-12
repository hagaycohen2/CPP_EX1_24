/**
 * in this project we will implement a graph using adjacency matrix
 * ecording to the README.md file we will implement the graph class and
 * relevant algorithms. the hole project will be test driven development refer
 * to the README.md file and the test files
 *
 * Author: Hagay Cohen : 206846180
 * Email: hagaycohen2@gmail.com
 */

#include "Graph.hpp"

#include <iostream>

using namespace std;
using namespace hagay;

// constructor
Graph::Graph() {
    this->vertices = 0;
    this->edges = 0;
};

/**
 * initialize the graph with the given matrix
 * if number of rows and columns are not equal the function will throw an
 * exception if the matrix is not symmetric and the graph was initialized as
 * undirected the function will throw an exception if the diagonal of the matrix
 * is not zero the function will throw an exception
 * */
void Graph::loadGraph(vector<vector<int>> graph) {
    for (size_t i = 0; i < graph.size(); i++) {
        if (graph.size() != graph[i].size()) {
            throw invalid_argument("The graph matrix is invalid");
        }
    }
    this->matrix = graph;
    this->vertices = graph.size();
    this->edges = 0;
    for (size_t i = 0; i < graph.size(); i++) {
        for (size_t j = 0; j < graph[i].size(); j++) {
            if (i == j) {
                if (graph[i][j] != 0) {
                    throw invalid_argument("The graph matrix is invalid");
                }
            }
            if (graph[i][j] != 0) {
                this->edges++;
            }
        }
    }
}
void Graph::printGraph() {
    cout << "Graph with " << this->vertices << " vertices and " << this->edges
         << " edges." << endl;
    for (size_t i = 0; i < this->matrix.size(); i++) {
        for (size_t j = 0; j < this->matrix[i].size(); j++) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> Graph::getMatrix() { return this->matrix; }

size_t Graph::getVertices() { return this->vertices; }
