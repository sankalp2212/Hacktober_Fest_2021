#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} * top;

void push(int data)
{

    struct Node *temp;
    temp = new Node();

    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

// deletion pop
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        cout << "\n Underflow" << endl;
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }
}

void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        cout << "\n Underflow";
        return;
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            cout << temp->data << "-> ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    int choice;
    cout << " press 1 - for push operation ";
    cout << "\n press 2 - for pop operation ";
    cout << "\n press 3 - for display operation ";
    cout << "\n press 4 - for push exit ";
    cout << "\n enter your choice: ";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            int data;
            cout << "enter data:";
            cin >> data;
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            cout << "no valid choice entered ";
        }
        cout << "enter your choice : ";
        cin >> choice;
    }

    return 0;
}