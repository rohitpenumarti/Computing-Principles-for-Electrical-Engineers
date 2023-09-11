#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>

class CPPLib {
 public:
  //q2
  int findKthSmallest(const std::vector<std::vector<int> > &input, int k);

  //q3
  std::vector<std::vector<int> > kClosest(std::vector<std::vector<int> >& points, int k);

};

// q1
class MaxHeap {
 public:
  MaxHeap() : data_() {}

  int getParentIndex(int i); //GT
  int getLeftIndex(int i); //GT
  int getRightIndex(int i); //GT
  int getLargestChildIndex(int i); //GT

  int getLeft(int i);
  int getRight(int i);
  int getParent(int i);

  int top(); //GT
  void push(int v); //GT
  void pop(); //GT
  void TrickleUp(int i);
  void TrickleDown(int i);

  std::vector<int> data_;
};

#endif
