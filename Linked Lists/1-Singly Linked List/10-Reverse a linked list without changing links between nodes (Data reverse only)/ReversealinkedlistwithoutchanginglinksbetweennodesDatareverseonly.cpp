#include<bits/stdc++.h> // Include all standard libraries
using namespace std;

/* Definition of a linked list node */
struct Node
{
  int data;             // Data stored in the node
  struct Node *next;    // Pointer to the next node
  Node (int data)       // Constructor to initialize a node with data
  {
    this->data = data;
    next = NULL;        // Initialize the next pointer to NULL
  }
};

/* Definition of a linked list */
struct LinkedList
{
  Node *head;           // Pointer to the head of the linked list
  LinkedList ()         // Constructor to initialize the linked list
  {
    head = NULL;        // Initially, the linked list is empty
  }

  /* Function to reverse the linked list */
  void reverse ()
  {
    Node *current = head;              // Start from the head node
    std::vector < int >element;        // Vector to store linked list elements

    // Traverse the linked list and store its elements in the vector
    while (current != NULL)
      {
        element.push_back (current->data);
        current = current->next;
      }

    current = head;                   // Reset current to head
    int i = element.size () - 1;      // Index to iterate the vector in reverse

    // Update the linked list nodes with reversed data
    while (current != NULL)
      {
        current->data = element[i--];
        current = current->next;
      }
  }

  /* Function to print the linked list */
  void display ()
  {
    struct Node *temp = head;         // Start from the head node
    while (temp != NULL)              // Traverse the linked list
      {
        cout << temp->data << " ";    // Print the data of each node
        temp = temp->next;            // Move to the next node
      }
  }

  /* Function to insert a new node at the beginning of the list */
  void insert (int data)
  {
    Node *temp = new Node (data);     // Create a new node
    temp->next = head;                // Point the new node to the current head
    head = temp;                      // Update the head to the new node
  }
};

/* Driver code to demonstrate the functionality */
int main ()
{
  LinkedList ll;             // Create a linked list object

  // Insert elements into the linked list
  ll.insert (10);
  ll.insert (20);
  ll.insert (30);
  ll.insert (40);

  // Display the given linked list
  cout << "Given linked list\n";
  ll.display ();

  // Reverse the linked list
  ll.reverse ();

  // Display the reversed linked list
  cout << "\nReversed Linked list \n";
  ll.display ();
  
  return 0;
}
