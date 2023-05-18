/*1.5 顺序队列

	bool EnQueue(const T item)	//1.5-a.	入队操作，判断队列是否为满
	bool DeQueue(T& item)		//1.5-b.	返回队头元素，并删除该元素，判断队列是否为空
	bool GetFront(T& item)		//1.5-c.	返回队头元素，但不删除，判断队列是否为空】

*/
#include <iostream>
using namespace std;

template <class T>
class ArrayQueue {
private:
    int maxSize; //队列最大容量
    int front;
    int rear;
    int* queue;

public:
    ArrayQueue(int size)
    {
        maxSize = size + 1;
        queue = new T[maxSize];
        front = rear = 0;
    }
    ~ArrayQueue()
    {
        delete[] queue;
    }

    void Clear()
    {
        front = rear;
    }

    /*
	TODO：1.5-a.入队操作，判断队列是否为满，如果队列已满，则输出打印cout << "队列已满，溢出" << endl;，返回false。
	否则，将值item进行入队操作。并返回true
	返回值说明：入队成功，返回true，否则返回false
	 */
    bool EnQueue(const T item)
    {
      if(IsFull()) return false;
      queue[rear]=item;
      rear=(rear+1)%maxSize;
      return true;
    }
    /*
	TODO：1.5-b.返回队头元素，并删除该元素，判断队列是否为空
	如果队列为空，则输出打印cout << "队列为空" << endl;并返回false。
	否则将队列头元素取出并赋值给item变量并删除该元素，返回true
	返回值说明：成功获取队头元素返回true，否则返回false
	 */
    bool DeQueue(T& item)
    {
      if (IsEmpty()) return false;
      item=queue[front];
      front=(front+1)%maxSize;
      return true;
    }
    /*
	TODO：1.5-c.	返回队头元素，但不删除，判断队列是否为空
	如果队列为空，则打印cout << "队列为空" << endl;并返回false。
	否则取出队头元素赋值给item，返回true。
	返回值说明：成功获取队头元素，返回true，否则返回false
	 */
    bool GetFront(T& item)
    {
      if (IsEmpty()) return false;
      item=queue[front];
      return true;
    }

    bool IsEmpty()
    {
        if (front == rear) {
            cout << "队列为空" << endl;
            return true;
        } else {
            return false;
        }
    }
    bool IsFull()
    {
        if ((rear + 1) % maxSize == front) {
            cout << "队列已满，溢出" << endl;
            return true;
        } else {
            return false;
        }
    }
};

int main()
{
    int maxsize = 0, iNum = 0, temp1 = 0, temp2 = 0, temp3 = 0;
    cin >> maxsize >> iNum >> temp1;
    ArrayQueue<int> aq(maxsize);
    for (int i = 0; i < iNum; i++) {
        aq.EnQueue(i * 3);
    }
    aq.EnQueue(temp1);
    aq.DeQueue(temp2);
    cout << "出队：" << temp2 << endl;
    aq.GetFront(temp3);
    cout << "读取队头元素：" << temp3 << endl;
    return 0;
}
