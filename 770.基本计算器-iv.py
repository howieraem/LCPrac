#
# @lc app=leetcode.cn id=770 lang=python3
#
# [770] 基本计算器 IV
#

# @lc code=start
class Term:
    def __init__(self, coeff=0, var=''):
        self.coeff = coeff
        self.vars = []
        if var:
            self.vars.append(var)

    def __compareTo(self, other):
        nvars = len(self.vars)
        if nvars == len(other.vars):
            i = 0
            while i < nvars and self.vars[i] == other.vars[i]:
                i += 1
            if i == nvars:
                return 0
            var1, var2 = self.vars[i], other.vars[i]
            if var1 < var2:
                return -1
            elif var1 == var2:
                return 0
            return 1
        return len(other.vars) - len(self.vars)

    def __lt__ (self, other):
        return self.__compareTo(other) < 0

    def __gt__ (self, other):
        return other.__lt__(self)

    def __eq__ (self, other):
        return not self.__compareTo(other)

    def __ne__ (self, other):
        return self.__compareTo(other) != 0
    
    def __str__(self):
        s = '%d' % self.coeff
        for var in self.vars:
            s += '*%s' % var
        return s

    def __mul__(self, other):
        ret = Term(coeff=self.coeff * other.coeff)
        ret.vars = self.vars + other.vars
        ret.vars.sort()
        return ret

    def __rmul__(self, other):
        return self.__mul__(other)


class Expr:
    def __init__(self, term):
        self.terms = [term]

    def add(self, other):
        self.terms.extend(other.terms)
        self.terms.sort()
        self.simplify()

    def mul(self, other):
        ret = []
        for term1 in self.terms:
            for term2 in other.terms:
                ret.append(term1 * term2)
        self.terms = ret
        self.terms.sort()
        self.simplify()

    def operate(self, other, op):
        if op == '+':
            self.add(other)
        elif op == '-':
            for term in other.terms:
                term.coeff *= -1
            self.add(other)
        else:
            self.mul(other)
        return self

    def simplify(self):
        for i in range(len(self.terms)):
            while i < len(self.terms) - 1 and self.terms[i] == self.terms[i + 1]:
                self.terms[i].coeff += self.terms[i + 1].coeff
                del self.terms[i + 1]
            if i < len(self.terms) and self.terms[i].coeff == 0:
                del self.terms[i]
                i -= 1


class Solution:
    def basicCalculatorIV(self, expression: str, evalvars: List[str], evalints: List[int]) -> List[str]:
        d = dict(zip(evalvars, evalints))

        main_stack, op_stack = [], []
        i, n = 0, len(expression)
        while i < n:
            if expression[i] == ' ':
                i += 1
            elif expression[i].isdigit():
                x = 0
                while i < n and expression[i].isdigit():
                    x = x * 10 + int(expression[i])
                    i += 1
                main_stack.append(Expr(Term(x)))
            elif expression[i].isalpha():
                s = ''
                while i < n and expression[i].isalpha():
                    s += expression[i]
                    i += 1
                if s in d:
                    main_stack.append(Expr(Term(d[s])))
                else:
                    main_stack.append(Expr(Term(1, s)))
            elif expression[i] == '(':
                op_stack.append('(')
                i += 1
            elif expression[i] == ')':
                while len(op_stack) and op_stack[-1] != '(':
                    expr2 = main_stack.pop()
                    expr1 = main_stack.pop()
                    main_stack.append(expr1.operate(expr2, op_stack.pop()))
                op_stack.pop()
                i += 1
            elif expression[i] == '*':
                while len(op_stack) and op_stack[-1] == '*':
                    expr2 = main_stack.pop()
                    expr1 = main_stack.pop()
                    main_stack.append(expr1.operate(expr2, op_stack.pop()))
                op_stack.append('*')
                i += 1
            else:
                while len(op_stack) and \
                    (op_stack[-1] == '+' or 
                     op_stack[-1] == '-' or
                     op_stack[-1] == '*'):
                    expr2 = main_stack.pop()
                    expr1 = main_stack.pop()
                    main_stack.append(expr1.operate(expr2, op_stack.pop()))
                op_stack.append('+' if expression[i] == '+' else '-')
                i += 1

        while len(op_stack):
            expr2 = main_stack.pop()
            expr1 = main_stack.pop()
            main_stack.append(expr1.operate(expr2, op_stack.pop()))

        expr = main_stack.pop()
        expr.simplify()
        return [str(term) for term in expr.terms]

# @lc code=end
