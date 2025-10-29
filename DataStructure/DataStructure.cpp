#include <iostream>
using namespace std;

class ClsNode {
public:
    int data;
    ClsNode* Next;
};

void insertNode(ClsNode*& head, int Value)
{
    ClsNode* NewNode = new ClsNode();
    NewNode->data = Value;
    NewNode->Next = head;
    head = NewNode;
}

int main()
{
    // Initialize head to NULL (empty list)
    ClsNode* head = NULL;

    // Insert nodes
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);

    // Print all nodes
    ClsNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->Next;
    }

    // Free memory
    while (head != NULL) {
        ClsNode* toDelete = head;
        head = head->Next;
        delete toDelete;
    }

    return 0;
}
