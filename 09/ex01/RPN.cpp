#include "RPN.hpp"
#include <sstream>   // std::istringstream
#include <cctype>    // std::isdigit

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOp(int lhs, int rhs, char op) {
    switch (op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/':
            if (rhs == 0) throw std::runtime_error("division by zero");
            return lhs / rhs;
    }
    throw std::runtime_error("unknown operator");
}

int RPN::evaluate(const std::string& expr) {
    if (expr.empty()) throw std::runtime_error("empty expression");

    // Validación rápida de caracteres permitidos
    for (std::string::const_iterator it = expr.begin(); it != expr.end(); ++it) {
        char c = *it;
        if (!std::isdigit(c) && !isOperator(c) && c != ' ')
            throw std::runtime_error("invalid character");
    }

    std::istringstream iss(expr);
    std::string tok;
    std::stack<int> st;

    while (iss >> tok) {
        if (tok.size() == 1 && std::isdigit(tok[0])) {
            // Requisito típico del subject: operandos de 1 dígito (0–9)
            st.push(tok[0] - '0');
        } else if (tok.size() == 1 && isOperator(tok[0])) {
            if (st.size() < 2) throw std::runtime_error("not enough operands");
            int rhs = st.top(); st.pop();
            int lhs = st.top(); st.pop();
            int res = applyOp(lhs, rhs, tok[0]);
            st.push(res);
        } else {
            // Token inválido (p.ej. multi-dígito o sin espacios correctos)
            throw std::runtime_error("invalid token");
        }
    }

    if (st.size() != 1) throw std::runtime_error("invalid expression");
    return st.top();
}
