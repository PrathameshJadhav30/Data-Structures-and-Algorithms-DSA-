#include<iostream>
using namespace std;

// Definition of the node structure
struct node
{
    int num;             // Data part of the node
    node* nextptr;       // Pointer to the next node in the list
} * stnode;             // Pointer to the first node of the linked list

// Function declarations
void createList(int n);
void reverse(node** stnode);
void displayList();

int main()
{
    int n;

    // Prompt the user to input the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    // Create the linked list
    createList(n);

    // Display the linked list
    cout << "\nLinked list data: \n";
    displayList();

    // Reverse the linked list
    cout << "\nAfter reversing\n";
    reverse(&stnode);

    // Display the reversed linked list
    displayList();

    return 0;
}

// Function to create the linked list with 'n' nodes
void createList(int n)
{
    struct node* frntNode, * tmp;
    int num, i;

    // Allocate memory for the first node
    stnode = new node();
    if (stnode == NULL) // Check for memory allocation failure
    {
        cout << "Memory can not be allocated";
    }
    else
    {
        // Input data for the first node
        cout << "Enter the data for node 1: ";
        cin >> num;
        stnode->num = num;
        stnode->nextptr = nullptr; // Set the next pointer of the first node to NULL
        tmp = stnode; // tmp points to the first node

        // Loop to create the remaining 'n-1' nodes
        for (i = 2; i <= n; i++)
        {
            frntNode = new node(); // Create a new node

            if (frntNode == nullptr) // Check if memory allocation fails
            {
                cout << "Memory can not be allocated";
                break;
            }
            else
            {
                // Input data for the current node
                cout << "Enter the data for node " << i << ": ";
                cin >> num;
                frntNode->num = num;
                frntNode->nextptr = nullptr; // Set the next pointer of the current node to NULL
                tmp->nextptr = frntNode; // Link the previous node to the current node
                tmp = tmp->nextptr; // Move tmp to the current node
            }
        }
    }
}

// Function to reverse the linked list
void reverse(node** stnode)
{
    node* temp = nullptr;
    node* prev = nullptr;
    node* current = (*stnode); // Start with the first node

    // Loop to reverse the links between nodes
    while (current != nullptr)
    {
        temp = current->nextptr; // Store the next node
        current->nextptr = prev; // Reverse the current node's link
        prev = current;          // Move prev to the current node
        current = temp;          // Move current to the next node
    }
    // Set the head of the list to the last node (which becomes the new head)
    (*stnode) = prev;
}

// Function to display the linked list
void displayList()
{
    struct node* tmp;

    // Check if the list is empty
    if (stnode == nullptr)
    {
        cout << "List is empty";
    }
    else
    {
        tmp = stnode; // Start from the first node
        while (tmp != nullptr) // Traverse the list until the end
        {
            cout << tmp->num << "\t"; // Print the data of the current node
            tmp = tmp->nextptr; // Move to the next node
        }
    }
}
