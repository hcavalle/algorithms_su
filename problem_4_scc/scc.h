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
    int _cur_leader;
    int _cur_finish_time;
    map<int, int> scc_map;
    vector<int> magic_numbers;
    Graph graph;
    Graph g_rev;

    SccComputer(Graph g);
    SccComputer();
    int leader();
    void leader(int l);
    int finish_time();
    void finish_time(int ft);
    void increment_finish_time();

    void setMagicNumbers(Graph& g);
    void setSccs(Graph& g);
    void getSccs(Graph& g);
    void printSccs(Graph& g);

    void dfsLoop(Graph& g);
    void dfs(Graph& g, int node);
    void printTop5();
    void compute(Graph& g);
};

#endif
