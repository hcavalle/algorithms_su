/*
 * =====================================================================================
 *
 *       Filename:  scc.h
 *
 *    Description:  scc computation header file
 *
 *        Version:  1.0
 *        Created:  03/06/2015 10:38:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero   
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SCC_H
#define SCC_H

#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class SccComputer {
  private:

  public:
    int cur_leader;
    int cur_finish_time;
    vector<int> scc_vector;

    SccComputer(Graph g);
    SccComputer();
    void setMagicNumbers(Graph g);
    void setSccs(Graph g);
    void dfsLoop(Graph g);
    void dfs(Graph g, int node);
    void printTop5();
    void compute(Graph g);
};

#endif
