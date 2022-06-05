#include <iostream>
using namespace std;
class node
{
public:
        int data;
         node *next;
};
void Insert(node** first,int pos,int x){
  node *t,*p;
    if(pos==0){
        t=new node();
        t->data=x;
        t->next=(*first);
        (*first)=t;
    }
    else if(pos>0){
        p=(*first);
        for(int i=0;i<pos-1&&p;i++)
            p=p->next;
        if(p){
            t=new node();
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
    }  
}
int Delete(node** first,int pos){
    node *q,*p;
    int x=-1,i;
    if(pos==1){
        x=(*first)->data;
        p=(*first);
        (*first)=(*first)->next;
        delete p;
    }
    else{
        p=(*first);
        q=NULL;
        for(i=0;i<pos-1&&p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
}
void Display(node* first){
     node *temp=first;
    while((temp)!=NULL){
        cout<<(temp)->data<<" ";
        (temp)=(temp)->next;
    }
}
int main()
{
    node* first=NULL;
    Insert(&first,0,20);
    Insert(&first,1,23);
    Insert(&first,2,22);
    Insert(&first,3,34);
    Display(first);
    cout<<endl;
    Delete(&first,3);
    cout<<"after delete"<<endl;
    Display(first);
    cout<<endl;
    Insert(&first,3,4);
    Insert(&first,4,354);
    Display(first);
    return 0;
}
