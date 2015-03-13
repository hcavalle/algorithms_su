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
  this->graph = g;
  this->g_rev = g;
  this->leader(g.n());
  this->finish_time(0);
}

SccComputer::SccComputer() {
}

int SccComputer::leader() {
  return _cur_leader;

}

void SccComputer::leader(int l) {
  this->_cur_leader = l;

}

int SccComputer::finish_time() {
  return _cur_finish_time;

}

void SccComputer::finish_time(int ft) {
  this->_cur_finish_time = ft;

}

void SccComputer::increment_finish_time(){
  _cur_finish_time++;
}

void SccComputer::dfs(Graph& g, int node) {
  //mark as explored
  g.setVertexExplored(node);
  
  //set leader
  g.vertexLeader(node, this->leader());

  //check each arc recursively
  pair<map<int,int>::iterator, map<int,int>::iterator> arc_range = g.edges.equal_range(node);
  for (map<int,int>::iterator it = arc_range.first; it != arc_range.second; it++){
    int tail = it->second;
    if ( !g.vertexExplored(tail) ) {
      dfs(g,tail);
    }
  } 
  //_cur_finish_time++;
  this->increment_finish_time();
  
  //use pass by value accessor
  g.setFinish(node, this->finish_time());
  
}

void SccComputer::dfsLoop(Graph& g) {
  //loop 
  this->finish_time(0);

  for (map<int, Vertex>::reverse_iterator it = g.vertices.rbegin(); it != g.vertices.rend(); it++) {
    if (  !g.vertexExplored(it->first) ) {
      this->leader(it->first);
      dfs(g,it->first);
    }
      
  }
}

/*void SccComputer::dfsLoopByFinish() {
  //iterate over g_rev finish_times
  //for each finish time call dfs on the main graph entry, leaders will be sccs
  for (map<int,int>::reverse_iterator it = this->g_rev.finish_times.rbegin(); it != this->g_rev.finish_times.rend(); it++) {
    if (!this->graph.vertexExplored(it->second)) {
      this->leader(it->second);
      dfs(this->graph, it->second);
    }
  }
}*/

void SccComputer::setMagicNumbers(Graph& g_rev) {
  //dfsLoop1
  g_rev.reverse();
  dfsLoop(g_rev);
  this->graph.nodesToFinishTimes(g_rev.finish_times);
}

void SccComputer::setSccs(Graph& g) {
  //leader now demarcates sccs
  dfsLoop(g);
  std::pair<map<int, int>::iterator, bool> ret;
  for (map<int, Vertex>::iterator it=g.vertices.begin(); it != g.vertices.end(); it++) {
    ret = this->scc_map.insert(make_pair(it->second.leader, 1));
    if (!ret.second) {
      scc_map[it->second.leader]++;
    }
  }
}

void SccComputer::getSccs(Graph& g){
  //iterate over all vertices inserting and incrementing a leader map within scc

}

void SccComputer::printSccs(Graph& g) {
  cout<<"scc count:"<<endl;
  for (map<int,int>::iterator it = this->scc_map.begin(); it != scc_map.end(); it++) {
    cout<<it->second<<",";
  }

}

void SccComputer::compute(Graph& g) {
  setMagicNumbers(this->g_rev);
  setSccs(this->graph);
  printSccs(this->g_rev);
}

int main(int argc, char **argv) {
  Graph graph;
  //read in from file
  string filename;

  while (true) { 
    cout<<"filename please: "<<endl; 
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

