#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <stdexcept>

class RPN
{
    public:
        // Canonical form
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        static int evaluate(const std::string &expr);

    private:
        static bool isOperator(char c);
        static int  applyOp(int lhs, int rhs, char op);
};

#endif
