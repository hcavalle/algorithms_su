/*
 * =====================================================================================
 *
 *       Filename:  quicksort_first_pivot.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/31/2015 09:53:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v){
    if (v.size()) {
        for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

int choose_pivot(int start, int end, char mode) {
  /*cout<<"start is "<<start<<endl;
  cout<<"end is"<<end<<endl;
  cout<<"mode is"<<mode<<endl;
  */
  switch (mode) {
    case 'f':
      return start;
      break;
    case 'l':
      return end-1;
      break;
    case 'r':
      return start + (rand() % (end-start));
      break;
  }
  return start;
}

int quickSort(vector<int>& ar, int start, int end, char pivot_mode){
  //cout<<"end is: "<<end<<endl;
  //cout<<"start is: "<<start<<endl;
  cout<<"end - start = "<<end-start<<endl;

  if ( end - start < 2){
    return end - start -1;
  }
    
  //choose pivot, set index
  //int p_index = end - 1;
  //int p_index = start;
  int p_index = choose_pivot(start, end, pivot_mode);

  //set left and right indexes
  int r = end-1;
  int l = start;
  int count=0;

  while ( l < r) {
    while ( ar[r] > ar[p_index] &&  r > 1) {
      r--;
    }
    while ( (ar[l] < ar[p_index]) && l <= r) {
      l++;
    }
    
    if (l < r) {
      iter_swap(ar.begin()+l, ar.begin()+r);
      l++;
    }
     
   /* if (i < right_start){
        ar[i] = ar[i] - ar[right_start];
        ar[right_start] = ar[i] + ar[right_start];
        ar[i] = ar[right_start] - ar[i];
      }
      */
    print_vector(ar);

  }
  //cout<<"start index is: "<<start<<"right start index is: "<<right_start<<endl;
  //cout<<"start value is: "<<ar[start]<<"right start value is: "<<ar[right_start]<<endl;
  
  //recurse on left and right
  count += quickSort(ar, start, l, pivot_mode);
  //cout<<"adding to running count: "<<count<<endl;
  count += quickSort(ar, r, end, pivot_mode);
  //cout<<"adding to running count: "<<count<<endl;

  count += end - start - 1;
  //cout<<"adding to running count: "<<count<<endl;
  return count;

}

int main(int argc, char** argv) {
    vector <int>  _ar;
    int count;
    string user_mode;

    if (!argv[1]) { 
      while( (user_mode.compare("file") !=0 && user_mode.compare("cli") !=0)) {
        cout<<"Enter user mode: cli | file"<<endl;
        cin>>user_mode; 
        cout<<"mode set to: "<<user_mode;
      }
    } 
    else {
      user_mode = argv[1];
    }
    
    cout<<"entering input mode: "<<user_mode<<endl;

    if (user_mode == "cli") {
      /* cin >> _ar_size;
         for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
           int _ar_tmp;
           cin >> _ar_tmp;
           _ar.push_back(_ar_tmp);
         }
         */
    }
    else {
      string filename;
      string line;
      int t;

      
      while (filename.empty()) {
        cout<<"enter file name..."<<endl; 
        cin>>filename;
        cout<<"filename is: "<<filename<<endl;
      }

      std::ifstream myfile;
      myfile.open(filename.c_str());

      if (!myfile.is_open()) {
        cout<<"problem reading file..."<<endl;
        exit(1);
      }
      
      while (std::getline(myfile, line)){
        //read from file into array

        std::istringstream convert(line);
        if ((convert >> t) )
          _ar.push_back(t);
      }
    } 

    count = quickSort(_ar, 0, _ar.size(), 'f');
    print_vector(_ar);
    cout<<"final count PIVOT FIRST is: "<<count<<endl;

    count = quickSort(_ar, 0, _ar.size(), 'l');
    print_vector(_ar);
    cout<<"final count PIVOT LAST is: "<<count<<endl;

    count = quickSort(_ar, 0, _ar.size(), 'r');
    print_vector(_ar);
    cout<<"final count PIVOT RAND is: "<<count<<endl;

   return 0;

}


