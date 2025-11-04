#include <iostream>
using namespace std;

class ClsNode {
public:
    int data;
    ClsNode* Next;
    int orderInTheList;

    // Constructor
    ClsNode(int value) {
        data = value;
        Next = nullptr;
        orderInTheList = 0;
    }
};

//------------------------------------------
// Utility functions
//------------------------------------------

ClsNode* FindLastNode(ClsNode* head) {
    while (head != nullptr) {
        if (head->Next == nullptr)
            return head;
        head = head->Next;
    }
    return nullptr;
}

ClsNode* FindNode(ClsNode* head, int value) {
    while (head != nullptr) {
        if (head->data == value)
            return head;
        head = head->Next;
    }
    return nullptr;
}

//------------------------------------------
// Insertion functions
//------------------------------------------

void insertNode(ClsNode*& head, int value) {
    ClsNode* newNode = new ClsNode(value);
    newNode->Next = head;
    head = newNode;
}

void insertNodeAtTheEnd(ClsNode*& head, int value) {
    ClsNode* newNode = new ClsNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    ClsNode* last = FindLastNode(head);
    last->Next = newNode;
}

void insertNodeBetween(ClsNode*& head, int afterValue, int newValue) {
    ClsNode* position = FindNode(head, afterValue);
    if (position == nullptr) {
        cout << "Node with value " << afterValue << " not found.\n";
        return;
    }

    ClsNode* newNode = new ClsNode(newValue);
    newNode->Next = position->Next;
    position->Next = newNode;
}

//------------------------------------------
// Deletion functions
//------------------------------------------

void DeleteNode(ClsNode*& head, int value) {
    if (head == nullptr)
        return;

    ClsNode* current = head;
    ClsNode* prev = nullptr;

    // If the head is the node to delete
    if (current->data == value) {
        head = current->Next;
        delete current;
        return;
    }

    // Traverse to find node
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->Next;
    }

    if (current == nullptr)
        return; // Value not found

    prev->Next = current->Next;
    delete current;
}

void DeleteFirstNode(ClsNode*& head) {
    if (head == nullptr)
        return;

    ClsNode* temp = head;
    head = head->Next;
    delete temp;
}

void DeleteLastNode(ClsNode*& head) {
    if (head == nullptr)
        return;

    if (head->Next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    ClsNode* current = head;
    ClsNode* prev = nullptr;

    while (current->Next != nullptr) {
        prev = current;
        current = current->Next;
    }

    prev->Next = nullptr;
    delete current;
}

//------------------------------------------
// Display function
//------------------------------------------

void PrintList(ClsNode* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->Next;
    }
    cout << endl;
}

//------------------------------------------
// Main - Test all operations
//------------------------------------------

int main() {
    ClsNode* head = nullptr;

    cout << "=== Testing Linked List Operations ===\n\n";

    // 1. Insert at end
    insertNodeAtTheEnd(head, 10);
    insertNodeAtTheEnd(head, 20);
    insertNodeAtTheEnd(head, 30);
    insertNodeAtTheEnd(head, 40);
    cout << "After inserting nodes at the end:\n";
    PrintList(head);

    // 2. Insert at beginning
    insertNode(head, 5);
    cout << "\nAfter inserting node at the beginning (5):\n";
    PrintList(head);

    // 3. Insert between nodes (after 20)
    insertNodeBetween(head, 20, 25);
    cout << "\nAfter inserting 25 after 20:\n";
    PrintList(head);

    // 4. Find a node
    int valueToFind = 30;
    ClsNode* found = FindNode(head, valueToFind);
    if (found)
        cout << "\nNode with value " << valueToFind << " found.\n";
    else
        cout << "\nNode with value " << valueToFind << " not found.\n";

    // 5. Delete first node
    DeleteFirstNode(head);
    cout << "\nAfter deleting the first node:\n";
    PrintList(head);

    // 6. Delete a specific node
    DeleteNode(head, 25);
    cout << "\nAfter deleting node with value 25:\n";
    PrintList(head);

    // 7. Delete last node
    DeleteLastNode(head);
    cout << "\nAfter deleting the last node:\n";
    PrintList(head);

    // 8. Try to delete a non-existing node
    DeleteNode(head, 999);
    cout << "\nAfter trying to delete non-existing node 999:\n";
    PrintList(head);

    // 9. Delete all remaining nodes
    cout << "\nDeleting all remaining nodes...\n";
    while (head != nullptr)
        DeleteFirstNode(head);
    PrintList(head);

    cout << "\n=== End of Test ===\n";
    return 0;
}
