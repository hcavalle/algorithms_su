/*
 * =====================================================================================
 *
 *       Filename:  min_cut.cpp
 *
 *    Description:  take an adjacency list and find the min cut using randomized contraction algorithm
 *
 *        Version:  1.0
 *        Created:  02/08/2015 08:50:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harrison Cavallero 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "adjacency_list.h"
#include <string>


int main (int argc, char *argv[]) {
  //instantiate adjacency list graph
  Graph graph(201);
  int cut = 0;
  int min_cut;
  int max = 10;
  string filename = "kargerMinCut.txt";
  if (argc > 1)
    filename = argv[1];

  while (true) {
    min_cut = 201;
    cout<<"filename plase: "<<endl;
    cin>>filename;
    cout<<"max:"<<endl;
    cin>>max;
    

    //call mincut as specified for rand contraction algorithm
    for (int i = 0; i < max; i++) {
      
      graph.readEdgesFromFile(filename.c_str());
      cut = graph.minCut();
      min_cut = min_cut < cut ? min_cut : cut;
    }
      cout<<"min cut is: "<<min_cut<<endl;;
  }  
  //print 2 nodes left
  //graph.printGraph();
  return 0;
  
}

