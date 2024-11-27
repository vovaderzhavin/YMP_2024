#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Token.h"
#include <fstream>
using namespace std;

class HashTable {
private:
    static const int hash_size = 10000;
    int token_count;
    Token* tokens[hash_size];
public:
    HashTable() : token_count(0) {
        for (int i = 0; i < hash_size; ++i) {
            tokens[i] = nullptr;
        }
    }

    ~HashTable() {
        for (long long i = 0; i < hash_size; i++) {
            delete tokens[i];
        }
    }

    void new_token(const Token& token);
    void print_table(ofstream& fout);

    int hash_function(const string& lexeme) const;
    int get_index(int i) { return tokens[i]->get_index(); }
};
#endif