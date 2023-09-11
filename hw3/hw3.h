#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

enum class Command {kFind, kSort, kErase};
enum class ResultCode {kSuccess, kIndexError, kFindError};

class CPPLib {
 public:
  //q3
  ResultCode vector_commander(std::vector<int>& v, int left, int right, int find_value, Command command);
  //q5
  void mergeArray(std::vector<int>& input1, int m, std::vector<int>& input2, int n);
  //q8
  bool CheckValidExpression(const std::string& a);
};


// q6
class MyString
{
private:
    char* data_;
    int size_;
public:
    MyString();
    ~MyString();
    MyString(const MyString&);
    void push_back(char);
    void pop_back();
    int size();
    char* data();
    bool empty();
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct Statistics {
  int minimum;
  int maximum;
  int median;
  float average;
  float standard_deviation;
 };

class SinglyLinkedList {
public:
  SinglyLinkedList() { head_ = nullptr; }
  SinglyLinkedList(const SinglyLinkedList&);
  SinglyLinkedList(const std::vector<int> &v);
  bool empty();
  int size();
  void push_back(int i);
  void pop_back();
  int back();
  ListNode *GetBackPointer();
  ListNode *GetIthPointer(int i);
  void print();

  std::vector<int> convert_to_vector();
  ListNode *erase(int i);
  std::map<int, int> histogram();
  void remove_duplicates();
  Statistics calculate_statistics();

  ListNode *GetTheFirstOddValue(ListNode *head);
  ListNode * CreateNodeWithValue(int value);

  ListNode *head_;
};


#endif
