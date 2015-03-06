/*
 * =====================================================================================
 *
 *       Filename:  graph.cpp
 *
 *    Description:  implementation of graph adjecency list for calculating sccs
 *
 *        Version:  1.0
 *        Created:  02/23/2015 07:05:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "graph.h"

Graph::Graph() {
  n = 0;
  m = 0;
}

void Graph::reverse() {
  //reverse all values in edges
  multimap<int,int>rev_edges;
  for (multimap<int,int>::iterator it = edges.begin(); it != edges.end(); it++) {
    //swap(it->first, it->second);
    rev_edges.insert(std::make_pair(it->second, it->first));
    //edges.erase(it);
  } 
  edges = rev_edges;
}

void Graph::print() {

}

void Graph::clear() {
  edges.clear();
  vertices.clear();
}

/*  Edge findEdgesByVertex(int v){
  
}*/

void Graph::addEdge(Edge e) {
  edges.insert(make_pair(e.v, e.vv));
  m++;
}

void Graph::addVertex (int v) {
  //first check if exists
  if ( vertices.find(v) != vertices.end() ) {
    return;
  }

  Vertex vertex(v);
  vertices.insert(std::pair<int, pair<int,bool> > (vertex.index, vertex.properties ));
  n++;
}

void Graph::addVertex (Vertex v) {
  if ( vertices.find(v.index) != vertices.end() ) {
    return;
  }

  vertices.insert(std::pair<int, pair<int,bool> > (v.index, v.properties ));
  n++;
}

void Graph::set_n(int _n) {
  n = _n;
}


void Graph::set_m(int _m) {
  m = _m;
}
/* /
void Graph::m++() {
  m++;
}
void Graph::n++() {
  n++;
}
*/
void Graph::readFromFile(const char filename[]){
  ifstream infile(filename); 
  clear();

  if (!infile.is_open()) {
    cout<<"problem reading file..."<<endl;
    exit(1);
  }

  int tail;
  int head;
  Edge e;
  string line;

  while (std::getline(infile, line)){
    std::istringstream int_line(line);
    if (int_line >> tail) {
      e.v = tail;
      addVertex(tail);
      if( int_line >> head ) {
        e.vv = head;
        addEdge(e);
        addVertex(head);
      }//end while int_line tempvv
    }//end if int_line tempv
  }//end while infile, line
}//end readEdgeFromFile
