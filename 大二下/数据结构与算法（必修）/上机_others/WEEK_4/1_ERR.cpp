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
  const char END_OF_STRING='\0';
  char *result=new char(3);
  result[0]='1';result[1]='1';result[2]='1';
  stack brakets(strlen(c)+1); //"()"
  stack bracket(strlen(c)+1); //"[]"
  stack brace(strlen(c)+1); //"{}"
  int index=0;

  while(c[index]!=END_OF_STRING) //LOAD STACKS
  {
    switch (c[index]) {
      case '(':
      brakets.push(c[index]);
      break;

      case ')':
      if(!brakets.empty())
      brakets.pop();
      else result[0]='0';
      break;

      case '[':
      bracket.push(c[index]);
      break;

      case ']':
      if(!bracket.empty())
      bracket.pop();
      else result[1]='0';

      break;

      case '{':
      brace.push(c[index]);
      break;

      case '}':
      if(!brace.empty())
      brace.pop();
      else result[2]='0';

    }
    index++;
  }
  if(!brakets.empty()) result[0]='0';
  if(!bracket.empty()) result[1]='0';
  if(!brace.empty()) result[2]='0';
  return result;
}
void printResult(char* p)
{
    if (NULL != p && strlen(p) == 3) {
        if (p[0] == '1') {
            cout << "()匹配" << endl;
        } else {
            cout << "()不匹配" << endl;
        }

        if (p[1] == '1') {
            cout << "[]匹配" << endl;
        } else {
            cout << "[]不匹配" << endl;
        }

        if (p[2] == '1') {
            cout << "{}匹配" << endl;
        } else {
            cout << "{}不匹配" << endl;
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
    delete result;
    return 0;
}
