#include "cpplib.h"
#include "limits"
#include <iostream>
#include <stack>
#include <map>
#include <cmath>

// Question 3

ResultCode CPPLib::vector_commander(std::vector<int>& v, int left, int right, int find_value, Command command) {
  if (command == Command::kSort) {
    if ((0 <= left && left < v.size()) && (left < right && right <= v.size())) {
      std::sort(v.begin()+left, v.begin()+right);
      return ResultCode::kSuccess;
    } else {
      return ResultCode::kIndexError;
    }
  } else if (command == Command::kFind) {
    if (!((0 <= left && left < v.size()) && (left < right && right <= v.size()))) {
      return ResultCode::kIndexError;
    }

    if (std::find(v.begin()+left, v.begin()+right, find_value) != v.begin()+right) {
      return ResultCode::kSuccess;
    } else {
      return ResultCode::kFindError;
    }
  } else {
    if (0 <= left && left < v.size()) {
      v.erase(v.begin()+left);
      return ResultCode::kSuccess;
    } else {
      return ResultCode::kIndexError;
    }
  }
}

// Question 5
void CPPLib::mergeArray(std::vector<int>& input1, int m, std::vector<int>& input2, int n) {
  std::vector<int> input1Copy = input1;

  int curr_i1 = 0;
  int curr_i2 = 0;
  for (int i = 0; i < m+n; i++) {
    if (curr_i2 > n && curr_i1 > m) {
      break;
    } else if (curr_i2 >= n && curr_i1 < m) {
      input1[i] = input1Copy[curr_i1];
      curr_i1++;
      continue;
    }

    if (input2[curr_i2] < input1Copy[curr_i1]) {
      input1[i+1] = input1Copy[curr_i1];
      input1[i] = input2[curr_i2];
      curr_i2++;
    } else {
      curr_i1++;
    }

    if (i >= m+curr_i2) {
      input1[i] = input2[curr_i2];
      curr_i2++;
    }
  }
}

// Question 6
MyString::MyString() {
  data_ = nullptr;
  size_ = 0;
}

MyString::~MyString() {
  if (data_ != nullptr) {
    delete data_;
  }

  std::cout << "Delete!" << std::endl;
}

MyString::MyString(const MyString& rhs) {
  size_ = rhs.size_;
  data_ = new char(rhs.size_);
  std::copy(rhs.data_, rhs.data_+rhs.size_, data_);
}

void MyString::push_back(char ch) {
  char * s = new char[size_+1];

  if(data_ == nullptr) {
    s[0] = ch;
  } else {
    for (int i = 0; i < size_; i++) {
      s[i] = data_[i];
    }
    s[size_] = ch;
  }

  if (data_) {
    delete data_;
  }

  data_ = s;
  size_ += 1;
}

void MyString::pop_back() {
  if (size_ == 0) {
    return;
  }

  char * s = new char[size_];
  for (int i = 0; i < size_; i++) {
    s[i] = data_[i];
  }

  if (data_) {
    delete data_;
  }

  data_ = s;
  size_--;
}

int MyString::size() {
  return size_;
}

char* MyString::data() {
  return data_;
}

bool MyString::empty() {
  if (size_== 0) {
    return true;
  } else {
    return false;
  }
}

// Question 7
bool CPPLib::CheckValidExpression(const std::string& a){
  if (a.length() == 0) {
    return true;
  } else if(a.length() == 1) {
    return false;
  }

  std::stack<char> characters;
  std::map<char, char> bracket_map = {{')', '('}, {'}', '{'}, {']', '['}};
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '(' || a[i] == '[' || a[i] == '{' || a[i] == ')' || a[i] == ']' || a[i] == '}') {
      if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
        characters.push(a[i]);
      } else if ((a[i] == ')' || a[i] == ']' || a[i] == '}') && !characters.empty() && (characters.top() != bracket_map.at(a[i]))) {
        return false;
      } else {
        if (characters.empty()) {
          return false;
        } else {
          characters.pop();
        }
      }
    }
  }

  return characters.empty();
}

// Question 8

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs) {
  if (rhs.head_ != nullptr) {
    ListNode *n1 = rhs.head_;
    ListNode *n2;
    ListNode *node = new ListNode(n1->val);
    head_ = node;
    n2 = head_;

    while(n1->next != nullptr) {
      n1 = n1->next;
      ListNode *node = new ListNode(n1->val);
      n2->next = node;
      n2 = node;
    }
  }
}

SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v) {
  ListNode **x = &head_;
  for (int i = 0; i < v.size(); i++) {
    *x = new ListNode(v[i]);
    x = &(*x)->next;
  }
}

bool SinglyLinkedList::empty() { return head_ == nullptr; }

int SinglyLinkedList::size() {
  int s = 0;
  if (empty()) {
    return s;
  }
  ListNode *p = head_;
  ListNode *p_prev;
  while (p != nullptr) {
    s++;
    p_prev = p;
    p = p->next;
  }

  return s;
}

ListNode *SinglyLinkedList::GetBackPointer() {
  if (empty()) {
    return head_;
  }
  ListNode *p = head_;
  while (p->next != nullptr) {
    p = p->next;
  }
  return p;
}

ListNode *SinglyLinkedList::GetIthPointer(int i) {
  if (empty()) {
    return head_;
  }

  ListNode *p = head_;
  ListNode *p_prev = head_;
  int max_size = size();
  int count = 0;
  while (p != nullptr && count < max_size && count <= i) {
    p_prev = p;
    p = p->next;  // Dangerous!! If p is null, then p->next = crash!!
    count++;
  }

  if (i < max_size) {
    return p_prev;
  } else {
    return nullptr;
  }
}

void SinglyLinkedList::push_back(int i) {
  // If list empty, create a new node and point head_ to it
  if (empty()) {
    head_ = new ListNode(i);
    return;
  }
  // If not empty, go to the end, create a new node and point the last item to
  // it
  auto back_ptr = GetBackPointer();
  auto newNode = new ListNode(i);
  back_ptr->next = newNode;
}

void SinglyLinkedList::pop_back() {}
int SinglyLinkedList::back() { return 0; }
void SinglyLinkedList::print() {
  std::cout << "{";
  if (!empty()) {
    ListNode *p = head_;
    ListNode *p_prev;
    while (p != nullptr) {
      p_prev = p;
      std::cout << p->val;
      p = p->next;
      if (p) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
}

std::vector<int> SinglyLinkedList::convert_to_vector() {
  std::vector<int> v = {};

  ListNode *p = head_;
  while (p != nullptr) {
    v.push_back(p->val);
    p = p->next;
  }

  return v;
}

ListNode * SinglyLinkedList::erase(int i) {
  return NULL;
}

std::map<int, int> SinglyLinkedList::histogram() {
  std::map<int, int> m = {};

  ListNode *p = head_;
  while (p != nullptr) {
    m[p->val]++;
    p = p->next;
  }

  return m;
}
void SinglyLinkedList::remove_duplicates() {
  
}

Statistics SinglyLinkedList::calculate_statistics() {
  Statistics s;

  ListNode *p = head_;
  int min = INT32_MAX;
  int max = INT32_MIN;
  int sum = 0;
  double median;

  if (size()%2 == 0) {
    ListNode *p1 = GetIthPointer(size()/2);
    ListNode *p2 = GetIthPointer(1+(size()/2));
    median = 0.5*(p1->val+p2->val);
  } else {
    ListNode *p = GetIthPointer(size()/2);
    median = p->val;
  }

  int min_temp;
  int max_temp;
  while (p != nullptr) {
    min_temp = p->val;
    if(min_temp < min) {
      min = min_temp;
    }

    max_temp = p->val;
    if(max_temp > max) {
      max = max_temp;
    }
    
    sum += p->val;
    p = p->next;
  }

  float average = ((float)sum)/size();

  ListNode *p1 = head_;
  double sd_sum = 0;
  while (p1 != nullptr) {
    sd_sum += (p1->val - average)*(p1->val - average);
    p1 = p1->next;
  }

  float sd = sqrt(sd_sum/size());

  s.minimum = min;
  s.maximum = max;
  s.median = median;
  s.average = average;
  s.standard_deviation = sd;

  return s;
}

ListNode * SinglyLinkedList::GetTheFirstOddValue(ListNode *head) {
  while (head != nullptr) {
    if (head->val % 2 != 0) {
      return head;
    } else {
      head = head->next;
    }
  }
  return head;
}

ListNode * SinglyLinkedList::CreateNodeWithValue(int value) {
  return new ListNode(value);
}