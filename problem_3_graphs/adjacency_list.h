/*
 * =====================================================================================
 *
 *       Filename:  adjacency_list.h
 *
 *    Description:  header for adjacency list implementation
 *
 *        Version:  1.0
 *        Created:  02/09/2015 05:11:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef AJ_H
#define AJ_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Edge {
  Edge() : w(0){}
  int v;
  int vv;
  int w;
  //bool d;
};

/*struct Vertex {
  int vid;
  vector <Edge> ie; 
}

struct adjList {
  vector <Vertex> v; 
}
*/

class Graph {
  private:
    int n; //node count
    int m;
    //struct adjList graph;
    std::map< int, multimap <int,int> > adj_list;
    //could make tuple for direction and weight
    //vector< map <int,int> > adj_list;

  public:
    Graph(int n);
    int numVertices();
    void addEdge(Edge e);
    void removeEdge(Edge e);
    void edgeContract(Edge e);
    void randEdgeContract();
    void printGraph();
    void clearGraph();
    int minCut();
    multimap<int, int>::iterator findEdge(int v, int vv);
    void readEdgesFromFile(const char filename[]);
    //map<int, std::tuple>::iterator findEdge(int v, int vv);
};

#endif
