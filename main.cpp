#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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

int cardinality(const std::vector<int>& vector) {
    return vector.size();
}

std::vector<std::vector<int>> power_set(const std::vector<int>& set) {

    std::vector<std::vector<int>> result;
    int size = set.size();
    int number_of_subsets=pow(2,size);

    for (int i=0;i<number_of_subsets;i++) {
        std::vector<int> subset;
        for (int j=0;j<size;j++) {
            if (i & 1<<j) {
                subset.push_back(set.at(j));
            }
        }
        result.push_back(subset);
    }

    return result;

}
int main() {
    std::vector<int> setA={1,2,3};
    std::vector<int> setB={23,4,5,6};
    print(setA,"A");
    print(setB,"B");

    std::cout<<"|A| = "<<cardinality(setA)<<" |B| = "<<cardinality(setB)<<std::endl;
    print(power_set(setA),"P(A)");

    return 0;
}
