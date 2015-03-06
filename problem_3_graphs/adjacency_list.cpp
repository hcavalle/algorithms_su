/*
 * =====================================================================================
 *
 *       Filename:  adjacency_list.cpp
 *
 *    Description:  implementation of an adjacency list
 *
 *        Version:  1.0
 *        Created:  02/08/2015 08:53:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero
 *   Organization:  
 *
 * =====================================================================================
 */

#include "adjacency_list.h"
/*  #include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
*/

/* Graph class functions */
Graph::Graph(int nc) {
 //multimap <int, int> element; 
 //adj_list.assign(nc, element);
 n = nc;
 m = 0;

}


//add edge
void Graph::addEdge(Edge e) {
 adj_list[e.v].insert(make_pair(e.vv,e.w)); 
 //adj_list[e.vv].insert(make_pair(e.v,e.w)); 
 m++;
}

int Graph::numVertices() {
  return adj_list.size();
}

void Graph::removeEdge(Edge e) {
  adj_list[e.v].erase(e.vv);
  adj_list[e.vv].erase(e.v);
  m--;
}

void Graph::edgeContract(Edge e) {
  //remove self loops pre-emptively from e.v from e.vv
  while (adj_list[e.vv].find(e.v) != adj_list[e.vv].end()) {
    adj_list[e.vv].erase(adj_list[e.vv].find(e.v));
    m--;
  }
  while (adj_list[e.vv].find(e.vv) != adj_list[e.vv].end()) {
    adj_list[e.vv].erase(adj_list[e.vv].find(e.vv));
    m--;
  }

  //contract v into vv
  //also need to update all other records to change vv to v
  //iterate over adj_list[e.vv] multimap, update all edges from vv to v; erase(vv) and insert(v)
  //for (multimap< int, int >::iterator m_it = adj_list[e.vv].begin(); !adj_list[e.vv].empty(); m_it++){
  while( !adj_list[e.vv].empty() ) {
    multimap< int, int >::iterator m_it = adj_list[e.vv].begin();  
    if (m_it == adj_list[e.vv].end() ) {
      break;
    }

    int ie = m_it->first;

    try {
      adj_list[ie].erase(e.vv);
      adj_list[ie].insert(make_pair(e.v,e.w));
      //add function to get edge, given v and vv insert ie e.v and e.w
      int w = 0;
      adj_list[e.v].insert(make_pair(ie, w));
      adj_list[e.vv].erase(m_it);
    }
    catch(...) {
      cout<<"out of range exception"<<endl;
    }
  }
  //}

  //erase vertex vv
    adj_list[e.v].erase(e.vv);
    adj_list.erase(e.vv);
    //adj_list[e.vv].clear();
    //n--;

  //point edge from v to E to vv
  //if v==vv, remove edge
  
}

void Graph::randEdgeContract() {
  //find random edge (u,v)
  //random index in vector of multimaps (v)
  int rand_index = rand() % adj_list.size();
  map< int,multimap<int,int> >::iterator v_it = adj_list.begin();
  std::advance(v_it, rand_index);
  
  //random index in multimap (vv)
  rand_index = rand() % v_it->second.size();
  multimap<int,int>::iterator vv_it = v_it->second.begin();
  std::advance(vv_it, rand_index); 
  
  int v = v_it->first;
  int vv = vv_it->first;
  
  Edge e;
  e.v = v;
  e.vv = vv;

  edgeContract(e);
}

void Graph::printGraph() {
  for (map< int, multimap<int, int> >::iterator it = adj_list.begin(); it !=adj_list.end(); it++) {
    cout<<"graph node["<<it->first<<"]: ";
    for (multimap <int,int>::iterator mm_it = it->second.begin(); mm_it != it->second.end(); mm_it++){
      cout<<mm_it->first<<endl;
    }
  } 
}

int Graph::minCut(){
  int count = 0;

  while (numVertices() > 2) {
    //iteratively call randContract
    randEdgeContract();
    //cout << graph.numVertices();
  }
  count = adj_list.begin()->second.size();
  return count;

  for (map< int, multimap<int, int> >::iterator it = adj_list.begin(); it !=adj_list.end(); it++) {
    for (multimap <int,int>::iterator mm_it = it->second.begin(); mm_it != it->second.end(); mm_it++){
      count++;
    }
  } 
  return count/2;
}

void Graph::clearGraph() {
  adj_list.clear();
}

void Graph::readEdgesFromFile(const char filename[]){
  ifstream infile(filename); 
  clearGraph();

  if (!infile.is_open()) {
    cout<<"problem reading file..."<<endl;
    exit(1);
  }

  int temp_v;
  int temp_vv;
  Edge e;
  string line;
  
  while (std::getline(infile, line)){
    //read from file into array
    std::istringstream int_line(line);
    if (int_line >> temp_v) {
      e.v = temp_v;
      while( !int_line.eof() ) {
        int_line >> temp_vv;
        e.vv = temp_vv;
        addEdge(e);
      }//end while int_line tempvv
    }//end if int_line tempv
  }//end while infile, line
}//end readEdgeFromFile

/* multimap<int, int>::iterator findEdge(int v, int vv) {
  return 0;  
}*/


