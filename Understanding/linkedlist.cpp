#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *createNode(int data)
{
    Node *node;
    node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}
void insertNode(int data, Node *node)
{
    Node *newNode;
    newNode = createNode(data);
    if (newNode->next)
        node->next = newNode;
    else
    {
        Node *temp = node;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
void deleteNode(int data, Node *node)
{
    Node *temp = node;
    Node *temp2 = node->next;
    while (temp)
    {
        if (temp2->data == data)
            temp->next = temp2->next;

        temp = temp->next;
        temp2 = temp2->next;
    }
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head;
    head = createNode(5);

    insertNode(4, head);
    insertNode(3, head);
    insertNode(2, head);
    insertNode(7, head);
    insertNode(1, head);

    printList(head);

    deleteNode(7, head);
    deleteNode(1, head);

    printList(head);

    return 0;
}