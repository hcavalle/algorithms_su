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

#include "graph.h"
#include <iostream>
#include <fstream>

using namespace std;

void dfsLoop(Graph g) {
  //Graph grev = g.reverse();

  //loop 1
}

int main(int argc, char **argv) {
 Graph graph;
 string filename;
 //read in from file
 while (true) {
   cout<<"filename plase: "<<endl;
   cin>>filename;


   //call mincut as specified for rand contraction algorithm

   graph.readFromFile(filename.c_str());
   cout<<"done reading from file"<<endl;
   Graph reverse(graph);
   reverse.reverse();
   cout<<"done reversing graph";
 }
                                                                                                
 //reverse
 //dfsLoop
  //loop 1: calc finishing times
  //loop 2: assign leaders and find SCCs
 
 return 0;
  
}

