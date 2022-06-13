#include <iostream>
#include <vector>
#include "Symbol.h"
using namespace::std;

//Constraints
const size_t limitedSize {107};
const int requiredDist {3};

std::vector <Symbol> sort(std::vector <Symbol> &unSorted);
int findLargest (const std::vector <Symbol> &unSorted);
bool isInclude(const std::vector <Symbol> &array, char const &includeSymbol);
int countDist(const std::string &str);

void print(const std::vector <Symbol> &symbols);
std::string input();
std::vector <Symbol> create(const std::string &inputStr);

int main() {
    //variables
    string logo {};
    vector <Symbol> symbols;

    logo = input();
    symbols = create(logo);
    symbols = sort(symbols);
    print(symbols);

    return 0;
}

//count distinct characters
int countDist(const std::string &str) {
    if (!str.empty()) {
        int i{}, k{}, count{1};
        for (i = 1; i < str.size(); i++) {
            for (k = 0; k < i; k++) {
                if (str.at(i) == str.at(k)) {
                    break;
                }
            }
            if (i == k) {
                count++;
            }
        }
        return count;
    }
    return 0;
}


std::vector <Symbol> sort(std::vector <Symbol> &unSorted) {
    std::vector <Symbol> sorted;
    char temp;
    std::vector <Symbol> notInclude;
    for (auto const &arr : unSorted) {
        int index { findLargest(unSorted) };
        if (!isInclude(notInclude, unSorted[index].getSymbol()) )  {
            sorted.push_back(unSorted.at(index));
        }
        notInclude.push_back(unSorted.at(index));
        unSorted.erase(unSorted.begin() + index );
    }

    for (int i {}; i < sorted.size(); i++) {
        for (int k {i+1}; k < sorted.size(); k++) {
            if (sorted[i].getSymbol() > sorted[k].getSymbol() && sorted[i].getSize() == sorted[k].getSize()){
                temp = sorted[i].getSymbol();
                sorted[i].setSymbol(sorted[k].getSymbol());
                sorted[k].setSymbol(temp);
            }
        }
    }
    return sorted;
}

int findLargest (const std::vector <Symbol> &unSorted) {
    int largest {unSorted[0].getSize()};
    int index {0};
    for (int i {}; i < unSorted.size(); i++) {
        if (largest < unSorted[i].getSize()) {
            largest = unSorted[i].getSize();
            index = i;
        }
    }
    return index;
}

//Check if vector of symbols include repeating elements
bool isInclude(const std::vector <Symbol> &array, char const &includeSymbol) {
    for (auto const &ar : array) {
        if (ar.getSymbol() == includeSymbol) {
            return true;
        }
    }
    return false;
}

//create vector of objects from each letter of the string
std::vector <Symbol> create(const std::string &inputStr) {
    size_t countSymb {};
    vector <Symbol> temp;
    for (auto const &arStr : inputStr) {
        countSymb = count(inputStr.begin(), inputStr.end(), arStr);
        temp.emplace_back(arStr, countSymb );
    }
    return temp;
}

//input
std::string input() {
    string temp {};
    bool isAcceptable(false);

    while (!isAcceptable) {
        cout << "Write name: ";
        getline(cin, temp);
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if (temp.size() >= 3 && temp.size() < limitedSize && countDist(temp) >= requiredDist) {
            isAcceptable = true;
        } else {
            cout << "Name has at least 3 distinct characters  and less that 107 symbols" << endl;
        }
    }
    return temp;
}

//Output
void print(const std::vector <Symbol> &symbols) {
    for (int i {}; i < 3; i++) {
        cout << symbols[i].getSymbol() << " : " << symbols[i].getSize() << endl;
    }
}