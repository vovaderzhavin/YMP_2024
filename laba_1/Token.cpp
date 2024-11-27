#include "Token.h"

int Token::get_index() {
    return index;
}

string Token::get_type() {
    switch (type) 
    {
    case TokenType::PROGRAM:
        return "PROGRAM";
    case TokenType::TYPE:
        return "TYPE";
    case TokenType::BEGIN:
        return "BEGIN";
    case TokenType::END:
        return "END";
    case TokenType::ID_NAME:
        return "ID NAME";
    case TokenType::INT_NUM:
        return "INTEGER NUMBER";
    case TokenType::REAL_NUM:
        return "REAL NUMBER";
    case TokenType::OPERATOR:
        return "OPERATOR";
    case TokenType::DELIMITER:
        return "DELIMITER";
    case TokenType::FUNC:
        return "FUNCTION";
    case TokenType::ERROR:
        return "ERROR";
    default:
        return "UNDEFINED";
    }
}