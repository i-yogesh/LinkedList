#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseList(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    int sum = 0;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        sum = carry + val1 + val2;

        int digit = sum%10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

Node* addTwoNumbers(Node* first, Node* second)
{
    // step1
    first = reverseList(first);
    second = reverseList(second);

    // step2
    Node* ans = add(first, second);

    // step3
    ans = reverseList(ans);
    return ans;
}

int main()
{
    Node *node1 = new Node(4);
    Node *node2 = new Node(2);
    Node *head1 = node1;
    Node *tail1 = node1;

    Node *head2 = node2;
    Node *tail2 = node2;

    // print(head1);

    insertAtTail(head1, tail1, 9);
    insertAtTail(head1, tail1, 9);
    print(head1);

    insertAtTail(head2, tail2, 4);
    print(head2);
    Node* ans = addTwoNumbers(head1, head2);
    print(ans);
}