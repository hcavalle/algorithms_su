/*
 * =====================================================================================
 *
 *       Filename:  graph.h
 *
 *    Description:  adjacency list directed graph implementation for computing strongly connected components
 *
 *        Version:  1.0
 *        Created:  02/23/2015 06:45:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <utility>

using namespace std;

struct Edge {
  int v;
  int vv;
};

struct Vertex {
  Vertex(int v) : index(v),explored(0),finish_time(0),leader(0){}
  Vertex(){}
  int index;
  bool explored;
  int finish_time;  
  int leader;
};

class Graph {
  private:
    int _n;
    int _m;

  public:
    Graph();
    Graph(int n, int m);
    void reverse();
    void findVertice();
    void findEdge();
    void addEdge(Edge e);
    void addEdge(int v, int vv);

    void addVertex(Vertex v);
    void addVertex(int v);
    bool vertexExplored(int index);
    void setVertexExplored(int index);
    void vertexLeader(int i, int leader);
    void setFinish(int node, int time);
    void nodesToFinishTimes(map<int, Vertex> ft);

    void n(int n);
    void m(int n);
    int n();
    int m();
    int max();
    /*  void n++();
    void m++(); */
    void readFromFile(const char file[]);
    
    void print();
    void clear();

    map<int, Vertex> vertices;
    multimap<int, int> edges;
    multimap<int, int> rev_edges;
    map<int, Vertex> finish_times;
    priority_queue<int> finish_times_queue;
    map<int, int> leaders;
};


#endif
