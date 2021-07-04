// remove Nth Node
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head, *tail;
    int size;

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

    void deleteNth(int n)
    {
        Node *first = head, *second = head, *pre = NULL;
        for (int i = 0; i < n; i++)
            second = second->next;

        while (second)
        {
            pre = first;
            first = first->next;
            second = second->next;
        }
        if (pre == NULL) //first node
            head = head->next;
        else
            pre->next = first->next;
        cout << first->val;
    }
};

int main()
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    list.print();

    list.deleteNth(7);
    list.print();

    return 0;
}