//
//  main.cpp
//  333
//
//  Created by MEGABOY on 2021-04-20.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct hospital
{
    string name;
    int number;
    hospital()
    {
        name="";
        number=0;
    }
    hospital(string name)
    {
        this->name=name;
        number=0;
    }
    hospital(string name, int number)
    {
        this->name=name;
        this->number=number;
    }
    friend ostream& operator<<(ostream &output, hospital &node)
    {
        output << node.name << " | ";
        output << node.number;
        return output;
    }
};

string upper(string str)
{
    int i;
    string tmp="";
    for(i=0;i<str.length();i++)
    {
        if(str[i]>='a' && str[i]<='z') tmp+=(str[i]-'a'+'A');
        else tmp+=str[i];
    }
    return  tmp;
}

class treeNode
{
public:
    hospital data;
    treeNode *child;
    treeNode *sib; //RIGHT BROTHERS
    treeNode()
    {
        child=NULL;
        sib=NULL;
    }
    treeNode(treeNode *p)
    {
        this->data=p->data;
        this->child=p->child;
        this->sib=p->sib;
    }
    treeNode(hospital &h)
    {
        this->data=h;
        this->child=NULL;
        this->sib=NULL;
    }
    treeNode(string n,int c)
    {
        this->data.name=n;
        this->data.number=c;
        this->child=NULL;
        this->sib=NULL;
    }
};

class tree
{
public:
    treeNode *root;
    treeNode *getParent(treeNode *root,treeNode *node)
    {
        if(node == root) return NULL;
        treeNode *index=root;
        queue<treeNode*> que;
        if(index != NULL) que.push(index);
        while(!que.empty())
        {
            index=que.front();
            que.pop();
            if(index->child != NULL)
            {
                treeNode *chi=index->child;
                if(chi==node) return index;
                while(chi->sib != NULL)
                {
                    if(chi->sib != NULL)
                    {
                        if(chi->sib == node) return index;
                        chi=chi->sib;
                    }
                }
            }
            if(index->child!=NULL) que.push(index->child);
            if(index->sib != NULL) que.push(index->sib);
        }
        return NULL;
    }
    void show(treeNode *rt)
    {
        queue<treeNode*> que;
        treeNode *top;
        treeNode *index;
        que.push(rt);
        while(!que.empty())
        {
            top=que.front();
            treeNode *ups=getParent(root,top);
            if(ups != NULL) cout << top->data << " | Upstream is " << ups->data.name <<endl;
            else cout << top->data << endl;
            que.pop();
            
            index=top->child;//push all child into the queue
            while(index!=NULL)
            {
                que.push(index);
                index=index->sib;
            }
        }
    }
    
    treeNode *search(string name)
    {
        queue<treeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            treeNode *top=que.front();
            
            treeNode *index=top->child;//push all child into the queue
            while(index!=NULL)
            {
                que.push(index);
                index=index->sib;
            }
            
            if(upper(top->data.name) == upper(name)) return top;
            que.pop();
        }
        return NULL;
    }
    void insert(string parent_name, hospital &value)
    {
        if(root==NULL)
        {
            root=new treeNode;
            root->data=value;
        }
        treeNode *parent=search(parent_name);
        treeNode *index=parent->child;
        while(index->sib!= NULL) index=index->sib; //Find the empty space
        index->sib=new treeNode;
        index->sib->data=value;
    }
    void insert(string parent_name, string name, int count)
    {
        if(root==NULL)
        {
            root=new treeNode;
            root->data.name=name;
            root->data.number=count;
        }
        treeNode *parent=search(parent_name);
        treeNode *index=parent;
        if(index->child == NULL)
        {
            index->child=new treeNode;
            index->child->data.name=name;
            index->child->data.number=count;
        }
        else {index=index->child; while(index->sib!= NULL) index=index->sib; //Find the empty space
        index->sib=new treeNode;
        index->sib->data.name=name;
            index->sib->data.number=count;}
    }
    
    int count(string gparent, string child)
    {
        treeNode *parent=search(gparent);
        treeNode *t=search(child);
        if(t==NULL) return 0;
        int sum=1;
        if(parent == NULL) return -2;
        while(upper(parent->data.name) != upper(t->data.name))
        {
            sum=sum* t->data.number;
            t=getParent(root,t);
            if(t==NULL) return -1;
        }
        return sum;
    }
};
int main()
{
    tree tr;
    tr.root= new treeNode;
    tr.root->data.name="Hospital";
    tr.root->data.number=1;
    tr.insert("Hospital", "Floors", 10);
    tr.insert("Floors", "Central Hall", 1);
    tr.insert("Floors", "Side buildings", 4);
    tr.insert("Central Hall", "TV", 1);
    tr.insert("Central Hall", "Sofa", 2);
    tr.insert("Side buildings", "Hallways", 2);
    tr.insert("Side buildings", "Joints", 1);
    tr.insert("Hallways", "Rooms", 21);
    tr.insert("Joints", "Warehouses", 5);
    tr.insert("Rooms", "Lavatory", 1);
    tr.insert("Rooms", "Sockets", 4);
    tr.insert("Rooms", "Beds", 2);
    tr.insert("Lavatory", "Washbasin", 1);
    tr.insert("Lavatory", "Toilet", 1);
    tr.insert("Sockets", "Plugs", 2);
    tr.insert("Sockets", "Panel", 1);
    cout << "ITEM | COUNT | UPSTREAM" <<endl <<endl;
    tr.show(tr.root);
    cout<<endl;
    cout<<"COUNT ___ IN ___ (Case Insensitive)" <<endl;
    cout << "COUNT: ";
    string cnt;
    cin >> cnt;
    cout << "IN: ";
    string frm;
    cin >> frm;
    int cc=tr.count(frm,cnt);
    if(cc==-1)cout << "Error in Hierarchy" <<endl;
    else if(cc==-2) cout << "Parent item Not Exist" << endl;
    else if(cc>0)cout << "There are(is) " << cc << " " << tr.search(cnt)->data.name << " in " << tr.search(frm)->data.name << endl;
    else if(cc==0) cout <<"Child Item Not Found" <<endl;
}
