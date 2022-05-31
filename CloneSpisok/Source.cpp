#include <iostream>
using namespace std;

struct Listitem
{
    int value;
    Listitem* next;
    Listitem();
};

class Stack
{
private:
    Listitem* head;
    Listitem* tail;
public:
    Stack();
    Stack(Stack const&) = delete;
    Stack& operator=(Stack const&) = delete;
    void push(int value);
    void pop();
    int top();
    void show();
    void clone(Stack const&);
    ~Stack();
};

Listitem::Listitem()
{
    next = NULL;
    this->value = 0;
}
Stack::Stack()
{
    head = tail = NULL;
}
void Stack::push(int value)
{
    Listitem* temp = new Listitem;
    temp->value = value;
    if (tail == NULL)
        tail = temp;
    else {
        temp->next = tail;
        tail = temp;
    }
}
void Stack::pop()
{
    if (tail == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    Listitem* temp = tail;
    tail = tail->next;
    delete temp;
}
int Stack::top()
{
    if (tail == NULL) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return tail->value;
}
void Stack::show()
{
    if (tail == NULL) {
        cout << "Stack is empty";
        return;
    }
    Listitem* temp = tail;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
void Stack::clone(Stack const& rhs)
{
    // удаление текущего списка
    Listitem* del = tail;
    while (del) {
        tail = del->next;
        std::cout << "del: " << del->value << ", ";
        delete del;
        del = tail;
    }
    std::cout << std::endl;

    // вставка в текущий список
    Listitem* tmp = rhs.tail;
    while (tmp)
    {
        push(tmp->value);
        tmp = tmp->next;
    }

    // реверс текущего списка
    Listitem* first = tail, * second = nullptr, * third = nullptr;
    if (tail)
    {
        second = tail->next;
        if (tail->next)
        {
            third = tail->next->next;
        }
    }

    if (first)
    {
        first->next = nullptr;
        if (second)
        {
            second->next = first;
            while (third)
            {
                first = second;
                second = third;
                third = third->next;
                second->next = first;
            }
            tail = second;
        }
    }
}
Stack::~Stack()
{
    Listitem* del = tail;
    while (del) {
        tail = del->next;
        //std::cout << del->value << "  ";
        delete del;
        del = tail;
    }

    delete head;
    head = nullptr;
}


int main()
{
    Stack s, s1;

    s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.push(400);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s1.clone(s);
    s1.show();
}