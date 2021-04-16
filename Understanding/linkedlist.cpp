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
int main()
{
    Node *head;
    int x = 0, c = 0;
    cin >> x;
    head = createNode(x);
    while (c != -1)
    {
        cout << "1 for insert, 2 for delete, 3 for print, -1 for exit";
        cin >> c;
        if (c == 1)
        {
            cin >> x;
            insertNode(x, head);
        }
        else if (c == 2)
        {
            cin >> x;
            head = deleteNode(x, head);
        }
        else if (c == 3)
            printList(head);
    }
    return 0;
}