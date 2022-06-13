#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string path {"/Users/maxim/Desktop/internTasks/wgTestTask1/file.txt"}; //path to file.txt
    std::ifstream obj;

    obj.open(path);
    if (obj.is_open()) {
        //init strings
        std::string str, newStr;
        while (!obj.eof()) {
            //set variables to no data
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
                }
            }
        }
        std::cout << newStr << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }
    obj.close();
    return 0;
}
