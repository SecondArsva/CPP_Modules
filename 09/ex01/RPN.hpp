#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN();
    ~RPN();

    // Evalúa la expresión RPN (tokens separados por espacios).
    // Devuelve true si OK; en ese caso 'result' contiene el valor.
    // En caso de error devuelve false.
    bool evaluate(const std::string& expr, long& result) const;

private:
    static bool isSpace(char c);
    static bool isDigit(char c);
    static bool isOperator(const std::string& tok);
    static bool tokenizeNext(const std::string& s, std::string::size_type& i, std::string& tok);
    static bool applyOp(long a, long b, char op, long& out); // a op b
};

#endif
