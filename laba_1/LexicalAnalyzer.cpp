#include "LexicalAnalyzer.h"
#include "Token.h"
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;


enum class State {
    START,
    ID_NAME_STATE,
    NUMBER_STATE,
    OPERATOR_STATE,
    DELIMITER_STATE,
    ERROR_STATE
};


bool LexicalAnalyzer::is_operator(char c) const {
    return (c == '+' || c == '-' || c == '=');
}

bool LexicalAnalyzer::is_delimiter(char c) const {
    return (c == '(' || c == ')' || c == ',');
}

bool LexicalAnalyzer::is_wrong_symbol(char c) const {
    bool is_num = isdigit(c);
    return (!is_delimiter(c) && !is_operator(c) && !isalpha(c) && !is_num && c != ' ');
}

Token LexicalAnalyzer::get_next_lexeme() {
    string lexeme;
    char c;
    State current_state = State::START;
    int index = 1;

    while (fin.get(c)) {
        switch (current_state) {
        case State::START: 
        {
            if (isspace(c)) {
                ++index;
                continue;
            }
            if (isalpha(c)) {
                current_state = State::ID_NAME_STATE;
                lexeme += c;
                //fin.unget();
                //fin.unget();
            }
            else if (isdigit(c)) {
                current_state = State::NUMBER_STATE;
                lexeme += c;
            }
            else if (is_operator(c)) {
                current_state = State::OPERATOR_STATE;
                lexeme += c;
            }
            else if (is_delimiter(c)) {
                current_state = State::DELIMITER_STATE;
                lexeme += c;
            }
            else {
                current_state = State::ERROR_STATE;
                lexeme += c;
            }
            break;
        }
        case State::ID_NAME_STATE:
        {
            if (isalpha(c)) {
                lexeme += c;
                //PROGRAM
                if (c == 'R' && lexeme.size() == 2) {
                    fin.get(c);
                    lexeme += c;
                    if (isdigit(c) || is_wrong_symbol(c)) {
                        current_state = State::ERROR_STATE;
                        break;
                    }
                    else if (isalpha(c)) {
                        if (c != 'O') {
                            current_state = State::ID_NAME_STATE;
                        }
                        else if (c == 'O') {
                            fin.get(c);
                            lexeme += c;
                            if (isdigit(c) || is_wrong_symbol(c)) {
                                current_state = State::ERROR_STATE;
                                break;
                            }
                            else if (isalpha(c)) {
                                if (c != 'G') {
                                    current_state = State::ID_NAME_STATE;
                                }
                                else if (c == 'G') {
                                    fin.get(c);
                                    lexeme += c;
                                    if (isdigit(c) || is_wrong_symbol(c)) {
                                        current_state = State::ERROR_STATE;
                                        break;
                                    }
                                    else if (isalpha(c)) {
                                        if (c != 'R') {
                                            current_state = State::ID_NAME_STATE;
                                        }
                                        else if (c == 'R') {
                                            fin.get(c);
                                            lexeme += c;
                                            if (isdigit(c) || is_wrong_symbol(c)) {
                                                current_state = State::ERROR_STATE;
                                                break;
                                            }
                                            else if (isalpha(c)) {
                                                if (c != 'A') {
                                                    current_state = State::ID_NAME_STATE;
                                                }
                                                else if (c == 'A') {
                                                    fin.get(c);
                                                    lexeme += c;
                                                    if (isdigit(c) || is_wrong_symbol(c)) {
                                                        current_state = State::ERROR_STATE;
                                                        break;
                                                    }
                                                    else if (isalpha(c)) {
                                                        if (c != 'M') {
                                                            current_state = State::ID_NAME_STATE;
                                                        }
                                                        else if (c == 'M') {
                                                            fin.get(c);
                                                            lexeme += c;
                                                            if (isdigit(c) || is_wrong_symbol(c)) {
                                                                current_state = State::ERROR_STATE;
                                                                break;
                                                            }
                                                            else if (isalpha(c)) {
                                                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                                                            }
                                                            else if (c == ' ') {
                                                                fin.unget();
                                                                return Token(TokenType::PROGRAM, lexeme, index, 0);
                                                            }
                                                        }
                                                    }
                                                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                                        fin.unget();
                                                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                                                    }
                                                }
                                            }
                                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                                fin.unget();
                                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                                            }
                                        }
                                    }
                                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                        fin.unget();
                                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                                    }
                                }
                            }
                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                fin.unget();
                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                            }
                        }
                    }
                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                        fin.unget();
                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                    }

                }
                //INTEGER
                else if (c == 'N' && lexeme == "IN") {
                    fin.get(c);
                    lexeme += c;
                    if (isdigit(c) || is_wrong_symbol(c)) {
                        current_state = State::ERROR_STATE;
                        break;
                    }
                    else if (isalpha(c)) {
                        if (c != 'T') {
                            current_state = State::ID_NAME_STATE;
                        }
                        else if (c == 'T') {
                            fin.get(c);
                            lexeme += c;
                            if (isdigit(c) || is_wrong_symbol(c)) {
                                current_state = State::ERROR_STATE;
                                break;
                            }
                            else if (isalpha(c)) {
                                if (c != 'E') {
                                    current_state = State::ID_NAME_STATE;
                                }
                                else if (c == 'E') {
                                    fin.get(c);
                                    lexeme += c;
                                    if (isdigit(c) || is_wrong_symbol(c)) {
                                        current_state = State::ERROR_STATE;
                                        break;
                                    }
                                    else if (isalpha(c)) {
                                        if (c != 'G') {
                                            current_state = State::ID_NAME_STATE;
                                        }
                                        else if (c == 'G') {
                                            fin.get(c);
                                            lexeme += c;
                                            if (isdigit(c) || is_wrong_symbol(c)) {
                                                current_state = State::ERROR_STATE;
                                                break;
                                            }
                                            else if (isalpha(c)) {
                                                if (c != 'E') {
                                                    current_state = State::ID_NAME_STATE;
                                                }
                                                else if (c == 'E') {
                                                    fin.get(c);
                                                    lexeme += c;
                                                    if (isdigit(c) || is_wrong_symbol(c)) {
                                                        current_state = State::ERROR_STATE;
                                                        break;
                                                    }
                                                    else if (isalpha(c)) {
                                                        if (c != 'R') {
                                                            current_state = State::ID_NAME_STATE;
                                                        }
                                                        else if (c == 'R') {
                                                            fin.get(c);
                                                            lexeme += c;
                                                            if (isdigit(c) || is_wrong_symbol(c) || is_operator(c) || is_delimiter(c)) {
                                                                current_state = State::ERROR_STATE;
                                                                break;
                                                            }
                                                            else if (isalpha(c)) {
                                                                current_state = State::ID_NAME_STATE;
                                                            }
                                                            else if (c == ' ') {
                                                                fin.unget();
                                                                return Token(TokenType::TYPE, lexeme, index, 0);
                                                            }
                                                        }
                                                    }
                                                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                                        fin.unget();
                                                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                                                    }
                                                }
                                            }
                                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                                fin.unget();
                                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                                            }
                                        }
                                    }
                                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                        fin.unget();
                                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                                    }
                                }
                            }
                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                fin.unget();
                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                            }
                        }
                        else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                            fin.unget();
                            return Token(TokenType::ID_NAME, lexeme, index, 0);
                        }
                    }
                }
                //ITOR
                else if (c == 'T' && lexeme == "IT") {
                    fin.get(c);
                    lexeme += c;
                    if (isdigit(c) || is_wrong_symbol(c)) {
                        current_state = State::ERROR_STATE;
                        break;
                    }
                    else if (isalpha(c)) {
                        if (c != 'O') {
                            current_state = State::ID_NAME_STATE;
                        }
                        else if (c == 'O') {
                            fin.get(c);
                            lexeme += c;
                            if (isdigit(c) || is_wrong_symbol(c)) {
                                current_state = State::ERROR_STATE;
                                break;
                            }
                            else if (isalpha(c)) {
                                if (c != 'R' && c != 'D') {
                                    current_state = State::ID_NAME_STATE;
                                }
                                else if (c == 'R') {
                                    fin.get(c);
                                    lexeme += c;
                                    if (isdigit(c) || is_wrong_symbol(c)) {
                                        current_state = State::ERROR_STATE;
                                        break;
                                    }
                                    else if (isalpha(c)) {
                                        current_state = State::ID_NAME_STATE;
                                    }
                                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                        fin.unget();
                                        lexeme.erase(lexeme.end() - 1);
                                        return Token(TokenType::FUNC, lexeme, index, 0);
                                    }
                                }
                                else if (c == 'D') {
                                    fin.get(c);
                                    lexeme += c;
                                    if (isdigit(c) || is_wrong_symbol(c)) {
                                        current_state = State::ERROR_STATE;
                                        break;
                                    }
                                    else if (isalpha(c)) {
                                        current_state = State::ID_NAME_STATE;
                                    }
                                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                        fin.unget();
                                        lexeme.erase(lexeme.end() - 1);
                                        return Token(TokenType::FUNC, lexeme, index, 0);
                                    }
                                }
                            }
                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                fin.unget();
                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                            }
                        }
                    }
                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                        fin.unget();
                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                    }
                }
                //REAL
                else if (c == 'E' && lexeme == "RE") {
                    fin.get(c);
                    lexeme += c;
                    if (isdigit(c) || is_wrong_symbol(c)) {
                        current_state = State::ERROR_STATE;
                        break;
                    }
                    else if (isalpha(c)) {
                        if (c != 'A') {
                            current_state = State::ID_NAME_STATE;
                        }
                        else if (c == 'A') {
                            fin.get(c);
                            lexeme += c;
                            if (isdigit(c) || is_wrong_symbol(c)) {
                                current_state = State::ERROR_STATE;
                                break;
                            }
                            else if (isalpha(c)) {
                                if (c != 'L') {
                                    current_state = State::ID_NAME_STATE;
                                }
                                else if (c == 'L') {
                                    fin.get(c);
                                    lexeme += c;
                                    if (isdigit(c) || is_wrong_symbol(c) || is_operator(c) || is_delimiter(c)) {
                                        current_state = State::ERROR_STATE;
                                        break;
                                    }
                                    else if (isalpha(c)) {
                                        current_state = State::ID_NAME_STATE;
                                    }
                                    else if (c == ' ') {
                                        fin.unget();
                                        return Token(TokenType::TYPE, lexeme, index, 0);
                                    }
                                }
                            }
                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                fin.unget();
                                return Token(TokenType::ID_NAME, lexeme, index, 0);
                            }
                        }
                    }
                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                        fin.unget();
                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                    }
                }
                //END
                else if (c == 'N' && lexeme == "EN") {
                    fin.get(c);
                    lexeme += c;
                    if (isdigit(c) || is_wrong_symbol(c)) {
                        current_state = State::ERROR_STATE;
                        break;
                    }
                    else if (isalpha(c)) {
                        if (c != 'D') {
                            current_state = State::ID_NAME_STATE;
                        }
                        else if (c == 'D') {
                            fin.get(c);
                            lexeme += c;
                            if (isdigit(c) || is_wrong_symbol(c)) {
                                current_state = State::ERROR_STATE;
                                break;
                            }
                            else if (isalpha(c)) {
                                current_state = State::ID_NAME_STATE;
                            }
                            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                                fin.unget();
                                return Token(TokenType::END, lexeme, index, 0);
                            }
                        }
                    }
                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                        fin.unget();
                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                    }
                }
                //распознование любых буквенных лексем
                else {
                    while (fin.get(c) && isalpha(c)) {
                        lexeme += c;
                    }
                    if (isdigit(c) || is_wrong_symbol(c)) {
                        current_state = State::ERROR_STATE;
                        lexeme += c;
                    }
                    else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                        fin.unget();
                        //lexeme.erase(lexeme.end() - 1);
                        return Token(TokenType::ID_NAME, lexeme, index, 0);
                    }
                }
            }
            else if (isdigit(c) || is_wrong_symbol(c)) {
                current_state = State::ERROR_STATE;
                lexeme += c;
            }
            else if (is_delimiter(c) || is_operator(c) || c == ' ') {
                fin.unget();
                //lexeme.erase(lexeme.end() - 1);
                return Token(TokenType::ID_NAME, lexeme, index, 0);
            }
            break;
        }
        case State::NUMBER_STATE:
        {
            if (isdigit(c)) {
                lexeme += c;
            }
            else if (c == '.') {
                lexeme += c;
            }
            else if (isalpha(c)) {
                lexeme += c;
                current_state = State::ERROR_STATE;
            }
            else {
                fin.unget();
                if (lexeme.find('.') != -1) {
                    return Token(TokenType::REAL_NUM, lexeme, index, 0);
                }
                else {
                    return Token(TokenType::INT_NUM, lexeme, index, 0);
                }
            }
            break;
        }
        case State::OPERATOR_STATE:
        {
            fin.unget();
            return Token(TokenType::OPERATOR, lexeme, index, 0);
        }
        case State::DELIMITER_STATE:
        {
            fin.unget();
            return Token(TokenType::DELIMITER, lexeme, index, 0);
        }
        case State::ERROR_STATE:
        {
            if (isspace(c) || is_delimiter(c) || is_operator(c)) {
                fin.unget();
                return Token(TokenType::ERROR, lexeme, index, 0);
            }
            else {
                lexeme += c;
            }
            break;
        }
        }
    }
    return Token(TokenType::UNKNOWN, "", index, 0);
}

void LexicalAnalyzer::analyzer() {
    Token token;
    while ((token = get_next_lexeme()).type != TokenType::UNKNOWN) {
        tokenList.new_token(token);
    }
    tokenList.print_table(fout);
}

