#include "cpplib.h"
#include "limits"
#include <cmath>
#include <iostream>

// Question 1
void CPPLib::GetAllStringsAux(std::string const &digits, int index, std::string combo, std::vector<std::string> &result) {
    if (index == digits.size()) {
        result.push_back(combo);
        return;
    }

    for (char c : m[digits[index]]) {
        combo.push_back(c);
        GetAllStringsAux(digits, index+1, combo, result);
        combo.pop_back();
    }
}

std::vector<std::string> CPPLib::GetAllStrings(std::string &digits) {
    std::vector<std::string> result;
    if (digits == "") {
        return result;
    }
    std::string combo = "";
    GetAllStringsAux(digits, 0, combo, result);
    return result;
}
// Question 2
int CPPLib::TSPWithGas(std::vector<std::vector<int> > &weights, std::vector<int> &gas, int start) {
    std::vector<int> cur_path = {start};
    std::vector<int> min_path;
    int min_cost = INT_MAX;
    TSPWithGas_aux(weights, gas, start, start, cur_path, 0, 0, min_cost, min_path);
    return min_cost;
}

void CPPLib::TSPWithGas_aux(std::vector<std::vector<int> > &weights,
                          std::vector<int> &gas, int start, int cur_node,
                          std::vector<int> &cur_path, int cur_cost,
                          int cur_gas, int &min_cost,
                          std::vector<int> &min_path) {
    if (cur_cost >= min_cost) {
        return;
    }
    
    cur_gas += gas[cur_node];
    if (cur_path.size() == weights.size()) {
        if (cur_gas >= weights[cur_node][start]) {
            int final_cost = cur_cost + weights[cur_node][start];
            if (final_cost < min_cost) {
                min_cost = final_cost;
                min_path = cur_path;
            }
            return;
        }
    }

    for (int i = 0; i < weights.size(); i++) {
        if (std::find(cur_path.begin(), cur_path.end(), i) == cur_path.end() && cur_gas >= weights[cur_node][i]) {
            cur_path.push_back(i);
            TSPWithGas_aux(weights, gas, start, i, cur_path, cur_cost + weights[cur_node][i],
                            cur_gas - weights[cur_node][i], min_cost, min_path);
            cur_path.pop_back();
        }
    }
}