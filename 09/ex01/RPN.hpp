#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    // Lanza std::runtime_error en caso de expresión inválida
    static int evaluate(const std::string& expr);

private:
    static bool isOperator(char c);
    static int  applyOp(int lhs, int rhs, char op); // lhs op rhs (¡ojo al orden!)
};

#endif
