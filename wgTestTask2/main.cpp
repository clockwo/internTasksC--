#include <iostream>
#include <vector>
#include <numeric>

int findDigitNum(int x);
bool findContainsNum(int x, int n); //function looks for DigitSum(x) in the number

void printVector(const std::vector <int> &printableVector);
int setSequence();

int main() {
    //variables
    int n {setSequence()}; //change here n of sequence
    int x {3}, countRounds{}, count {};
    //setArrays
    std::vector <int> initialVector (n);
    std::iota(initialVector.begin(),initialVector.end(), 1);
    std::vector <int> workingVector;

    while (x != 0) {
        int digitNumber {findDigitNum(x)};
        for (auto const &temp : initialVector ) {
            if (temp % x != 0 && !findContainsNum(digitNumber, temp ) ) {
                workingVector.push_back(temp);
            } else {
                count++;
            }
        }
        x = count;
        count = 0;
        //PrintInfo
        printVector(workingVector);
        std::cout << "Digit number: " << findDigitNum(x) << " | X: " << x << std::endl;
        std::cout << std::endl;
        //Clearing
        initialVector.clear();
        initialVector = workingVector;
        workingVector.clear();
        countRounds++;
    }
    std::cout << "Rounds: " << countRounds << std::endl;
    return 0;
}

int setSequence() {
    int temp {};
    std::cout << "Set limit of numbers: ";
    std::cin >> temp;
    return temp;
}

void printVector(const std::vector <int> &printableVector) {
    for (auto const &ar : printableVector) {
        std::cout << ar << ' ';
    }
}

int findDigitNum(int x) {
    int digitNum {};
    while (x != 0) {
        digitNum = digitNum + x % 10;
        x = x / 10;
    }
    if (digitNum >= 10) {
        digitNum = findDigitNum(digitNum);
    }
    return digitNum;
}

bool findContainsNum(int x, int n) {
    while (n != 0) {
        int k {n % 10};
        if (k == x) {
            return true;
        }
        n = n / 10;
    }
    return false;
}