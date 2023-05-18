/*1.3 顺序栈

	bool Push(const T item)		//1.3-a. 入栈操作，并判断栈是否为满
	bool Pop(T& item)			//1.3-b 出栈操作，并判断栈是否为空，返回栈顶元素
	bool Top(T& item)			//1.3-c 读取栈顶元素，但不删除，判断栈是否为空

*/
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
    void Clear();
    bool Push(const T item);
    bool Pop(T& item);
    bool Top(T& item);
    bool IsEmpty();
    bool IsFull;
};

template <class T>
class ArrayStack : public Stack<T> {
public:
    ArrayStack(int size)
    {
        maxSize = size;
        top = -1;
        st = new T[maxSize];
    }
    ArrayStack()
    {
        top = -1;
    }
    ~ArrayStack()
    {
        delete[] st;
    }
    void Clear()
    {
        top = -1;
    }
    /*
	TODO:1.3-a. 入栈操作，并判断栈是否为满,若栈已满，则打印cout << "栈满溢出" << endl;返回false。否则将item入栈，返回true
	返回值说明：成功入栈，返回true，否则返回false。
	 */
    bool Push(const T item)
    {
      if(top>=maxSize-1)
      {
        cout << "栈满溢出" << endl;
        return false;
      }
      top++;
      st[top]=item;
      return true;
    }
    /*
	TODO:1.3-b 出栈操作，并判断栈是否为空，若为空，则打印cout << "栈为空，不能进行删除操作" << endl;返回false。
	否则，将栈顶元素的值取出来赋值给item，进行出栈操作，返回true
	返回值说明：如果出栈成功，返回true，否则返回false。
	 */
    bool Pop(T& item)
    {
      if(top==-1)
      {
        cout << "栈为空，不能进行删除操作" << endl;
        return false;
      }
      item=st[top];
      top--;
      return true;
    }
    /*
	TODO:1.3-c 读取栈顶元素，但不删除，判断栈是否为空,若为空，则打印cout << "栈为空，不能读取栈顶元素" << endl;返回false
	否则，将栈顶元素取出，并赋值给item，返回true。
	返回值说明：成功读取栈顶元素，返回true，否则返回false。
	 */
    bool Top(T& item)
    {
      if(top==-1)
      {
        cout << "栈为空，不能读取栈顶元素" << endl;
        return false;
      }
      item=st[top];
      return true;
    }

private:
    int maxSize; //栈中最多保存的元素个数
    int top; //指向栈顶，初始化为-1，入栈时top+1，出栈时top-1
    T* st; //栈
};

int main()
{
    int maxsize, loop_num, temp;
    cin >> maxsize >> loop_num >> temp;

    ArrayStack<int> as(maxsize);
    for (int i = 1; i < loop_num; i++) {
        as.Push(i);
    }
    as.Push(temp);
    cout << "入栈：" << temp << endl;
    as.Pop(temp);
    cout << "出栈:" << temp << endl;
    as.Top(temp);
    cout << "读取栈顶元素:" << temp << endl;
    return 0;
}
