//Remove Dups - Removing duplicates from unsorted list without temporary buffer
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
Node *deleteNode(int data, Node *node)
{
    cout << "deleting   " << data << endl;

    Node *temp = node;
    Node *temp2 = node->next;
    if (node->data == data)
    {
        return node->next;
    }
    else
        while (temp)
        {
            if (temp2->data == data)
            {
                temp->next = temp2->next;
                break;
            }

            temp = temp->next;
            if (temp2->next)
                temp2 = temp2->next;
            else
            {
                cout << "not found";
                break;
            }
        }
    return node;
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
void removeDups(Node *head)
{
    Node *temp = head;
    Node *temp2 = head->next;

    while (temp->next)
    {
        while (temp2)
        {
            cout << "comparing   " << temp->data << "=" << temp2->data << endl;
            if (temp->data == temp2->data && temp != temp2)
            {
                head = deleteNode(temp->data, head);
                printList(head);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        temp2 = temp->next;
    }
}
int main()
{
    Node *head;
    int x = 0, c = 0;
    cin >> x;
    head = createNode(x);
    while (x != -1)
    {
        cin >> x;
        if (x != -1)
            insertNode(x, head);
    }
    printList(head);
    removeDups(head);
    printList(head);

    return 0;
}