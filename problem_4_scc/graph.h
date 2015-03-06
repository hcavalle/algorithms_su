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
  int index;
  bool explored;
  int finish_time;  
  int leader;
  std::pair <bool, int> properties;
};

class Graph {
  private:
    int n;
    int m;

  public:
    Graph();
    void reverse();
    void findVertice();
    void findEdge();
    void addEdge(Edge e);
    void addEdge(int v, int vv);
    void addVertex(Vertex v);
    void addVertex(int v);
    void set_n(int _n);
    void set_m(int _m);
    /*  void n++();
    void m++(); */
    void readFromFile(const char file[]);
    
    void print();
    void clear();

    map<int, pair<bool, int> > vertices;
    multimap<int, int> edges;
};

#endif
