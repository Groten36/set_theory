#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>

void print(const std::vector<int>& vector,const std::string& name) {
    std::cout<<name<<"= {";
    for (auto element : vector) {
        std::cout << element <<", ";
    }
    std::cout <<"} "<< std::endl;
}

void print(const std::vector<std::vector<int> >& vector,const std::string& name) {
    std::cout<<name<<"= {";
    for (auto element : vector) {
        std::cout << "{ ";
        for (auto i : element) {
            std::cout << i << ", ";
        }
        std::cout << "}, "<< std::endl;
    }
    std::cout<<"} "<< std::endl;
}

void print(const std::vector<std::pair<int,int>>& vector, const std::string& name) {
    std::cout << name << " = { ";
    for (const auto& element : vector) {
        std::cout << "{" << element.first << ", " << element.second << "}, ";
    }
    std::cout << "}\n";
}

size_t cardinality(const std::vector<int>& vector) {
    return vector.size();
}

std::vector<std::vector<int>> power_set(const std::vector<int>& set) {

    std::vector<std::vector<int>> result;
    size_t size = set.size();
    size_t number_of_subsets=1ULL << size;

    for (size_t i=0;i<number_of_subsets;i++) {
        std::vector<int> subset;
        for (size_t j=0;j<size;j++) {
            if (i & (1ULL<<j)) {
                subset.push_back(set.at(j));
            }
        }
        result.push_back(subset);
    }

    return result;

}

std::vector<std::pair<int,int>> cartesian_product(const std::vector<int>& setA, const std::vector<int>& setB) {
    std::vector<std::pair<int,int>> result;
    for (auto i:setA) {
        for (auto j:setB) {
            std::pair<int,int> pair={i,j};
            result.push_back(pair);
        }
    }
    return result;
}

bool is_subset(const std::vector<int>& vectorA, const std::vector<int>& setB) {
    for (auto i:vectorA) {
        if (find(setB.begin(),setB.end(),i)==setB.end()) {
            return false;
        }
    }
    return true;
}
int main() {
    std::vector<int> setA={1,2,3};
    std::vector<int> setB={23,4,5,6,1,2,3};
    print(setA,"A");
    print(setB,"B");

    std::cout<<"|A| = "<<cardinality(setA)<<" |B| = "<<cardinality(setB)<<std::endl;
    print(power_set(setA),"P(A)");
    print(cartesian_product(setA,setB),"AXB");
    if (is_subset(setA,setB)) {
        std::cout<<"A is subset of B";
    }
    else
        std::cout<<"A is not a subset of B";

    return 0;
}
