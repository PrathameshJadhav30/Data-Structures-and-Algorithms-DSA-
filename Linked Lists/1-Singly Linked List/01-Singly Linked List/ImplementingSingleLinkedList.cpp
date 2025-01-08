// Using Class
#include <iostream> // Include input/output stream library

using namespace std;

// Node class represents an individual element in the linked list
class Node
{
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the linked list

    // Constructor to initialize the node with a value and set the next pointer to nullptr
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class represents a singly linked list
class LinkedList
{
private:
    Node* head; // Pointer to the head (start) of the linked list

public:
    // Constructor to initialize the linked list with no elements
    LinkedList() : head(nullptr) {}

    // Method to insert a new node at the beginning of the linked list
    void insertStart(int data)
    {
        Node* newNode = new Node(data); // Create a new node
        newNode->next = head;           // Point the new node to the current head
        head = newNode;                 // Update the head to the new node
        cout << data << " inserted at the start" << endl;
    }

    // Method to delete the first node in the linked list
    void deleteStart()
    {
        if (head == nullptr) // Check if the list is empty
        {
            cout << "Linked List is empty, nothing to delete" << endl;
            return;
        }

        Node* temp = head;   // Temporarily store the current head
        head = head->next;   // Move the head to the next node
        cout << temp->data << " deleted from the start" << endl;
        delete temp;         // Delete the old head node to free memory
    }

    // Method to display the elements of the linked list
    void display()
    {
        cout << "Linked List: ";
        Node* current = head; // Start from the head of the list
        while (current != nullptr) // Traverse until the end of the list
        {
            cout << current->data << " "; // Print the data of the current node
            current = current->next;     // Move to the next node
        }
        cout << endl; // Print a newline at the end
    }
};

// Main function to demonstrate the functionality of the linked list
int main()
{
    LinkedList list; // Create an instance of LinkedList

    // Insert elements into the linked list
    list.insertStart(100);
    list.insertStart(80);
    list.insertStart(60);
    list.insertStart(40);
    list.insertStart(20);

    // Display the linked list
    list.display();

    // Delete elements from the linked list
    list.deleteStart();
    list.deleteStart();

    // Display the linked list again
    list.display();

    return 0;
}
