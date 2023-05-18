#include <stdio.h>
#include <stack>
#include <malloc.h>
#define MaxSize 100
using namespace std;

typedef char ElemType;

/*
TODO:定义一个结构体,成员：
  ElemType类型变量data，存储数据元素值；
  该结构体指针lchild，指向左孩子结点；
  该结构体指针rchild，指向右孩子结点
*/
typedef struct node
{
	ElemType data;
	node* lchild;
	node* rchild;
	//to check if is right child
	bool toRightChild;
	node()
	{
		lchild = NULL;
		rchild = NULL;
		toRightChild = false;
	}
} BTNode;

/*
TODO:完成利用特定格式字符串生成二叉树的功能.
功能描述:利用一个字符串生成二叉树树并赋值给由链式存储结构的二叉树的指针.
	  定义指针数组作为顺序栈用于辅助,循环判断字符串中每个字符,遇到'\0'退出,
	  如果遇到左括号，代表左子结点开始，则当前结点进栈,
	  如果遇到右括号，代表结束了孩子结点排列，退栈，
	  如果遇到','，代表右子结点开始，栈顶结点的右子结点，
	  其他字符代表普通具体结点值，结点指针分配相应空间,并赋值结点值,所有孩子结点赋空,
	  如果树空，则结点赋给树指针，否则将其作为栈顶结点的一个孩子，根据左右子结点标识赋给对应子结点指针.
参数说明:b-要赋值生成的二叉树的指针引用,str-目标字符串的指针.
返回值说明:无.
举例说明:如果字符串是"A(B,C)",则代表树A是根,A有左右两个孩子B,C
		如果字符串是"A(B(C)",则代表树A是根,A有一个左孩子B,B有一个左孩子C
*/
void CreateBTree(BTNode*& b, char* str)	//创建二叉树
{
	if (str == NULL)
	{
		return;
	}
	BTNode* currentNode = (BTNode *)malloc(sizeof(BTNode));
	//定义指针数组作为顺序栈用于辅助
	std::stack<BTNode *> tempStack;
	//循环判断字符串中每个字符,遇到'\0'退出
	for (int i = 0; str[i] != '\0'; i++)
	{
		//如果遇到左括号，代表左子结点开始，则当前结点进栈
		if (str[i] == '(')
		{
			tempStack.push(currentNode);
		}
		//如果遇到右括号，代表结束了孩子结点排列，退栈
		else if (str[i] == ')')
		{
			tempStack.pop();
		}
		//如果遇到','，代表右子结点开始，栈顶结点的右子结点
		else if (str[i] == ',')
		{
			tempStack.top()->toRightChild = true;
		}
		//其他字符代表普通具体结点值，结点指针分配相应空间, 并赋值结点值, 所有孩子结点赋空
		else
		{
			BTNode* newNode = (BTNode *)malloc(sizeof(BTNode));

			newNode->data = str[i];
			newNode->lchild = NULL;
			newNode->rchild = NULL;
			newNode->toRightChild = false;

			//temp pointer points to the current node
			currentNode = newNode;

			//如果树空，则结点赋给树指针，否则将其作为栈顶结点的一个孩子，根据左右子结点标识赋给对应子结点指针
			if (b == NULL)
			{
				b = currentNode;
			}
			else
			{
				if (tempStack.empty() == false)
				{
					//to left child
					if (tempStack.top()->toRightChild == false)
					{
						tempStack.top()->lchild = newNode;
					}
					//to right child
					else
					{
						tempStack.top()->rchild = newNode;
					}
				}
			}
		}
		
	}
}

/*
TODO:完成销毁二叉树的功能.
功能描述:利用递归方式释放二叉树每一个结点所分配的空间.
参数说明:b-目标二叉树的指针引用.
返回值说明:无.
*/
void DestroyBTree(BTNode* b)	//销毁二叉树
{
	if (b == NULL)
	{
		return;
	}
	DestroyBTree(b->lchild);
	DestroyBTree(b->rchild);
	free(b);
	return;
}

/*
TODO:查找二叉树中结点数据值等于x的结点
功能描述：利用递归方式从二叉树的根结点开始，查找结点数据值等于x的结点
		 当传入的结点b为空时，返回NULL；当传入的结点b的数据值等于x时，返回指向该结点的指针
参数说明：b-目标二叉树的指针引用
		 x-查找的结点数据值
返回值说明：结点b为空时，返回NULL；结点b的数据值等于x时，返回该结点的指针
*/
BTNode* FindNode(BTNode* b, ElemType x) //查找值为x的结点
{
	//当传入的结点b为空时，返回NULL
	if (b == NULL)
	{
		return NULL;
	}
	//利用递归方式从二叉树的根结点开始，查找结点数据值等于x的结点
	//visit the node
	if (b->data == x)
	{
		return b;
	}

	if (FindNode(b->lchild, x) != NULL)
	{
		return FindNode(b->lchild, x);
	}
	else if (FindNode(b->rchild, x) != NULL)
	{
		return FindNode(b->rchild, x);
	}
	else
	{
		return NULL;
	}
}

BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}

BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}

/*
TODO:完成求二叉树的高度的功能.
功能描述:利用递归方式取左右孩子个数最大值.
  如果结点b为空，如果为空，则返回0
  如果结点b不为空，调用函数BTHeight()，传入b左右子结点，求左右子树的高度
  取左右子树高度的最大值加1进行返回
参数说明:b-目标二叉树的指针.
返回值说明:二叉树高度数值,当树为空时,返回0.
*/
int BTHeight(BTNode* b)		//求二叉树b的高度
{
	if (b == NULL)
	{
		return 0;
	}
	else
	{
		return (max(BTHeight(b->lchild), BTHeight(b->rchild)) + 1);
	}
}

void DispBTree(BTNode* b)  //以括号表示法输出二叉树
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");						//有孩子结点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild != NULL) printf(",");	//有右孩子结点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出)
		}
	}
}

int main()
{
	BTNode* b = NULL, * p, * lp, * rp;
	printf("二叉树的基本运算如下:\n");
	printf("  (1)创建二叉树\n");
	char str[40] = "";
	scanf("%s", str);
	str[39] = '\0';

	/*
	TODO:调用函数CreateBTree()，传入参数b、str，创建二叉树
	*/
	CreateBTree(b, str);

	printf("  (2)输出二叉树:");

	/*
	TODO:调用函数DispBTree()，传入参数b，输出二叉树
	*/
	DispBTree(b);

	printf("\n");
	printf("  (3)H结点:");
	/*
	TODO:调用函数FindNode()，传入参数b、'H'，查找二叉树中结点的数据值等于'H'的结点，将函数返回结果赋给p
	*/
	p = FindNode(b, 'H');

	if (p != NULL)
	{

		/*
		TODO:调用函数LchildNode()，传入参数p，获取p的左子结点，将函数返回结果赋给lp
		*/
		lp = LchildNode(p);

		if (lp != NULL)
			printf("左孩子为%c ", lp->data);
		else
			printf("无左孩子 ");

		/*
		TODO:调用函数RchildNode()，传入参数p，获取p的右子结点，将函数返回结果赋给rp
		*/
		rp = RchildNode(p);

		if (rp != NULL)
			printf("右孩子为%c", rp->data);
		else
			printf("无右孩子 ");
	}
	printf("\n");

	printf("  (4)二叉树b的高度:%d\n", BTHeight(b));
	printf("  (5)释放二叉树b\n");

	/*
	TODO:调用函数DestroyBTree()，传入参数b，销毁二叉树
	*/
	DestroyBTree(b);

	return 0;
}
