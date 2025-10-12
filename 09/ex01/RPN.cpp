#include "RPN.hpp"
#include <stack>
#include <cstdlib>
#include <cstring>

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

bool RPN::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool RPN::isOperator(const std::string& tok) {
    return tok.size() == 1 &&
           (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/');
}

bool RPN::tokenizeNext(const std::string& s, std::string::size_type& i, std::string& tok) {
    // saltar espacios
    while (i < s.size() && isSpace(s[i])) ++i;
    if (i >= s.size()) return false;

    // tomar hasta próximo espacio
    std::string::size_type j = i;
    while (j < s.size() && !isSpace(s[j])) ++j;

    tok = s.substr(i, j - i);
    i = j;
    return true;
}

bool RPN::applyOp(long a, long b, char op, long& out) {
    // a (op) b  ; ojo: en RPN el orden es: primero se desapila 'a', luego 'b', y se calcula b op a
    switch (op) {
        case '+': out = b + a; return true;
        case '-': out = b - a; return true;
        case '*': out = b * a; return true;
        case '/':
            if (a == 0) return false; // división por cero -> error
            out = b / a; // división entera
            return true;
    }
    return false;
}

bool RPN::evaluate(const std::string& expr, long& result) const {
    std::stack<long> st;
    std::string::size_type i = 0;
    std::string tok;

    while (tokenizeNext(expr, i, tok)) {
        // Números: el subject dice que serán < 10 → un dígito [0-9]
        if (tok.size() == 1 && isDigit(tok[0])) {
            long v = tok[0] - '0';
            st.push(v);
        }
        else if (isOperator(tok)) {
            if (st.size() < 2) return false; // falta de operandos
            long a = st.top(); st.pop();
            long b = st.top(); st.pop();
            long out;
            if (!applyOp(a, b, tok[0], out)) return false;
            st.push(out);
        }
        else {
            // token inválido (p.ej. paréntesis, decimales, multi-dígito, etc.)
            return false;
        }
    }

    if (st.size() != 1) return false; // expresión mal formada
    result = st.top();
    return true;
}
