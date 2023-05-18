//AVL算法
#include <stdio.h>
#include <malloc.h>
typedef int KeyType;					//关键字类型
typedef char InfoType;

/*
TODO:定义一个平衡二叉树结构体，成员：
  KeyType类型变量key，存储关键字；
  int型变量bf，存储平衡因子
  InfoType型变量data，存储数据；
  两个该平衡二叉树结构体类型指针lchild，rchild，指向其左右孩子结点.
*/
typedef struct node               		//记录类型
{
	//key
	KeyType key;
	//data
	InfoType data;
	//balance factor
	int bf;
	//left child and right child
	node* lchild;
	node* rchild;
} BSTNode;

/*
TODO:完成对以指针p所指结点为根的二叉树作左平衡旋转处理的功能.
功能描述:对以指针p所指结点为根的二叉树作左平衡旋转处理，通过判断结点的平衡因子的值，进行重新赋值等运算来作平衡处理.
  具体实现过程：
	定义两个BSTNode类型的指针p1、p2
	判断如果p的平衡因子等于0，将p的平衡因子置为1，入参taller置为1.
	判断如果p的平衡因子等于-1，将p的平衡因子置为0，入参taller置为0.
	如果p的平衡因子既不等于0，也不等于-1，
	  p1指向结点p的左子结点
	  判断如果p1的平衡因子等于1，结点p的成员lchild指向p1的右子结点，p1的成员rchild指向p结点，p和p1的平衡因子置为0，将p1赋给p.
	  判断如果p1的平衡因子等于-1，p2指向p1的右子结点，p1的右子结点指向p2的左子结点，p2的左子结点指向p1，
		p的左子结点指向p2的右子结点，p2的右子结点指向p，
		判断如果p2的平衡因子等于0，将p和p1的平衡因子置为0
		判断如果p2的平衡因子等于1，将p1的平衡因子置为0，将p的平衡因子置为-1
		如果p2的平衡因子既不等于0，也不等于1，将p1的平衡因子置为1，p的平衡因子置为0
		将p2赋给p，p的平衡因子置为0
	  入参taller置为0.
参数说明:p：目标二叉树的根指针引用
		taller：二叉树p是否长高的标记
返回值说明:无.
*/
void LeftProcess(BSTNode*& p, int& taller)
{
	BSTNode* p1;
	BSTNode* p2;
	if (p->bf == 0)
	{
		p->bf = 1;
		taller = 1;
	}
	else if (p->bf == -1)
	{
		p->bf = 0;
		taller = 0;
	}
	else
	{
		p1 = p->lchild;
		if (p1->bf == 1)
		{
			p->lchild = p1->rchild;
			p1->rchild = p;
			p->bf = 0;
			p1->bf = 0;
			p = p1;
		}
		else if (p1->bf == -1)
		{
			p2 = p1->rchild;
			p1->rchild = p2->lchild;
			p2->lchild = p1; 
			p->lchild = p2->rchild; 
			p2->rchild = p;

			if (p2->bf == 0)
			{
				p->bf = 0;
				p1->bf = 0;
			}
			else if (p2->bf == 1)
			{
				p1->bf = 0;
				p->bf = -1;
			}
			else
			{
				p1->bf = 1;
				p->bf = 0;
			}
			p = p2;
			p->bf = 0;
		}
		taller = 0;
	}
}

/*
TODO:完成对以指针p所指结点为根的二叉树作右平衡旋转处理的功能.
功能描述:对以指针p所指结点为根的二叉树作右平衡旋转处理，通过判断结点的平衡因子的值，进行重新赋值等运算来作平衡处理.
  具体实现过程：
	定义两个BSTNode类型的指针p1、p2
	判断如果p的平衡因子等于0，将p的平衡因子置为-1，入参taller置为1.
	判断如果p的平衡因子等于1，将p的平衡因子置为0，入参taller置为0.
	如果p的平衡因子既不等于0，也不等于1，
	  p1指向结点p的右子结点
	  判断如果p1的平衡因子等于-1，p的右子结点指向p1的左子结点，p1的左子结点指向p，p和p1的平衡因子置为0，将p1赋给p.
	  判断如果p1的平衡因子等于1，p2指向p1的左子结点，p1的左子结点指向p2的右子节点，p2的右子节点指向p1,
		p的右子结点指向p2的左子结点，p2的左子结点指向p，
		判断如果p2的平衡因子等于0，将p和p1的平衡因子置为0
		判断如果p2的平衡因子等于-1，将p1的平衡因子置为0，p的平衡因子置为1
		如果p2的平衡因子既不等于0，也不等于-1，将p1的平衡因子置为-1，p的平衡因子置为0
		将p2赋给p，p的平衡因子置为0
	入参taller置为0
参数说明:p：目标二叉树的根指针引用
		taller：二叉树p是否长高的标记
返回值说明:无.
*/
void RightProcess(BSTNode*& p, int& taller)
{
	BSTNode* p1;
	BSTNode* p2;
	if (p->bf == 0)
	{
		p->bf = -1;
		taller = 1;
	}
	else if (p->bf == 1)
	{
		p->bf = 0;
		taller = 0;
	}
	else
	{
		p1 = p->rchild;
		if (p1->bf == -1)
		{
			p->rchild = p1->lchild;
			p1->lchild = p;
			p->bf = 0;
			p1->bf = 0;
			p = p1;
		}
		else if (p1->bf == 1)
		{
			p2 = p1->lchild;
			p1->lchild = p2->rchild;
			p2->rchild = p1;
			p->rchild = p2->lchild;
			p2->lchild = p;
			if (p2->bf == 0)
			{
				p->bf = 0;
				p1->bf = 0;
			}
			else if (p2->bf == -1)
			{
				p1->bf = 0;
				p->bf = 1;
			}
			else
			{
				p1->bf = -1;
				p->bf = 0;
			}
			p = p2;
			p->bf = 0;
		}
		taller = 0;
	}
}

/*
TODO:完成插入结点的功能.
功能描述:在平衡二叉树b中插入一个关键字为e的结点，利用递归方式插入结点，插入成功返回1，否则返回0.
  具体实现过程：
	判断二叉树b是否为NULL，
	  如果二叉树b为NULL，创建新结点，给新结点分配存储空间，新结点的key置为e、左右孩子结点为NULL、bf置为0，入参taller置为1，返回1.
	  如果二叉树b不为NULL，判断结点b中的key是否等于e，
		如果结点b中的key等于e，将入参taller置为0，返回0.
		如果结点b中的key不等于e，判断e是否小于结点b中的key，
		  如果e小于结点b中的key，调用函数InsertAVL()，传入结点b的左侧子结点、入参e、入参taller，判断函数InsertAVL()返回值是否等于0，
			如果函数InsertAVL()返回值等于0，返回0.
			如果函数InsertAVL()返回值不等于0，判断入参taller是否等于1，如果入参taller等于1，则调用函数LeftProcess()，传入参数为入参b、入参taller.
		  如果e不小于结点b中的key，调用函数InsertAVL()，传入结点b的右侧子结点、入参e、入参taller，判断函数InsertAVL()返回值是否等于0，
			如果函数InsertAVL()返回值等于0，返回0.
			如果函数InsertAVL()返回值不等于0，判断入参taller是否等于1，如果入参taller等于1，则调用函数RightProcess()，传入参数为入参b、入参taller.
参数说明:b：目标二叉树指针引用
		e：关键字
		taller：二叉树b是否长高的标记.
返回值说明:结点插入成功返回1，否则返回0.
*/
int InsertAVL(BSTNode*& b, KeyType e, int& taller)
{
	if (b == NULL)
	{
		BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
		//check if null pointer
		if (newNode == NULL)
		{
			return 0;
		}
		newNode->key = e;
		newNode->lchild = NULL;
		newNode->rchild = NULL;
		newNode->bf = 0;
		taller = 1;
		b = newNode;
		return 1;
	}
	//b != NULL
	if (b->key == e)
	{
		taller = 0;
		return 0;
	}
	else
	{
		if (e < b->key)
		{
			if (InsertAVL(b->lchild, e, taller) == 0)
			{
				return 0;
			}
			else
			{
				if (taller == 1)
				{
					LeftProcess(b, taller);
				}
			}
		}
		else
		{
			if (InsertAVL(b->rchild, e, taller) == 0)
			{
				return 0;
			}
			else
			{
				if (taller == 1)
				{
					RightProcess(b, taller);
				}
			}
		}
	}

	return 1;
}

//以括号表示法输出AVL
void DispBSTree(BSTNode* b)
{
	if (b != NULL)
	{
		printf("%d", b->key);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBSTree(b->lchild);
			if (b->rchild != NULL) printf(",");
			DispBSTree(b->rchild);
			printf(")");
		}
	}
}

/*
TODO:完成销毁平衡二叉树的功能.
功能描述:利用递归方式释放平衡二叉树每一个结点所分配的空间.
  具体实现过程：
	判断b指针是否为NULL，如果不为NULL，则调用函数DestroyAVL()，分别销毁b的左右子结点；
	调用函数free()释放b
参数说明:b：目标平衡二叉树的指针引用.
返回值说明:无.
*/
void DestroyAVL(BSTNode*& b)
{
	if (b != NULL)
	{
		DestroyAVL(b->lchild);
		DestroyAVL(b->rchild);
		free(b);
	}
}

/*
TODO:完成在删除结点时进行左处理的功能.
功能描述:判断平衡因子的值来改变标记值，或改变左右孩子来作左处理.
  具体实现过程:
	定义两个BSTNode型的指针变量p1、p2
	判断如果p的平衡因子等于1，将p的平衡因子置为0，taller置为1
	判断如果p的平衡因子等于0，将p的平衡因子置为-1，taller置为0
	如果p的平衡因子既不等于1，也不等于0，
	  p1指向p的右子结点
	  判断如果p1的平衡因子等于0，将p的右子结点指向p1的左子结点，p1的左子结点指向p，p1的平衡因子置为1，
		p的平衡因子置为-1，p1赋给p，taller置为0
	  判断如果p1的平衡因子等于-1，将p的右子结点指向p1的左子结点，p1的左子结点指向p，p和p1的平衡因子置为0，
		p1赋给p，taller置为1
	  如果p1的平衡因子既不等于0，也不等于-1，
		将p2指向p1的左子结点，p1的左子结点指向p2的右子结点，p2的右子结点指向p1，
		p的右子结点指向p2的左子结点，p2的右子结点指向p,
		判断如果p2的平衡因子等于0，将p和p1的平衡因子置为0
		判断如果p2的平衡因子等于-1，将p的平衡因子置为1，p1的平衡因子置为0
		如果p2的平衡因子既不等于0，也不等于-1，将p的平衡因子置为0，p1的平衡因子置为-1
		p2的平衡因子置为0，p2赋给p，taller置为1
参数说明:p：目标二叉树的根指针引用
		taller：左右高度比较标记.
返回值说明:无.
*/
void LeftProcess1(BSTNode*& p, int& taller)
{
	BSTNode* p1;
	BSTNode* p2;
	if (p->bf == 1)
	{
		p->bf = 0;
		taller = 1;
	}
	else if (p->bf == 0)
	{
		p->bf = -1;
		taller = 0;
	}
	else
	{
		p1 = p->rchild;
		if (p1->bf == 0)
		{
			p->rchild = p1->lchild;
			p1->lchild = p;
			p1->bf = 1;
			p->bf = -1;
			p = p1;
			taller = 0;
		}
		else if (p1->bf == -1)
		{
			p->rchild = p1->lchild;
			p1->lchild = p;
			p->bf = 0;
			p1->bf = 0;
			p = p1;
			taller = 1;
		}
		else
		{
			p2 = p1->lchild;
			p1->lchild = p2->rchild;
			p2->rchild = p1;
			p->rchild = p2->lchild;
			p2->rchild = p;
			if (p2->bf == 0)
			{
				p->bf = 0;
				p1->bf = 0;
			}
			else if (p2->bf == -1)
			{
				p->bf = 1;
				p1->bf = 0;
			}
			else
			{
				p->bf = 0;
				p1->bf = -1;
			}
			p2->bf = 0;
			p = p2;
			taller = 1;
		}
	}
}

/*
TODO:完成在删除结点时进行右处理的功能.
功能描述:判断平衡因子的值来改变标记值，或改变左右孩子来作右处理.
  具体实现过程:
	定义两个BSTNode型的指针变量p1、p2
	判断如果p的平衡因子等于-1，将p的平衡因子置为0，taller置为-1
	判断如果p的平衡因子等于0，将p的平衡因子置为1，taller置为0
	如果p的平衡因子既不等于-1，也不等于0，
	  p1指向p的左子结点
	  判断如果p1的平衡因子等于0，将p的左子结点指向p1的右子结点，p1的右子结点指向p，p1的平衡因子置为-1，
		p的平衡因子置为1，p1赋给p，taller置为0
	  判断如果p1的平衡因子等于1，将p的左子结点指向p1的右子结点，p1的右子结点指向p，p和p1的平衡因子置为0，
		p1赋给p，taller置为1
	  如果p1的平衡因子既不等于0，也不等于1，
		将p2指向p1的右子结点，p1的右子结点指向p2的左子结点，p2的左子结点指向p1，
		p的左子结点指向p2的右子结点，p2的右子结点指向p,
		判断如果p2的平衡因子等于0，将p和p1的平衡因子置为0
		判断如果p2的平衡因子等于1，将p的平衡因子置为-1，p1的平衡因子置为0
		如果p2的平衡因子既不等于0，也不等于1，将p的平衡因子置为0，p1的平衡因子置为1
		p2的平衡因子置为0，p2赋给p，taller置为1
参数说明:p：目标二叉树的根指针引用
		taller：左右高度比较标记.
返回值说明:无.
*/
void RightProcess1(BSTNode*& p, int& taller)
{
	BSTNode* p1;
	BSTNode* p2;
	if (p->bf == -1)
	{
		p->bf = 0;
		taller = -1;
	}
	else if (p->bf == 0)
	{
		p->bf = 1;
		taller = 0;
	}
	else
	{
		p1 = p->lchild;
		if (p1->bf == 0)
		{
			p->lchild = p1->rchild;
			p1->rchild = p;
			p1->bf = -1;
			p->bf = 1;
			p = p1;
			taller = 0;
		}
		else if (p1->bf == 1)
		{
			p->lchild = p1->rchild;
			p1->rchild = p;
			p->bf = 0;
			p1->bf = 0;
			p = p1;
			taller = 1;
		}
		else
		{
			p2 = p1->rchild;
			p1->rchild = p2->lchild;
			p2->lchild = p1;
			p->lchild = p2->rchild;
			p2->rchild = p;
			if (p2->bf == 0)
			{
				p->bf = 0;
				p1->bf = 0;
			}
			else if (p2->bf == 1)
			{
				p->bf = -1;
				p1->bf = 0;
			}
			else
			{
				p->bf = 0;
				p1->bf = 1;
			}
			p2->bf = 0;
			p = p2;
			taller = 1;
		}
	}
}

/*
TODO:完成用于处理被删结点左右子树均不空的情况的功能.
功能描述:判断结点右孩子指针值来释放空间或者递归调用函数做右处理.
  具体实现过程：
	判断如果r的右子结点等于NULL，r的关键字赋给q的关键字，r赋给q，r指向r的左子结点，调用函数free()释放q，taller置为1
	如果r的右子结点不等于NULL，调用函数Delete2()，传入参数分别为q、r的右子结点、taller，
	  判断如果taller等于1，调用函数RightProcess1()，传入参数分别为r、taller
参数说明:q：结点指针
		r：根结点指针引用
		taller：左右高度比较标记.
返回值说明:无.
*/
void Delete2(BSTNode* q, BSTNode*& r, int& taller)
//由DeleteAVL()调用,用于处理被删结点左右子树均不空的情况
{
	if (r->rchild == NULL)
	{
		q->key = r->key;
		q = r;
		r = r->lchild;
		free(q);
		taller = 1;
	}
	else
	{
		Delete2(q, r->rchild, taller);
		if (taller == 1)
		{
			RightProcess1(r, taller);
		}
	}
}

/*
TODO:完成在AVL树p中删除关键字为x的结点的功能.
功能描述:判断结点的关键字的值来递归调用并进行左右处理或者调用函数释放空间.
  具体实现过程：
	定义int型变量k，BSTNode型指针q
	判断如果p等于NULL，返回0.
	判断如果x小于结点p的关键字，调用函数DeleteAVL()，传入的参数分别为p的左子结点指针变量、x、taller，将函数DeleteAVL()的返回值赋给变量k，
	  判断如果taller等于1，调用函数LeftProcess1()，传入的参数分别为p、taller
	  返回k的值.
	判断如果x大于结点P的关键字，调用函数DeleteAVL()，传入的参数分别为p的右子结点指针变量、x、taller，将函数DeleteAVL()的返回值赋给变量k，
	  判断如果taller等于1，调用函数RightProcess1()，传入的参数分别为p、taller
	  返回k的值.
	如果x等于p的关键字，p赋给q，
	  判断如果p的右子结点等于NULL，p指向p的左子结点，调用函数free()释放q，taller置为1
	  判断如果p的左子结点等于NULL，p指向p的右子结点，调用函数free()释放q，taller置为1
	  如果p的左右子结点均不空，调用函数Delete2()，传入参数分别为q、q的左子结点、taller，
		判断如果taller等于1，调用函数LeftProcess1()，传入参数分别为q、taller
		q赋给p
	  返回1.
参数说明:p：树结点指针引用
		x：目标关键字
		taller：左右高度比较标记.
返回值说明:删除失败返回0,删除成功返回1.
*/
int DeleteAVL(BSTNode*& p, KeyType x, int& taller)
{
	int k;
	BSTNode* q;
	if (p == NULL)
	{
		return 0;
	}
	if (x < p->key)
	{
		k = DeleteAVL(p->lchild, x, taller);
		if (taller == 1)
		{
			LeftProcess1(p, taller);
		}
		return k;
	}
	else if (x > p->key)
	{
		k = DeleteAVL(p->rchild, x, taller);
		if (taller == 1)
		{
			RightProcess1(p, taller);
		}
		return k;
	}
	else
	{
		q = p;
		if (p->rchild == NULL)
		{
			p = p->lchild;
			free(q);
			taller = 1;
		}
		else if (p->lchild == NULL)
		{
			p = p->rchild;
			free(q);
			taller = 1;
		}
		else if (p->rchild != NULL && p->lchild != NULL)
		{
			Delete2(q, q->lchild, taller);
			if (taller == 1)
			{
				LeftProcess1(q, taller);
			}
			p = q;
		}
		return 1;
	}
}

int main()
{
	BSTNode* b = NULL;
	int i, j, k;
	scanf_s("%d", &k);
	KeyType a[] = { 16,3,7,11,9,26,18,14,15 }, n = 9;
	for (i = 0; i < n; i++)
	{
		/*
		TODO:调用函数InsertAVL()，向平衡二叉树b中插入一个关键字为a[i]的结点，
		传入的参数分别为指向树的根结点b、数组元素a[i]和变量j
		*/
		InsertAVL(b, a[i], j);

	}
	printf("   AVL:");
	/*
	TODO:调用函数DispBSTree()，输出b指向的平衡二叉树
	*/
	DispBSTree(b);

	printf("   删除关键字%d:", k);
	/*
	TODO:调用函数DeleteAVL()，删除平衡树b中等于关键字k的一个结点，
	传入的参数分别为指向数的根结点b、变量k和变量j
	*/
	DeleteAVL(b, k, j);

	printf("   AVL:");
	/*
	TODO:调用函数DispBSTree()，输出b指向的平衡二叉树
		 调用函数DestroyAVL()，销毁b指向的平衡二叉树
	*/
	DispBSTree(b);
	DestroyAVL(b);

	return 0;
}
