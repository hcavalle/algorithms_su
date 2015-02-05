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

void print_sub(vector<int> v, int start, int end) {
    if (v.size()) {
        for (vector<int>::const_iterator it = v.begin()+start; it != v.begin()+end; it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
  
}

long quickSort(vector<int>& ar, int start, int end, char pivot_mode){
  //cout<<"end - start = "<<end-start<<endl;
  int size = end - start;

  if ( size < 2){
    return 0;
  }
  int p_index = 0;

  switch (pivot_mode) {
    case 'f':
      //p_index = start;
      break;
    case 'l':
      //p_index = end-1;
      //iter_swap(ar.begin()+start, ar.begin() + end-1);
      std::swap(ar[start], ar[end-1]);
      break;
    case 'r':
      int mid;
      int median;
      if (size == 2) {
        median = start;
      }
      else {
        if (size % 2) mid = start + ((size)/2);
        else mid = start + (size/2) -1;
        /*  
        cout<<"size is: "<<size<<endl;
        cout<<"size mod 2: "<<size%2<<endl<<"size / 2: "<<size/2<<endl;
        cout<<"ar end-1 is: "<<ar[end-1]<<endl;
        cout<<"ar mid is: "<<ar[mid]<<endl;
        cout<<"ar start is: "<<ar[start]<<endl;
        */

        
        if (ar[start] > ar[end-1]) {
          if (ar[end-1] > ar[mid])
            median = end-1;
          else if (ar[mid] > ar[start])
            median = start;
          else
            median = mid;
        }
        else if (ar[start] < ar[end-1]) {
          if (ar[start] > ar[mid])
            median = start;
          else if (ar[mid] > ar[end-1])
            median = end-1;
          else
            median = mid;
        }
      }

      //print_sub(ar, start, end);
      /*  cout<<"end is: "<<end<<endl;
      cout<<"start is: "<<start<<endl;
      cout<<"mid is: "<<mid<<endl;
      cout<<"median value is: "<<ar[median]<<endl;
      cout<<"size addin to count is: "<<size-1<<endl;
      cout<<endl;
      */
      //cout<<"median index is: "<<median<<endl;
      std::swap(ar[start], ar[median]);
      //cout<<"pivot mode in r: "<<pivot_mode<<endl;
      break;
      
  }
    
  //choose pivot, set index
  //int p_index = end - 1;
  //first
  p_index = start;

  /*last
  int p_index = end;
  */

  //set left and right indexes
  int right_start = start+1;
  int i = start+1;
  long count=0;

  while ( i < end) {
    if ( (ar[i] < ar[p_index])) {
      if (i > right_start){
        ar[i] = ar[i] - ar[right_start];
        ar[right_start] = ar[i] + ar[right_start];
        ar[i] = ar[right_start] - ar[i];
      }
      right_start++;
    }
    
    i++;

  }
  //swap ar[start] and ar[right_start -1] -- put pivot in right spot
  //cout<<"start index is: "<<start<<"right start index is: "<<right_start<<endl;
  //cout<<"start value is: "<<ar[start]<<"right start value is: "<<ar[right_start]<<endl;
  /*
  ar[start] = ar[start] - ar[right_start-1];
  ar[right_start-1] = ar[start] + ar[right_start-1];
  ar[start] = ar[right_start -1] - ar[start]; 
  */
  
  //print_vector(ar);

  int tmp = 0;
  tmp = ar[p_index];
  ar[p_index] = ar[right_start-1];
  ar[right_start -1 ] = tmp; 
  /* 
  ar[start] = ar[start] ^ ar[right_start-1];
  ar[right_start-1] = ar[start] ^ ar[right_start-1];
  ar[start] = ar[start] - ar[right_start-1]; 
  */


  count += size -1;
  //recurse on left and right
  count += quickSort(ar, right_start, end, pivot_mode);
  //cout<<"adding to running count: "<<count<<endl;
  count += quickSort(ar, start, right_start-1, pivot_mode);
  //cout<<"adding to running count: "<<count<<endl;
  //cout<<"running count: "<<count<<endl;

  //cout<<"pivot index:"<<p_index<<endl;
  //cout<<"pivot value:"<<ar[p_index]<<endl;
  //print_vector(ar);
  //print_sub(ar, start, end);
  return count;

}

void file_to_ar(vector<int>& _ar){
  _ar.clear();
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


int main(int argc, char** argv) {
    vector <int>  _ar;
    long count;
    /* string user_mode;

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
         cin >> _ar_size;
         for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
           int _ar_tmp;
           cin >> _ar_tmp;
           _ar.push_back(_ar_tmp);
         }
         
    }*/

    file_to_ar(_ar);

    count = quickSort(_ar, 0, _ar.size(), 'f');
    //print_vector(_ar);
    cout<<"final count PIVOT FIRST is: "<<count<<endl;

    file_to_ar(_ar);
 
    count = quickSort(_ar, 0, _ar.size(), 'l');
    //print_vector(_ar);
    cout<<"final count PIVOT LAST is: "<<count<<endl;

    file_to_ar(_ar);

    count = quickSort(_ar, 0, _ar.size(), 'r');
    //print_vector(_ar);
    cout<<"final count PIVOT RAND is: "<<count<<endl;

   return 0;

}


