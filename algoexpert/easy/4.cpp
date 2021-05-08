// doubly linked list
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next, *prev;

    Node(int v)
    {
        val = v;
        next = prev = NULL;
    }
};

class LinkedList
{
private:
    Node *head, *tail;
    int size;

    void removeThisNode(Node *node)
    {
        if (size < 1)
            return;
        size--;

        if (node == head)
        {
            head = head->next;
            head->prev = NULL;
        }

        if (node == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        if (node->prev && node->next)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = NULL;
        node->next = NULL;
    }

public:
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void print()
    {
        cout << "printing" << endl;
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "printing pver" << endl;
    }

    void insert(int x)
    {
        size++;
        Node *newNode;
        newNode = new Node(x);

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void removeAll(int x)
    {
        Node *temp = head, *nodeToRemove;
        while (temp)
        {
            nodeToRemove = temp;
            temp = temp->next;
            if (temp->val == x)
                removeThisNode(nodeToRemove);
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(3);
    list.insert(1);
    list.insert(3);
    list.insert(1);
    list.insert(3);
    list.insert(1);
    list.insert(1);
    list.insert(3);

    list.print();
    list.removeAll(3);
    list.print();

    return 0;
}