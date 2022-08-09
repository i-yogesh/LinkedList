#include <bits/stdc++.h>
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
// main code
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool checkPalindrome(Node* head)
{
    if (head->next == NULL)
        return true;

    // Step1 : Finding The Middle
    Node *middle = findMiddle(head);

    // STEP2: Reverse after Middle Node
    Node *temp = middle->next;
    middle->next = reverseLL(temp);
    // Step3: Compare data below and after middle
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    // setting the LL back to its original order
    temp = middle->next;
    middle->next = reverseLL(temp);

    return true;
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    print(head);
    int ans = checkPalindrome(head);
    if (ans == 1)
        cout << "\nPalindrome\n";
    else
        cout << "\nNot Palindrome\n";
    return 0;
}