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
        std::string str, newStr;
        while (!obj.eof()) {
            //set variable to no data
            str.clear();
            //get string from file.txt
            getline(obj,str);
            if (str.length() != 0) {
                //init and find ';'
                size_t posSemi = str.find(';');
                //cut string after semicolon
                std::string tempString {str, posSemi + 1, str.size()};
                //init and converting a string value into an int value
                int tempNumber = stoi(tempString);
                //find the second runner
                if (tempNumber == 2) {
                    newStr = str.substr(0, posSemi);
                    break;
                }
            }
        }
        std::cout << newStr << std::endl;
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
