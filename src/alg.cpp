// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
using namespace std;

int pr(char x) {
    if ((x == '-') || (x == '+'))
        return 2;
    else if ((x == '/') || (x == '*'))
        return 3;
    else
        return 0;
}
std::string infx2pstfx(std::string inf) {
  Tstack<char> stack;
    string str;
    for (int i = 0; i < inf.length(); i++) {
        if ((inf[i] >= '0') && (inf[i] <= '9')) {
            str += inf[i];
            str += " ";
        }
        else if ((stack.empty()) || (inf[i] == '(') || (pr(inf[i] > pr(stack.top())))) {
            stack.push(inf[i]);
        }
        else if (inf[i] == ')') {
            while (stack.top() != '(') {
                str += stack.top();
                str += ' ';
                stack.pop();
            }
            stack.pop();
        }
        else if (!stack.empty())  {
            while (pr(inf[i] <= pr(stack.top()))) {
                str += stack.top();
                str += ' ';
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }
     if (!stack.empty())
         while (!stack.empty()) {
            str += stack.top();
            str += ' ';
            stack.pop();
        }
    return str;
}
int eval(std::string pst) {
  Tstack<char> stack;
  int result, n1, n2;
        for (int i = 0; i < pst.length(); i++) {
            if ((pst[i] >= '0') && (pst[i] <= '9'))
                stack.push(pst[i] - '0');
            else if (pst[i] != ' ') {
                n2 = stack.top();
                stack.pop();
                n1 = stack.top();
                stack.pop();
                if (pst[i] == '+')
                    stack.push(n1 + n2);
                if (pst[i] == '-')
                    stack.push(n1 - n2);
                if (pst[i] == '*')
                    stack.push(n1 * n2);
                if (pst[i] == '/')
                    stack.push(n1 / n2);
            }
        }
        result = stack.top();
        return result;
}
