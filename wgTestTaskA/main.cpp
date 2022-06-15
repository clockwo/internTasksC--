#include <iostream>
#include <fstream>
#include <string>

std::string setPath();

int main() {

    std::string path { setPath() };
    std::ifstream obj;

    obj.open(path);
    if (obj.is_open()) {
        //init strings
        std::string inputStr, nameStr;
        while (!obj.eof()) {
            //set variable to no data
            inputStr.clear();
            //get string from file.txt
            getline(obj,inputStr);
            if (inputStr.length() != 0) {
                //init and find ';'
                size_t posSemi = inputStr.find(';');
                //cut string after semicolon
                std::string tempString {inputStr, posSemi + 1, inputStr.size()};
                //init and converting a string value into an int value
                int tempNumber = stoi(tempString);
                //find the second runner
                if (tempNumber == 2) {
                    nameStr = inputStr.substr(0, posSemi);
                    break;
                }
            }
        }
        std::cout << nameStr << std::endl;
    } else {
        std::cout << "The file does not exist or cannot be opened." << std::endl;
    }
    obj.close();
    return 0;
}

std::string setPath() {
    std::string temp;
    std::cout << "Set path to file: ";
    getline(std::cin, temp);
    return temp;
}
