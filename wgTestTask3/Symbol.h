//
// Created by Maxim Gudkov on 07.06.2022.
//

#ifndef WGTESTTASK3_SYMBOL_H
#define WGTESTTASK3_SYMBOL_H
#include <iostream>

class Symbol {

private:
    char letter;
    size_t size;
    static constexpr const char defLetter = ' ';
    static constexpr size_t defSize = 0;
public:
    Symbol(char inputChar = defLetter, size_t inputSize = defSize);
    ~Symbol() = default;
    void setSymbol(char setChar) {letter = setChar;};
    int getSize() const {return static_cast<int>(this->size);};
    char getSymbol() const {return this->letter;};
};


#endif //WGTESTTASK3_SYMBOL_H
