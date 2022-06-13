#include <iostream>
#include <vector>
using namespace::std;

int findDig(int x);

bool findIncludeDig(int x, int n);

int main() {
    //variables
    int x {3}, n {20}, countRounds{}; //change here n of sequence

    vector <int> arr;
    vector <int> arr2;
    int count {};
    //creat massive
    for (size_t i {1}; i <= n; i++) {
        arr.push_back(i);
    }
    for (auto const &ar : arr) {
        cout << ar << ' ';
    }
    cout << "Digt number: " << findDig(x) << " | X: " << x << endl;
    cout << endl;
    while (x != 0) {
        int digNumber {findDig(x)};
        for (int i{}; i < arr.size(); i++) {
            if (arr.at(i) % x != 0 && !findIncludeDig(digNumber, arr.at(i) )) {
                arr2.push_back(arr.at(i));
            } else {
                count++;
            }
        }
        x = count;
        count = 0;
        for (auto const &ar : arr2) {
            cout << ar << ' ';
        }
        cout << "Digt number: " << findDig(x) << " | X: " << x << endl;
        cout << endl;
        arr.clear();
        arr = arr2;
        arr2.clear();
        countRounds++;
    }
    std::cout << "Rounds: " << countRounds << std::endl;
    return 0;
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
    int k {};
    while (n != 0) {
        k = n % 10;
        if (k == x) {
            return true;
        }
        n = n / 10;
    }
    return false;
}