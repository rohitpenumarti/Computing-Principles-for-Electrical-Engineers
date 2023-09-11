#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

class CPPLib {
 private:
      std::map<char, std::set<char> > m = {
        {'0', {'a', 'b'}},
        {'1', {'d', 'f'}},
        {'2', {'g', 'h'}},
        {'3', {'j', 'k'}},
        {'4', {'m', 'n'}},
        {'5', {'p', 'q'}},
        {'6', {'t', 'u'}},
        {'7', {'w', 'x'}},
        {'8', {'!', '?'}},
        {'9', {'*', '#'}}
      };
 
     void GetAllStringsAux(std::string const &digits, int index, std::string combo, std::vector<std::string> &result);
 
 public:
      //q1
      std::vector<std::string> GetAllStrings(std::string &digits);

      //q2

      static int TSPWithGas(std::vector<std::vector<int> > &weights,
                          std::vector<int> &gas, int start);

      static void TSPWithGas_aux(std::vector<std::vector<int> > &weights,
                                std::vector<int> &gas, int start, int cur_node,
                                std::vector<int> &cur_path, int cur_cost,
                                int cur_gas, int &min_cost,
                                std::vector<int> &min_path);
};

#endif
