#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insert(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* reverseKGroup(Node *&head, int k)
{
    int count = 0;
    if (head == NULL)
        return NULL;

    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
        head->next = reverseKGroup(forward, k);

    return prev;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);
    print(head);
    head  = reverseKGroup(head, 3);
    print(head);
    return 0;
}