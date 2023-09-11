#include "cpplib.h"
#include "limits"
#include <iostream>

std::string CPPLib::PrintHelloWorld() { return "**** Hello World ****"; }

// Question 5 Print your self-introduction
std::string CPPLib::PrintIntro() {
    return "Name: Rohit Penumarti\nEmail: penumart@usc.edu\nMajor: MS Quantum Information Science\nInterests: "
               " Machine Learning, Hiking, Backpacking, Exercising, Soccer, Movies"; 
}

// Question 6
std::vector<int> CPPLib::Flatten3DVector(const std::vector< std::vector< std::vector<int> > > &input){
    std::vector<int> res;

    if (input.empty()) {
        return res;
    }

    for (std::vector< std::vector<int> > v2d : input) {
        for (std::vector<int> v1d: v2d) {
            for (int i : v1d) {
                res.push_back(i);
            }
        }
    }
    return res;
}

// Question 7 Climbing Stairs
int CPPLib::climbStairs(int n) {
    if (n < 0) {
        return -1;
    } else if (n <= 2) {
        return n;
    } else {
        return climbStairs(n-1) + climbStairs(n-2);
    }
}
