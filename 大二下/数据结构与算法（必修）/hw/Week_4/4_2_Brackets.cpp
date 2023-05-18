/*课后习题1.8-h

	h.	假设表达式中允许包含3中括号：圆括号、方括号和大括号。
		设计一个算法采用顺序栈判断表达式中的括号是否正确配对。
		void Bracketmatch(const char* c)

*/
#include <cstring>
#include <iostream>

using namespace std;
class stack {
private:
    int maxsize;
    int top;
    char* st;

public:
    stack(int size)
    {
        maxsize = size;
        top = -1;
        st = new char[maxsize];
    }

    void push(char item)
    {
        st[++top] = item;
    }

    void pop()
    {
        top--;
    }

    bool empty()
    {
        return top == -1;
    }
};
/*
TODO:计一个算法采用顺序栈判断表达式c中的括号是否正确配对。
返回值说明:返回长度为3个字符的字符串，
第1个字符表示()的匹配情况。
第2个字符表示[]的匹配情况
第3个字符表示{}的匹配情况。
如果匹配，则对应的字符设置为'1'，否则设置为'0'。
比如：返回值为"110",表示：()匹配，[]匹配，{}不匹配
 */
char* Bracketmatch(const char* c) //括号匹配
{
    char *result = new char(3);
    result[0] = '1';
    result[1] = '1';
    result[2] = '1';
    //initialize 3 stacks for 3 kinds of brackets
    //stack for ()
    stack stackParen(strlen(c));
    //stack for []
    stack stackBracket(strlen(c));
    //stack for {}
    stack stackBrace(strlen(c));

    //traverse the expression
    for (int i=0;i<strlen(c);i++)
    {
        switch (c[i])
        {
            //1. left bracket push
            case ('('):
                stackParen.push(c[i]);
                break;
            
            case ('['):
                stackBracket.push(c[i]);
                break;

            case ('{'):
                stackBrace.push(c[i]);
                break;
            
            //2. right bracket pop and check
            case (')'):
                if (stackParen.empty())
                {
                    result[0] = '0';
                }
                else
                {
                    stackParen.pop();
                    result[0] = '1';
                }
                break;
            
            case (']'):
                if (stackBracket.empty())
                {
                    result[1] = '0';
                }
                else
                {
                    stackBracket.pop();
                    result[1] = '1';
                }
                break;

            case ('}'):
                if (stackBrace.empty())
                {
                    result[2] = '0';
                }
                else
                {
                    stackBrace.pop();
                    result[2] = '1';
                }
                break;
        }
    
    }
    //after coped with the expression
    if (!stackParen.empty())
    {
        result[0] = '0';
    }
    if (!stackBracket.empty())
    {
        result[1] = '0';
    }
    if (!stackBrace.empty())
    {
        result[2] = '0';
    }

    return result;
}


void printResult(char* p)
{
    if (NULL != p) {
        if (p[0] == '1') {
            cout << "() is matched" << endl;
        } else {
            cout << "() is not matched" << endl;
        }

        if (p[1] == '1') {
            cout << "[] is matched" << endl;
        } else {
            cout << "[] is not matched" << endl;
        }

        if (p[2] == '1') {
            cout << "{} is matched" << endl;
        } else {
            cout << "{} is not matched" << endl;
        }
    }
}
int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    char* result = Bracketmatch(s.c_str());
    printResult(result);
    //delete result;

    system("pause");
    return 0;
}
