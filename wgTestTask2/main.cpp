#include <iostream>
#include <vector>

int findDig(int x);
bool findIncludeDig(int x, int n);
std::vector <int> createVector(const int &n);

void printFirstSequence(const std::vector <int> &arr, const int &x);

int main() {
    //variables
    int x {3}, n {20} , countRounds{}, count {}; //change here n of sequence
    //setArrays
    std::vector <int> arr = createVector(n);
    std::vector <int> arrSecond;

    printFirstSequence(arr, x);

    while (x != 0) {
        int digNumber {findDig(x)};
        for (int i{}; i < arr.size(); i++) {
            if (arr.at(i) % x != 0 && !findIncludeDig(digNumber, arr.at(i) )) {
                arrSecond.push_back(arr.at(i));
            } else {
                count++;
            }
        }
        x = count;
        count = 0;
        for (auto const &ar : arrSecond) {
            std::cout << ar << ' ';
        }
        std::cout << "Digit number: " << findDig(x) << " | X: " << x << std::endl;
        std::cout << std::endl;
        arr.clear();
        arr = arrSecond;
        arrSecond.clear();
        countRounds++;
    }
    std::cout << "Rounds: " << countRounds << std::endl;
    return 0;
}

void printFirstSequence(const std::vector <int> &arr, const int &x){
    for (auto const &ar : arr) {
        std::cout << ar << ' ';
    }
    std::cout << "Digit number: " << findDig(x) << " | X: " << x << std::endl;
    std::cout << std::endl;
}

std::vector <int> createVector(const int &n) {
    std::vector <int> tempVector;
    for (int i {1}; i <= n; i++) {
        tempVector.push_back(i);
    }
    return tempVector;
}

int findDig(int x) {
    int dignum {};
    while (x != 0) {
        dignum = dignum + x % 10;
        x = x / 10;
    }
    if (dignum >= 10) {
        dignum = findDig(dignum);
    }
    return dignum;
}

bool findIncludeDig(int x, int n) {
    while (n != 0) {
        int k {n % 10};
        if (k == x) {
            return true;
        }
        n = n / 10;
    }
    return false;
}