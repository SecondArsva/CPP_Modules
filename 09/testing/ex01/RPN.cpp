#include "RPN.hpp"
#include <sstream>   // std::istringstream
#include <cctype>    // std::isdigit

bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Aplica la operación indicada por operador a los operandos left-hand side y right-hand side.
// Devuelve el resultado de lhs (+,-,*,/) rhs.
// Lanza una excepción si el operador no es válido o si hay división por cero.
int RPN::applyOp(int lhs, int rhs, char op)
{
    switch (op)
    {
        case '+':
			return lhs + rhs;
        case '-':
			return lhs - rhs;
        case '*':
			return lhs * rhs;
        case '/':
            if (rhs == 0)
                throw std::runtime_error("division by zero");
            return lhs / rhs;
    }
    throw std::runtime_error("unknown operator");
}

// Evalúa una expresión en RPN contenida en 'expr'.
// Solo acepta dígitos individuales (<10) y los operadores + - * /.
// Usa una pila para procesar la expresión token a token.
// Lanza excepciones si encuentra caracteres inválidos, tokens incorrectos,
// falta de operandos, división por cero o si la expresión no reduce a un único resultado.
int RPN::evaluate(const std::string &expr)
{
    if (expr.empty())
        throw std::runtime_error("empty expression");
    for (std::string::const_iterator it = expr.begin(); it != expr.end(); ++it)
    {
        char c = *it;
        if (!std::isdigit(c) && !isOperator(c) && c != ' ')
            throw std::runtime_error("invalid character");
    }
    std::istringstream iss(expr);
    std::string tok;
    std::stack<int> st;
    while (iss >> tok)
    {
        if (tok.size() == 1 && std::isdigit(tok[0]))
            st.push(tok[0] - '0');
        else if (tok.size() == 1 && isOperator(tok[0]))
        {
            if (st.size() < 2)
                throw std::runtime_error("not enough operands");
            int rhs = st.top();
			st.pop();
            int lhs = st.top();
			st.pop();
            int res = applyOp(lhs, rhs, tok[0]);
            st.push(res);
        }
        else
            throw std::runtime_error("invalid token");
    }

    if (st.size() != 1)
        throw std::runtime_error("invalid expression");
    return st.top();
}
