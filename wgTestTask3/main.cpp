#include <iostream>
#include <string>
#include <set>
#include <algorithm>

std::string createString();
std::string getDistinctStr(const std::string &inputString); //Get string of distinctive characters

void printInfo(const std::string &inputString);

int main() {
    std::string inputStr { createString() };
    std::sort(inputStr.begin(),inputStr.end());
    printInfo(inputStr);
    return 0;
}

void printInfo(const std::string &inputString) {
    const int timer {3}; //how many letters are needed for the output
    std::string tempStr {getDistinctStr(inputString)};
    size_t firstCharSize = std::count(inputString.begin(), inputString.end(), tempStr.at(0));
    char tempChar {tempStr.at(0)};

    for (int i {}; i < timer; i++) {
        for (auto &ch: tempStr) {
            size_t tempValue = std::count(inputString.begin(), inputString.end(), ch);
            if (firstCharSize < tempValue) {
                firstCharSize = tempValue;
                tempChar = ch;
            }
        }
        tempStr.erase(std::find(tempStr.begin(), tempStr.end(), tempChar));
        std::cout << tempChar << " : " << firstCharSize << std::endl;
        //clear
        firstCharSize = 0;
    }
}

std::string createString() {
    const int lenName {107}; //Constraint
    std::string tempString;
    do {
        std::cout << "Write your company name (less than 107 symbols and has at least 3 distinct characters): ";
        getline(std::cin, tempString);
    } while (getDistinctStr(tempString).size() < 3 || tempString.size() > lenName);
    //make all lower
    transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);
    return tempString;
}

std::string getDistinctStr(const std::string &inputString) {
    std::string tempStr = inputString;
    std::set <char> chars;
    tempStr.erase(
            std::remove_if(
                    tempStr.begin(),
                    tempStr.end(),
                    [&chars] (char ch) {
                        if (chars.count(ch)) {return true;}

                        chars.insert(ch);
                        return false;
                    }
            ),
            tempStr.end()
    );
    return tempStr;
}