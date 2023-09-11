#include "cpplib.h"
#include "limits"
#include "set"

// Question 1
bool CPPLib::IsGreaterThan(int input1, int input2) {
  if (input1 > input2) {
    return true;
  } else {
    return false;
  }
}

bool CPPLib::IsGreaterThan(int input1, std::string input2) {
  for (int i = 0; i < input2.length(); i++) {
    if (!std::isdigit(input2[i])) {
      return false;
    }
  }

  if (input1 > std::stoi(input2)) {
    return true;
  } else {
    return false;
  }
}

bool CPPLib::IsGreaterThan(std::string input1, int input2) {
  for (int i = 0; i < input1.length(); i++) {
    if (!std::isdigit(input1[i])) {
      return false;
    }
  }
  
  if (stoi(input1) > input2) {
    return true;
  } else {
    return false;
  }
}

bool CPPLib::IsGreaterThan(std::string input1, std::string input2) {
  if (input1.length() > input2.length()) {
    return true;
  } else {
    return false;
  }
}

// Question 3
void CPPLib::RemoveIntersectionByReference(std::vector<int> &input1, std::vector<int> &input2) {
  int i = 0;
  while (i < input1.size()) {
    auto loc = std::find(input2.begin(), input2.end(), input1[i]);
    if (loc != input2.end()) {
      input1.erase(input1.begin() + i);
      input2.erase(loc);
      continue;
    }
    i++;
  }
}
void CPPLib::RemoveIntersectionByPointer(std::vector<int> *input1, std::vector<int> *input2) {
  int i = 0;
  while (i < (*input1).size()) {
    auto loc = std::find((*input2).begin(), (*input2).end(), (*input1)[i]);
    if (loc != (*input2).end()) {
      (*input1).erase((*input1).begin() + i);
      (*input2).erase(loc);
      continue;
    }
    i++;
  }
}

// Question 4
void CPPLib::UniqueVectorNotBySet(std::vector<int>& input) {
  if (input.empty()) {
    return;
  }
  std::vector<int> unique = {};

  for (int i = 0; i < input.size(); i++) {
    if (std::find(unique.begin(), unique.end(), input[i]) == unique.end()) {
      unique.push_back(input[i]);
    }
  }

  input = unique;
}
void CPPLib::UniqueVectorBySet(std::vector<int>& input) {
  if (input.empty()) {
    return;
  }
  std::set<int> unique;
  unique.insert(input.begin(), input.end());

  input.erase(input.begin(), input.end());
  for (auto it = unique.begin(); it != unique.end(); it++) {
    input.push_back(*it);
  }
}

void CPPLib::ReverseVector(std::vector<int> &input){
  if (input.empty()) {
    return;
  }

  std::reverse(input.begin(), input.end());
}
void CPPLib::ReverseString(std::string& input) {
  int initial_length = input.length();

  for (int i = input.length()-2; i >= 0; i--) {
    input += input[i];
  }

  input.erase(input.begin(), input.begin()+initial_length-1);
}
void CPPLib::PrimeVector(std::vector<int>& input) {
  int i = 0;
  while (i < input.size()) {
    if (input[i] == 1) {
      input.erase(input.begin()+i);
      continue;
    } else if (input[i] % 2 == 0 && input[i] != 2) {
      input.erase(input.begin()+i);
      continue;
    } else {
      for (int j = 3; j <= int(input[i]/2); j++) {
        if (input[i] % j == 0) {
          input.erase(input.begin()+i);
          break;
        }
      }
    }
    i++;
  }
}
std::vector<int> CPPLib::UnionVectors(std::vector<int>& input1, std::vector<int>& input2) {
  std::vector<int> result = {};
  for (int i = 0; i < input1.size(); i++) {
    if (std::find(result.begin(), result.end(), input1[i]) != result.end()) {
      break;
    }

    if (std::find(input2.begin(), input2.end(), input1[i]) != input2.end()) {
      result.push_back(input1[i]);
    }
  }
  return result;
}

// Question 5
void CPPLib::CleanString(std::string& input) {
  std::transform(input.begin(), input.end(), input.begin(), tolower);
  input.erase(std::remove_if(input.begin(), input.end(), ispunct), input.end());
}

// Question 6
int CPPLib::findLucky(std::vector<int>& input) {
  int result = -1;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] > result) {
      int count = std::count(input.begin(), input.end(), input[i]);
      if (count == input[i]) {
        result = count;
      }
    }
  }
  return result;
}

// Question 7
void CPPLib::Rearrange(std::vector<int>& input, int k) {
  std::vector<int> tmp_vec = input;
  std::sort(tmp_vec.begin(), tmp_vec.end(), 
            [](int a, int b) {
              return a < b;
            });
  int k_largest = tmp_vec[tmp_vec.size()-k];
  auto idx = std::find(input.begin(), input.end(), k_largest);

  std::map<int, int> m;
  for (int i = 0; i < input.size(); i++) {
    m.insert({i, input[i]});
  }

  for (int i = 0; i < input.size(); i++) {
    if (m.at(i) < k_largest && i > std::distance(input.begin(), idx)) {
      auto it = std::find_if(input.rbegin()-(std::distance(idx, input.end())), input.rend(),
                            [&k_largest](int a) {
                              return a < k_largest;
                            });
      if (it == input.rend()) {
        std::replace(input.begin(), idx, input[0], m.at(i));
      } else {
        std::replace(input.begin(), idx, *(std::next(it)), m.at(i));
      }
    } else if (m.at(i) > k_largest && i < std::distance(input.begin(), idx)) {
      auto it = std::find_if(input.rbegin(), input.rbegin()-(std::distance(idx, input.end())),
                            [&k_largest](int a) {
                              return a > k_largest;
                            });
      if ((it+1).base() == idx) {
        std::replace(idx, input.end(), *(std::next(idx)), m.at(i));
      } else {
        std::replace(idx, input.end(), *(std::next(it)), m.at(i));
      }
    }
  }
}

// Question 8
bool CPPLib::Match(const std::string& pattern, const std::vector<std::string>& strs) {
  if (pattern.length() != strs.size()) {
    return false;
  }

  std::map<char, std::string> m;
  for (int i = 0; i < pattern.length(); i++) {
    if (m.find(pattern[i]) == m.end()) {
      for (auto it = m.begin(); it != m.end(); it++) {
        if (strs[i].compare(it->second) == 0) {
          return false;
        }
      }
      m.insert({pattern[i], strs[i]});
    } else {
      if (strs[i].compare(m[pattern[i]]) != 0) {
        return false;
      }
    }
  }

  return true;
}