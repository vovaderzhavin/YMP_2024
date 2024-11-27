#include <iostream>
#include <iomanip>
#include "HashTable.h"
using namespace std;


int HashTable::hash_function(const string& lexeme) const {
    int hash = 0;
    for (char ñ : lexeme) {
        hash = (hash * 13 + int(ñ)) % 10000;
    }
    return hash;
}

void HashTable::new_token(const Token& token) {
    int hash = hash_function(token.lexeme);
    if (tokens[hash] == nullptr) {
        tokens[hash] = new Token(token.type, token.lexeme, token_count, hash);
        ++token_count;
    }
    else {
        if (tokens[hash]->lexeme == token.lexeme) {
            return;
        }
        int new_hash = (hash + 1) % hash_size;
        while (tokens[new_hash] != nullptr) {
            new_hash = (new_hash + 1) % hash_size;
        }
        tokens[new_hash] = new Token(token.type, token.lexeme, token_count, new_hash);
        ++token_count;
    }
}

void HashTable::print_table(ofstream& fout) {
    fout << "|==================|================|=============|" << endl;
    fout << "|  Type of lexeme  |     Lexeme     |    Index    |" << endl;
    fout << "|==================|================|=============|" << endl;
    for (int i = 0; i < hash_size; i++) {
        Token* token = new Token();
        for (int j = 0; j < hash_size; j++) {
            if (tokens[j] == nullptr) {
                continue;
            }
            if (i == get_index(j)) {
                token = tokens[j];
                break;
            }
        }
        if (token->type != TokenType::UNKNOWN && token->type != TokenType::ERROR) {
            string tokenType = token->get_type();
            fout << "| " << setw(17) << left << tokenType;
            fout << setw(1) << left << "| " << setw(15) << left << token->lexeme;
            fout << setw(1) << left << "| " << setw(11) << left << token->hash << " |" << endl;
        }
    }
    fout << "|==================|================|=============|" << endl;
    for (int i = 0; i < hash_size; i++) {
        Token* token = tokens[i];
        if (tokens[i] != nullptr && token->type == TokenType::ERROR) {
            fout << "| " << setw(17) << left << "ERROR";
            fout << setw(1) << left << "| " << setw(15) << left << token->lexeme;
            fout << setw(1) << left << "| " << setw(11) << left << token->hash << " |" << endl;
        }
    }
    fout << "|==================|================|=============|" << endl;
}