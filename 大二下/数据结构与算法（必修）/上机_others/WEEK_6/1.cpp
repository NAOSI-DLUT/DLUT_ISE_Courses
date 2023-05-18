/*2.5 课后习题

a.    设一棵二叉搜索树以二叉链表表示，试编写有关二叉树的递归算法
    int degree1(binarytreenode* p)                            //2.5-a-i 统计度为1的结点
    int degree2(binarytreenode* p)                            //2.5-a-ii 统计二叉树中度为2的结点个数
    int degree3(binarytreenode* p)                            //2.5-a-iii 统计二叉树中度为0的结点个数
    int get_height(binarytreenode* p)                        //2.5-a-iv 统计二叉树的高度
    void get_width(binarytreenode* p, int i, int wide[])    //2.5-a-v 统计各层结点数
    int get_max(binarytreenode* p)                            //2.5-a-vi 计算二叉树中各结点中的最大元素的值
    void change_children(binarytreenode* p)                    //2.5-a-vii 交换每个结点的左子树和右子树？
    void del_leaf(binarytreenode* p)                        //2.5-a-viii 从二叉树中删去所有叶结点
    bool wanquan(binarytreenode* pRoot)                        //2.5-b 编写算法判定给定二叉树是否为完全二叉树
*/
#include <iostream>
#include <queue>
using namespace std;
class binarytreenode //二叉树结点
{
    int data;

public:
    binarytreenode* leftchild;
    binarytreenode* rightchild;
    binarytreenode(int& d)
    {
        data = d;
        leftchild = NULL;
        rightchild = NULL;
    }
    int& get_data() { return data; }
    void change_data(int& n) { data = n; }
    ~binarytreenode(){};
};

//二叉树
class binarytree {
    binarytreenode* root;
    static int times;
    int size;

public:
    binarytree()
    {
        size = 0;
        root = NULL;
    }
    int get_size() { return size; }
    binarytreenode* get_root() { return root; }
    void creat() //创建二叉树
    {
        binarytreenode* prev;
        cout << "输入int型数据:(以0结束)";
        int temp;
        cin >> temp;
        while (temp != 0) {
            if (root == NULL) {
                root = new binarytreenode(temp);
                size++;
                prev = root;
            } else {
                prev = root;
                size++;
                for (;;) {
                    if (temp < prev->get_data()) {
                        if (prev->leftchild == NULL) {
                            prev->leftchild = new binarytreenode(temp);
                            break;
                        }
                        prev = prev->leftchild;
                    } else {
                        if (prev->rightchild == NULL) {
                            prev->rightchild = new binarytreenode(temp);
                            break;
                        }
                        prev = prev->rightchild;
                    }
                }
            }
            cin >> temp;
        }
    }

    void levelorder() //广度优先遍历
    {
        binarytreenode* p = get_root();
        queue<binarytreenode*> que;
        cout << "广度遍历结果: ";
        if (p != NULL)
            que.push(p);
        else
            cout << "二叉树为空!";
        while (!que.empty()) {
            if (p != NULL) {
                cout << p->get_data() << " ";
                if (p->leftchild != NULL)
                    que.push(p->leftchild);
                if (p->rightchild != NULL)
                    que.push(p->rightchild);
                que.pop();
                if (!que.empty())
                    p = que.front();
            }
        }
        cout << endl;
    }
    /*
    TODO:统计并返回度为1的结点个数
     */
    int degree1(binarytreenode* p)
    {
        int i=0;
        if(p==NULL) return 0;
        if((p->leftchild == NULL && p->rightchild != NULL) || (p->rightchild == NULL && p->leftchild != NULL)) i=1;
        return (i+degree1(p->leftchild)+degree1(p->rightchild));
    }
    /*
    TODO:统计并返回度为2的结点个数
     */
    int degree2(binarytreenode* p)
    {
        int i=0;
        if(p==NULL) return 0;
        if(p->leftchild != NULL && p->rightchild != NULL) i=1;
        return (i+degree2(p->leftchild)+degree2(p->rightchild));
    }
    /*
    TODO:统计并返回度为0的结点个数
     */
    int degree0(binarytreenode* p)
    {
        if(p==NULL) return 0;
        if(leaf(p)) return 1;
        return (degree0(p->leftchild)+degree0(p->rightchild));
    }
    /*
    TODO:统计并返回高度
     */
    int get_height(binarytreenode* p)
    {
        if(p==NULL) return 0;
        if(leaf(p)) return 1;
        int h1=1+get_height(p->leftchild);
        int h2=1+get_height(p->rightchild);
        if(h1>h2) return h1;
        else return h2;
    }
    void get_width(binarytreenode* p, int i, int wide[]) //统计各层结点数
    {
        wide[i++]++;
        if (p->leftchild != NULL)
            get_width(p->leftchild, i, wide);
        if (p->rightchild != NULL)
            get_width(p->rightchild, i, wide);
    }
    /*
    TODO:统计并返回二叉树的宽度
     */
    int get_max_width()
    {
        if(root==NULL) return 0;
        int wide[100];
        int i;
        for(i=0;i<size;i++) wide[i]=0;
        int max=0;
        get_width(root, 0, wide);
        for(i=0;wide[i]!=0;i++)
        {
            if(wide[i] >max) max=wide[i];
        }
        return max;
    }

    /*
    TODO: 计算并返回二叉树的最大值
     */
    int get_max(binarytreenode* p)
    {
        int d0,d1,d2;
        d0=p->get_data();
        if(leaf(p)) return d0;
        if(p->leftchild != NULL )d1=get_max(p->leftchild); else d1=d0;
        if(p->rightchild != NULL )d2=get_max(p->rightchild); else d2=d0;
        return max(d0,max(d1, d2));
    }
    /*
    TODO:交换二叉树的左右孩子
     */
    void change_children(binarytreenode* p)
    {
        if(p==NULL) return;
        change_children(p->leftchild);
        change_children(p->rightchild);
        binarytreenode *tmp;
        tmp=p->leftchild;
        p->leftchild=p->rightchild;
        p->rightchild=tmp;
        
    }
    int find_father(binarytreenode* num, binarytreenode*& fa) //寻找父节点
    {
        binarytreenode* p = root;
        int flag = 0;
        while (p != NULL) {
            if (p->get_data() > num->get_data()) {
                fa = p;
                flag = 1;
                p = p->leftchild;
            } else if (p->get_data() <= num->get_data() && p != num) {
                fa = p;
                flag = 2;
                p = p->rightchild;
            } else {
                break;
            }
        }
        return flag;
    }
    /*
    TODO:删除叶节点，删除成功的时候输出打印cout << xxx << "删除成功!" << endl;其中xxx为叶子节点的值
     */
    void del_leaf(binarytreenode* p)
    {
        if(!leaf(p))
        {
            del_leaf(p->leftchild);
            del_leaf(p->rightchild);
        }
        delete p;
    }

    bool leaf(binarytreenode* pCur)
    {
        if (pCur->leftchild == NULL && pCur->rightchild == NULL)
            return true;
        return false;
    }

    /*
TODO:判断是否是完全二叉树，是则返回true，否则返回false。
 */
    bool wanquan(binarytreenode* pRoot) //是否完全二叉树
    {
        binarytreenode *parent;
        if(leaf(pRoot))
        {
            find_father(pRoot, parent);
            if(parent->leftchild !=NULL && parent->rightchild !=NULL) return true;
            else return false;
        }
        return (wanquan(pRoot->leftchild) && wanquan(pRoot->rightchild));
    }
};
int binarytree::times = 0;
int main()
{
    binarytree tree;
    tree.creat();
    tree.levelorder();
    cout << "度为1的结点个数: " << tree.degree1(tree.get_root()) << endl;
    cout << "度为2的结点个数: " << tree.degree2(tree.get_root()) << endl;
    cout << "度为0的结点个数: " << tree.degree0(tree.get_root()) << endl;
    cout << "二叉树高度: " << tree.get_height(tree.get_root()) << endl;
    cout << "二叉树宽度: " << tree.get_max_width() << endl;
    cout << "最大值:" << tree.get_max(tree.get_root()) << endl;
    cout << "删除叶节点:" << endl;
    tree.del_leaf(tree.get_root());
    tree.levelorder();
    cout << "交换左右孩子. . ." << endl;
    tree.change_children(tree.get_root());
    tree.levelorder();
    if (tree.wanquan(tree.get_root()))
        cout << "该二叉树是完全二叉树" << endl;
    else
        cout << "该二叉树不是完全二叉树" << endl;
    return 0;
}

