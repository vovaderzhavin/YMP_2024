#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H
#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "Token.h"
using namespace std;

class LexicalAnalyzer {
public:
    LexicalAnalyzer(const string& input, const string& output) {
        fin.open(input);
        fout.open(output);
    };
    ~LexicalAnalyzer() {};
    void analyzer();

private:
    ifstream fin;
    ofstream fout;
    HashTable tokenList;

    bool is_operator(char c) const;
    bool is_delimiter(char c) const;
    bool is_wrong_symbol(char c) const;

    Token get_next_lexeme();
};
#endif