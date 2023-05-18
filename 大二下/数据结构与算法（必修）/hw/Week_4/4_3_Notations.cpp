/*
中缀表达式转后缀表达式：
    初始化一个栈，用于暂时保存无法确定运算顺序的运算符
    1. 遇到操作数：直接加入后缀表达式
    2. 遇到界限符：遇到 “(” 直接入栈；
                  遇到 “)” 依次弹出栈内运算符并加入后缀表达式，直到弹出 “(” 为止。
    3. 遇到运算符：依次弹出栈中优先级高于或等于当前运算符的运算符，并加入后缀表达式，
                  碰到 “(” 或者栈空为止。之后将当前运算符入栈。
    处理完所有字符后，依次弹出所有运算符，加入后缀表达式。

后缀表达式的计算：
    初始化一个栈，用于保存操作数
    1. 从左往右扫描所有元素，知道处理完所有元素；
    2. 遇到操作数：压入栈；
    3. 遇到运算符：依次弹出两个栈顶元素，先出为右，后出为左，执行运算，结果压入栈。
    处理完后，栈顶元素即为结果。
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#define SIZE 20
using namespace std;

template<class T>
class SqStack
{
private:
    T data[SIZE];//data array
    int top;//stack top pointer

public:
    //initialize the sequence stack
    SqStack();
    //is empty?
    bool isEmpty();
    //push into stack top
    bool push(T);
    //delete the stack top
    bool pop(T&);
    //get the stack top
    bool getPop(T&);
    //print stack
    void printStack();
};

template<class T>
SqStack<T>::SqStack()
{
    //initialize the top pointer as -1
    //why not 0? 0 is need to store data.
    top = -1;
}

template<class T>
bool SqStack<T>::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
bool SqStack<T>::push(T e)
{
    if (top == SIZE - 1)
    {
        return false;
    }
    else
    {
        top++;
        data[top] = e;
        //is equal to data[++top]
        return true;
    }
}

template<class T>
bool SqStack<T>::pop(T& e)
{
    if (top == -1)
    {
        return false;
    }
    else
    {
        e = data[top];
        top--;
        //is equal to data[top--]
        return true;
    }
}

template<class T>
bool SqStack<T>::getPop(T& e)
{
    if (top == -1)
    {
        return false;
    }
    else
    {
        e = data[top];
        return true;
    }
}

template<class T>
void SqStack<T>::printStack()
{
    for (int i = 0; i <= top; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}


//to receive the infix notation and postfix notation
string infix;
string postfix[SIZE];
//a pointer to point the next index
int postfixLength = 0;

bool isDigit(char tempChar)
{
    if (tempChar >= '0' && tempChar <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool infixToPostfix(string infix)
{
    postfixLength = 0;
    //initialize a stack to store operators
    SqStack<string> operatorStack;
    //check the chars by order
    int i = 0;
    while (i < infix.length())
    {
        //2. 遇到界限符：遇到 “(” 直接入栈；
        //              遇到 “)” 依次弹出栈内运算符并加入后缀表达式，直到弹出 “(” 为止。
        if (infix[i] == '(' || infix[i] == ')')
        {
            //遇到 “(” 直接入栈
            if (infix[i] == '(')
            {
                //transfer 'char' into 'string', by string constructor
                string tempString(1, infix[i]);
                operatorStack.push(tempString);
            }
            //遇到 “)” 依次弹出栈内运算符并加入后缀表达式，直到弹出 “(” 为止
            else
            {
                string tempString;
                while (tempString != "(")
                {
                    operatorStack.pop(tempString);
                    if (tempString != "(")
                    {
                        postfix[postfixLength ++] = tempString;
                    }
                }
            }

            i ++;
        }
        
        //3. 遇到运算符：依次弹出栈中优先级高于或等于当前运算符的运算符，并加入后缀表达式，
        //              碰到 “(” 或者栈空为止。之后将当前运算符入栈。
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            string getNextPop;
            operatorStack.getPop(getNextPop);
            //stop when the next is '(' or stack is empty
            while (getNextPop != "(" && !operatorStack.isEmpty())
            {
                //1. when '*' or '/', only pop '*' or '/', otherwise stop
                if (infix[i] == '*' || infix[i] == '/')
                {
                    operatorStack.getPop(getNextPop);
                    if (getNextPop == "*" || getNextPop == "/")
                    {
                        string nextPop;
                        operatorStack.pop(nextPop);
                        postfix[postfixLength ++] = nextPop;                       
                    }
                    else
                    {
                        break;
                    }
                }
                //2. when '+' or '-', pop all in order
                else
                {
                    string nextPop;
                    operatorStack.pop(nextPop);
                    postfix[postfixLength ++] = nextPop;
                }

                operatorStack.getPop(getNextPop);
            }

            string tempString(1, infix[i]);
            operatorStack.push(tempString);

            i ++;
        }

        //1. 遇到操作数：直接加入后缀表达式
        else
        {
            string tempNum(1, infix[i]);
            //check if the operand has 2 or more bits
            int j = i + 1;
            while (isDigit(infix[j]))
            {
                string tempString(1, infix[j]);
                tempNum = tempNum + tempString;
                j ++;
            }

            postfix[postfixLength ++] = tempNum;
            
            i = j;
        }
    }
    //after checking all the chars, if the stack is not empty
    //pop the operators by order
    while (!operatorStack.isEmpty())
    {
        string tempString;
        string nextPop;
        
        operatorStack.pop(nextPop);
        postfix[postfixLength ++] = nextPop;
    }

    return true;
}

int calPostfix(string postfix[])
{
    //initialize a stack to store operands
    SqStack<int> operandStack;
    //check strs by order
    int i = 0;
    while (i < postfixLength)
    {
        //3. 遇到运算符：依次弹出两个栈顶元素，先出为右，后出为左，执行运算，结果压入栈
        if (postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "*" || postfix[i] == "/")
        {
            int operandLeft;
            int operandRight;
            //first is right, last is left
            operandStack.pop(operandRight);
            operandStack.pop(operandLeft);
            //execute the operation
            if (postfix[i] == "+")
            {
                operandStack.push(operandLeft + operandRight);
            }
            else if (postfix[i] == "-")
            {
                operandStack.push(operandLeft - operandRight);
            }
            else if (postfix[i] == "*")
            {
                operandStack.push(operandLeft * operandRight);
            }
            else if (postfix[i] == "/")
            {
                operandStack.push(operandLeft / operandRight);
            }
        }

        //2. 遇到操作数：压入栈
        else
        {
            int tempInt = atoi(postfix[i].c_str());
            operandStack.push(tempInt);
        }

        i ++;
    }

    if (!operandStack.isEmpty())
    {
        int result;
        operandStack.pop(result);
        return result;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cout << "输入一个中缀表达式：" << endl;
    cin >> infix;
    infixToPostfix(infix);
    cout << "表达式计算结果:" << endl;
    cout << calPostfix(postfix) << endl;

    system("pause");
    return 0;
}