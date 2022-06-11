#include <iostream>
using namespace std;
class stack
{
public:
    struct st
    {
        int size, top;
        int *s;
    };
    void push(st *st, int x);
    int pop(st *st);
    int peep(st st, int pos);
    int stacktop(st st);
    int IsEmpty(st st);
    int IsFull(st st);
    void display(st *st);
    
};
int main()
{
    stack k;
    stack::st s;
    cout << "enter size of stack" << endl;
    cin >> s.size;
    s.s = new int[s.size];
    s.top = -1;
    k.IsEmpty(s);
    k.push(&s, 20);
    k.pop(&s);
    k.push(&s,25);
    k.push(&s,35);
    k.display(&s);
    return 0;
}
void stack::display(st *st)
{
    cout << "running display...." << endl;
    if (st->top == -1)
        cout << "stack is empty" << endl;
    else
    {
        for(int i=st->top;i>=0;i--)
        cout<<st->s[i]<<endl;
        
    }
}
void stack::push(st *st, int x)
{
    cout << "running push...." << endl;
    if (st->top == st->size - 1)
        cout << "stack overflow" << endl;
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
int stack::pop(st *st)
{
    cout << "running pop...." << endl;
    int x = -1;
    if (st->top == -1)
        cout << "stack underflow" << endl;
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
};
int stack::peep(st st, int pos)
{
    cout << "running peep...." << endl;
    int x = -1;
    if ((st.top - pos + 1) < 0)
        cout << "invalid position" << endl;
    else
        x = st.s[st.top - pos + 1];
    return x;
};
int stack::stacktop(st st)
{
    cout << "running stacktop...." << endl;
    if (st.top == -1)
        return -1;
    else
        return st.s[st.top];
};
int stack::IsEmpty(st st)
{
    cout << "running IsEmpty...." << endl;
    if (st.top == -1)
        return 1;
    else
        return 0;
};
int stack::IsFull(st st)
{
    cout << "running IsFull...." << endl;
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
};
