// mergesort problem 1 solution
/*
 *This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.

Your task is to compute the number of inversions in the file given, where the ith row of the file indicates the ith entry of an array.
Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the video lectures. The numeric answer for the given input file should be typed in the space below.
So if your answer is 1198233847, then just type 1198233847 in the space provided without any space / commas / any other punctuation marks. You can make up to 5 attempts, and we'll use the best one for grading.
(We do not require you to submit your code, so feel free to use any programming language you want --- just type the final numeric answer in the following space.)

[TIP: before submitting, first test the correctness of your program on some small test files or your own devising. Then post your best test cases to the discussion forums to help your fellow students!]
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int max(){
  //compare to ints, return larger
  return 0;
}

void print_vector(const vector<int> v){
  if (v.size()) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
      //cout<<*it<<" ";
    }
    //cout<<endl;
  }
}

int merge(vector<int> &ar, vector<int> &left, vector<int> &right) {
  //for length of ar
  int i = 0;
  int j = 0;
  int k = 0;
  int inv_count = 0;

  //cout<<"printing left..."<<endl;
  //print_vector(left);
  
  //cout<<"printing right"<<endl;
  //print_vector(right);

  for (k = 0; k < ar.size(); k++) {
    if (left[i] < right[j] && i < left.size() || j == right.size()) {
      //cout<<"pushing back left with index: "<<i<<" and value: "<<left[i]<<endl;
      ar[k] = left[i];
      i++;
    }
    else if(right[j] < left[i] && j < right.size() || i == left.size()){
      //cout<<"pushing back right with index: "<<j<<" and value: "<<right[j]<<endl;
      ar[k] = right[j];
      j++;
      
      if (left.size() > i)
        inv_count += (left.size() - i);
    }
  }//end for k
  cout<<"inv count before merge return..."<<inv_count<<endl;
  //cout<<"printing ar before return from merge..."<<endl;
  //print_vector(ar);
  return inv_count;
}//end merge

vector<int> merge_sort(vector<int> &ar, unsigned long* count){
  //cout<<"entering function merge_sort with size"<<ar_size<<endl;

  if (!ar.size()){
    //cout<<"empty array given to mergesort"<<endl;
    return ar;
  }
  int swp_count = 0;
  int total_count = 0;

  //divide
  if (ar.size() == 1) {
    //cout<<"base case met, returning ar..."<<endl;
    return ar; 
  }
  vector<int> left;
  vector<int> right; 

  int middle; 
  
  for (int i = 0; i < ar.size(); i++) {
    if (i < ar.size()/2)
      left.push_back(ar[i]);
    else
      right.push_back(ar[i]); 
  }
  //call mergesort on left and right recursively
  //cout<<"calling left recursive call..."<<endl;
  left = merge_sort(left, count);
  //cout<<"return from left call."<<endl;

  //cout<<"calling right recursive call.."<<endl;
  right = merge_sort(right, count);
  //cout<<"return from right call."<<endl;
  
  //call merge on resultant vectors
  //cout<<"calling merge..."<<endl;
  *count += merge(ar, left, right);
 
  cout<<"total count is: "<<*count<<endl;
  //print_vector(ar);
  return ar;
}


int main(int argc, char** argv) {
  //cout<<"starting mergesort..."<<endl;
  vector<int> ar;
  int t=0;
  unsigned long *count = new unsigned long(0);
  std::string line;

  //open file
  std::ifstream myfile (argv[1]);
  //std::ifstream myfile ("input.txt", std::ifstream::in);

  while (std::getline(myfile, line)){
    //read from file into array
    //cout<<"read and insert line: "<<line<<endl;

    //convert string to int
    std::istringstream convert(line);
    if ((convert >> t) )
      ar.push_back(t);
  }

  //mergesort on input array
  ar = merge_sort(ar, count);
}


