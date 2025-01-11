#include<iostream>
using namespace std;

// Node structure representing each node in the linked list
class Node
{
    public:
    int data;    // Data part of the node
    Node *next;  // Pointer to the next node in the linked list
};

// Function to insert a new node at the start of the linked list
void insertStart(Node** head, int data){
    // Create a new node
    Node* newNode = new Node();

    // Assign the data value to the new node
    newNode->data = data;

    // Set the next pointer of the new node to the current head of the list
    newNode->next = *head;

    // Change the head pointer to the new node
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertLast(Node** head, int data){
    // Create a new node
    Node* newNode = new Node();

    // Assign the data value to the new node
    newNode->data = data;

    // Since this will be the last node, set its next to NULL
    newNode->next = NULL;

    // If the linked list is empty, set the new node as the head
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // If the list is not empty, traverse to the last node
    struct Node* temp = *head;
    
    // Traverse to the last node of the linked list
    while(temp->next != NULL)
        temp = temp->next;

    // Set the next of the last node to the new node
    temp->next = newNode;
}

// Function to calculate the size of the linked list
int calcSize(Node* node){
    int size = 0;

    // Traverse the linked list to calculate the number of nodes
    while(node != NULL){
        node = node->next;
        size++;
    }
    return size; // Return the size of the linked list
}

// Function to insert a new node at a specific position in the linked list
void insertPosition(int n, int data, Node** head)
{
    // Get the current size of the linked list
    int size = calcSize(*head);

    // Check if the position is valid (should be between 1 and size)
    if(n < 1 || size < n)
    {
        cout << "Not Valid position to insert" << endl; 
    } 
    else { 
        // Create a new node to insert
        Node* temp = *head; 
        Node* newNode = new Node(); 
        
        newNode->data = data;
        newNode->next = NULL;

        // Traverse to the node before the nth position
        while(--n)
            temp = temp->next;
        
        // Set the next of the new node to the current nth node's next
        newNode->next = temp->next;

        // Set the nth node's next to the new node
        temp->next = newNode;
        // Now the new node is inserted at the nth position
    }
}

// Function to display the elements of the linked list
void display(Node* node){
    // Traverse and print the data of each node in the linked list
    while(node != NULL){
        cout << node->data << " "; 
        node = node->next;
    }
    cout << endl; // End the display output
}

int main(){

    // Initialize the linked list with head as NULL
    Node* head = NULL;

    // Insert elements at the start of the linked list
    insertStart(&head, 5);
    insertStart(&head, 10);
    insertStart(&head, 15);

    // Insert elements at the end of the linked list
    insertLast(&head, 20);
    insertLast(&head, 25);
    insertLast(&head, 30);
    insertLast(&head, 35);

    // Insert a new node after the 3rd position
    insertPosition(3, 100, &head);

    // Display the entire linked list
    display(head); 

    return 0;  
}
