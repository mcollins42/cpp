#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Node
{
private:
    T value;
    Node<T> *next;

public:
    Node(const T &value, Node<T> *next = nullptr);

    void setNext(Node<T> *next) { this->next = next; };
    const Node<T> *getNext() const { return next; };
    const T &getValue() const;
};

template <class T>
Node<T>::Node(const T &value, Node<T> *next)
{
    this->value = value;
    this->next = next;
}
template <class T>
const T &Node<T>::getValue() const
{
    return value;
}

template <class T>
class List
{
    Node<T> *head = nullptr;

public:
    void addHead(T value);
    const Node<T> *getHead() const;
};

template <class T>
void List<T>::addHead(T value)
{
    Node<T> *newNode = new Node<T>(value, head);
    head = newNode;
}

template <class T>
const Node<T> *List<T>::getHead() const
{
    return head;
}

int main()
{
    List<int> list;
    list.addHead(3);
    list.addHead(2);
    list.addHead(14);

    const Node<int> *curr;
    for (curr = list.getHead(); curr != nullptr; curr = curr->getNext())
    {
        cout << "node: " << curr->getValue() << endl;
    }

    vector<string> msg{"Hello", "C++", "World", "from", "VS Code!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
