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

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* &left, Node* &right)
{
    if(left == NULL)
    return right;

    if(right == NULL)
    return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left!=NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right!=NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    //Removing the dummy node
    ans = ans->next;
    return ans;
}

Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    //Step1: Breaking the LL into two parts
    Node *middle = getMid(head);

    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;

    //Sorting both the left and the right part
    left = mergeSort(left);
    right = mergeSort(right);

    //Merging the sorted lists
    Node* result = merge(left,right);

    //Returning the sorted List
    return result;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 6);
    // print(head);
    head = mergeSort(head);
    print(head);
    return 0;
}