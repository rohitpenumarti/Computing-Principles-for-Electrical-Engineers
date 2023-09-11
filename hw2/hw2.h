#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>

/**
 *  Example class used for GTest demo
 */
class CPPLib {
 public:
  // q1
  bool IsGreaterThan(int input1, int input2);
  bool IsGreaterThan(int input1, std::string input2);
  bool IsGreaterThan(std::string input1, int input2);
  bool IsGreaterThan(std::string input1, std::string input2);
  //q3
  void RemoveIntersectionByReference(std::vector<int> &input1, std::vector<int> &input2);
  void RemoveIntersectionByPointer(std::vector<int> *input1, std::vector<int> *input2);

  //q4
  void UniqueVectorNotBySet(std::vector<int> &input);
  void UniqueVectorBySet(std::vector<int> &input);
  void ReverseVector(std::vector<int> &input);
  void ReverseString(std::string &input);
  void PrimeVector(std::vector<int> &input);
  std::vector<int> UnionVectors(std::vector<int> &input1, std::vector<int> &input2);

  //q5
  void CleanString(std::string& input);

  // q6
  int findLucky(std::vector<int>& input);

  // q7
  void Rearrange(std::vector<int>& input, int k);

  // q8
  bool Match(const std::string& pattern, const std::vector<std::string>& strs);
};

#endif
