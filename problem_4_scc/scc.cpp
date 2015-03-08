/*
 * =====================================================================================
 *
 *       Filename:  scc.cpp
 *
 *    Description:  calculates the size of the 5 largest strongly connected components in a graph, given a text file as input for graph, where each row is an edge and each row has 2 'columns', the vertices
 *        Created:  02/20/2015 03:00:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero 
 *   Organization:  
 *
 * =====================================================================================
 */

//compile with scc_graph.cpp
//  ds for edges: explored bool
//  g_adj_list
//    m = multimap<int, int> //tail = first, head = second
//    v = map<int, map<bool, int> //int = v index, bool = explored/unexplored, int = leader v
//    v_finishing times = array, 0 -> largest, n = smallest
//    /* mv = list of lists list v [list m] */
//
//  scc = array = size of SCCs
//
//
//  operations: traverse edges for vertex
//    g_reverse(g) - reverse arcs of graph
//    dfs-loop(grev, f_times)
//    dfs-loop(g)
//    sub-operations:
//    dfsLoop(grev)
//      // determines finishing time of each V
//      node_max_index - largest index value for nodes
//      nodes_processed - number of nodes processed
//      cur_source_node_index - source node index for current dfs loop iteration
//      dfs(g, v)
//        mark v as explored
//        set leader=s for node
//
//      
//  algorithm (kosaraju):
//    Grev = graph reversed
//    finish times: Run dfs-loop on Grev - compute the 'magical ordering' of nodes, that allows for correct processing start point
//    find sccs: Run dfs-loop on G, from largest finish time to smallest
//      
//dfs implementation

#include "scc.h"

SccComputer::SccComputer(Graph g) {
  cur_leader = g.n();
  cur_finish_time = 0;
}

void SccComputer::dfs(Graph g, int node) {
  //mark as explored
  g.setVertexExplored(node);
  
  //set leader
  g.vertexLeader(node, cur_leader);

  //check each arc recursively
  pair<map<int,int>::iterator, map<int,int>::iterator> arc_range = g.edges.equal_range(node);
  for (map<int,int>::iterator it = arc_range.first; it != arc_range.second; it++){
    int tail = it->second;
    if ( !g.vertexExplored(tail) ) {
      dfs(g, tail);
    }
  } 
  cur_finish_time++;
  //use pass by value accessor
  g.setFinish(node, cur_finish_time);
  
}

void SccComputer::dfsLoop(Graph g) {
  //loop 
  cur_leader = g.n;
  cur_finish_time = 0;

  for (int i = cur_leader; i > 0; i--) {
    if (  !g.vertices[i].vertexExplored() ) {
      cur_leader = i;
      dfs(g,i);
    }
      
  }
  //loop 2
    //with f_times
}

void SccComputer::setMagicNumbers(Graph g) {
  //dfsLoop1
}

void SccComputer::setSccs(Graph g) {

}

void SccComputer::compute(Graph g) {
  Graph reverse(g);

  setMagicNumbers(g);
  setSccs(g);
}

int main(int argc, char **argv) {
  Graph graph;
  //read in from file
  string filename;

  while (true) { 
    cout<<"filename plase: "<<endl; 
    cin>>filename; 
    graph.readFromFile(filename.c_str()); 
    cout<<"done reading file"<<endl;

    SccComputer computer(graph);

    cout<<"Computing scc process beginning..."<<endl;
    computer.compute(graph);
  } 

 //reverse
 //dfsLoop
  //loop 1: calc finishing times
  //loop 2: assign leaders and find SCCs
 
 return 0;
}

