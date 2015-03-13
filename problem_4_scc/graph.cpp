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

Graph::Graph(){
  _n=0;
  _m=0;
}


Graph::Graph(int n=0, int m=0) {
  _n = n;
  _m = m;
}

void Graph::reverse() {
  //reverse all values in edges
  multimap<int,int>rev_edges;
  for (multimap<int,int>::iterator it = edges.begin(); it != edges.end(); it++) {
    //swap(it->first, it->second);
    rev_edges.insert(std::make_pair(it->second, it->first));
    //edges.erase(it);
  } 
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
  _m++;
}

void Graph::addVertex (int v) {
  //first check if exists
  if ( vertices.find(v) != vertices.end() ) {
    return;
  }

  Vertex vertex(v);
  vertices.insert(std::make_pair(vertex.index, vertex));
  _n++;
}

void Graph::addVertex (Vertex v) {
  if ( vertices.find(v.index) != vertices.end() ) {
    return;
  }

  vertices.insert(std::make_pair(v.index, v));
  _n++;
}

bool Graph::vertexExplored(int i) {
  return vertices[i].explored;
}

void Graph::setVertexExplored(int i) {
  vertices[i].explored =  vertices[i].explored ? false : true; 
}

void Graph::vertexLeader(int i, int leader) {
  vertices[i].leader = leader;
}

void Graph::setFinish(int i, int time) {
  vertices[i].finish_time = time;
  finish_times.insert(make_pair(time,vertices[i]));
  finish_times_queue.push(time);
}

void Graph::nodesToFinishTimes(map<int, Vertex> ft) {
  vertices = ft;
}

void Graph::n(int n) {
  _n = n;
}

void Graph::m(int m) {
  _m = m;
}

int Graph::n() {
  return _n;
}

int Graph::m() {
  return _m;
}

int Graph::max() {
  if (finish_times_queue.empty())
    return this->n();

  int top = finish_times_queue.top();
  finish_times_queue.pop();
  return top;
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

