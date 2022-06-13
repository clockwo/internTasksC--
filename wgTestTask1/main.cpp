#include <iostream>
#include <fstream>
#include <string>
using namespace::std;

int main() {

    std::string path {"/Users/maxim/CLionProjects/wgTestTask1/file.txt"}; //path to file.txt
    std::ifstream obj;
    obj.open(path);
    if (obj.is_open()) {
        std::string str;
        std::string newStr;
        size_t posSemi {};
        int tempNumber {};
        while (!obj.eof()) {
            posSemi = 0;
            str = "";
            getline(obj,str);
            //find ';'
            if (str.length() != 0) {
                posSemi = str.find(";");
                std::string tempString {str, posSemi + 1, str.size()};
                tempNumber = stoi(tempString);
                //find number 2
                if (tempNumber == 2) {
                   newStr = str.substr(0, posSemi);
                }
            }
        }
        cout << newStr << endl;
    } else {
        std::cout << "0" << std::endl;
    }
    obj.close();
    return 0;
}
