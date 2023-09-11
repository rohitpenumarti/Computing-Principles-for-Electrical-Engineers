#include "cpplib.h"
#include "limits"
#include <iostream>
#include <math.h>
#include <queue>

int MaxHeap::getParentIndex(int i) {
    if (i == 0 || (int)((i-1)/2) >= data_.size()) {
        return -1;
    }

    return (int)((i-1)/2);
}

int MaxHeap::getLeftIndex(int i) {
    if (2*i+1 >= data_.size() || i < 0) {
        return -1;
    }

    return 2*i+1;
}

int MaxHeap::getRightIndex(int i) {
    if (2*i+2 >= data_.size() || i < 0) {
        return -1;
    }

    return 2*i+2;
}

int MaxHeap::getLargestChildIndex(int i) {
    if (getLeft(i) > getRight(i)) {
        return getLeftIndex(i);
    } else {
        return getRightIndex(i);
    }
}

int MaxHeap::getLeft(int i) {
    int val =  getLeftIndex(i);
    if (val == -1) {
        return -1;
    }

    return data_[val];
}

int MaxHeap::getRight(int i) {
    int val =  getRightIndex(i);
    if (val == -1) {
        return -1;
    }

    return data_[val];
}

int MaxHeap::getParent(int i) {
    int val =  getParentIndex(i);
    if (val == -1) {
        return -1;
    }

    return data_[val];
}

int MaxHeap::top() {
    if (data_.size() == 0) {
        return -1;
    }

    return data_[0];
}

void MaxHeap::push(int v) {
    data_.push_back(v);
    TrickleUp(data_.size()-1);
}

void MaxHeap::pop() {
    if (data_.size() == 0) {
        return;
    }

    data_.erase(data_.begin());
    TrickleDown(0);
}

void MaxHeap::TrickleUp(int i) {
    if (data_.size() == 0) {
        return;
    }

    while (i > 0 && data_[i] > getParent(i)) {
        std::swap(data_[getParentIndex(i)], data_[i]);
        i = getParentIndex(i);
    }
}

void MaxHeap::TrickleDown(int i) {
    if (data_.size() == 0) {
        return;
    }

    while (i < data_.size() && data_[i] < data_[getLargestChildIndex(i)]) {
        std::swap(data_[i], data_[getLargestChildIndex(i)]);
        i = getLargestChildIndex(i);
    }
}

int CPPLib::findKthSmallest(const std::vector<std::vector<int> > &input, int k) {
    if (k <= 0) {
        return INT32_MIN;
    }

    std::vector<int> values = {};
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            values.push_back(input[i][j]);
        }
    }

    std::priority_queue<int> pq;
    for (int i = 0; i < values.size(); i++) {
        if (i < k) {
            pq.push(values[i]);
        } else {
            if (values[i] < pq.top()) {
                pq.pop();
                pq.push(values[i]);
            }
        }
    }
    return pq.top();
}

std::vector<std::vector<int>> CPPLib::kClosest(std::vector<std::vector<int> >& points, int k) {
    if (k <= 0) {
        std::vector<std::vector<int> > v = {{}};
        return v;
    }

    std::vector<double> distances(points.size());
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points[i].size(); j++) {
            distances[i] += (points[i][j]*points[i][j]);
        }
        distances[i] = sqrt(distances[i]);
    }

    std::priority_queue<double> pq;
    std::map<double, std::vector<int>> index_map = {};
    for (int i = 0; i < distances.size(); i++) {
        index_map[distances[i]] = points[i];
        if (i < k) {
            pq.push(distances[i]);
        } else {
            if (distances[i] < pq.top()) {
                pq.pop();
                pq.push(distances[i]);
            }
        }
    }

    std::vector<std::vector<int>> v;
    while (pq.size() != 0) {
        v.push_back(index_map[pq.top()]);
        pq.pop();
    }

    std::reverse(v.begin(), v.end());
    return v;
}