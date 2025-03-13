#include <iostream>
#include "LinkedADTList.h"

// Constructor: Initializes an empty linked list
template <class DataType>
LinkedADTList<DataType>::LinkedADTList() {
   head = nullptr; // Set head to nullptr (empty list)
   size = 0; // Initialize size to 0
}

// Destructor: Clears the list to free memory
template <class DataType>
LinkedADTList<DataType>::~LinkedADTList() {
   clear(); // Call the clear function to delete all nodes
}

// Copy Constructor: Creates a deep copy of another list
template <class DataType>
LinkedADTList<DataType>::LinkedADTList(const LinkedADTList& other) {
   head = nullptr; // Initialize head to nullptr
   size = 0; // Initialize size to 0
   deepCopy(other); // Perform a deep copy of the other list
}

// Assignment Operator: Assigns the contents of another list to this list
template <class DataType>
LinkedADTList<DataType>& LinkedADTList<DataType>::operator=(const LinkedADTList& other) {
   if (this != &other) { // Check for self-assignment
       clear(); // Clear the current list
       deepCopy(other); // Perform a deep copy of the other list
   }
   return *this; // Return the current object for chaining
}

// Get length: Returns the number of items in the list
template <class DataType>
int LinkedADTList<DataType>::getLength() const {
   return size; // Return the size of the list
}

// Insert item to the list
template <class DataType>
void LinkedADTList<DataType>::putItem(const DataType& item) {
   Node *temp = new Node; // Create a new node
   temp->value = item; // Set the value of the new node
   if (head == nullptr) {
      head = temp;
      size++;
      return;
   }
   Node* prev = nullptr;
   Node* curr = head;
   while (curr != nullptr) {
      if (curr->value < item) {
         prev = curr;
         curr = curr->next;
      } else {
         break;
      }
   }
   if (prev == nullptr) {
      temp->next = curr;
      head = temp;
   } else {
      temp->next = curr;
      prev->next = temp;
   }
   size++;
}


// Retrieve an item: Searches for an item in the list and returns it if found
template <class DataType>
bool LinkedADTList<DataType>::getItem(const DataType& item, DataType& found_item) const {
   Node* current = head; // Start at the head of the list
   while (current != nullptr) { // Traverse the list
       if (current->value == item) { // Check if the current node's value matches the item
           found_item = current->value; // Return the found item
           return true; // Indicate success
       }
       current = current->next; // Move to the next node
   }
   return false; // Indicate the item was not found
}

// Make list empty: Clears the list by deleting all nodes
template <class DataType>
void LinkedADTList<DataType>::makeEmpty() {
   clear(); // Call the clear function to delete all nodes
}

// Delete an item: Removes an item from the list if it exists
template <class DataType>
bool LinkedADTList<DataType>::deleteItem(const DataType& item) {
   Node *previous = nullptr; // Pointer to the previous node
   Node *current = head; // Pointer to the current node
   while (current != nullptr && current->value != item) { // Traverse the list
       previous = current; // Update the previous node
       current = current->next; // Move to the next node
   }
   if (current == nullptr) { // If the item was not found.
       return false; // Indicate failure
   }
   if (previous == nullptr) { // If the item is at the head
       head = head->next; // Update head to skip the current node.
   } else { // If the item is in the middle or end
       previous->next = current->next; // Skip the current node
   }
   delete current; // Free the memory of the deleted node
   size--; // Decrement the size of the list
   return true; // Indicate success
}

// Check if list is full: Always returns false for a linked list
template <class DataType>
bool LinkedADTList<DataType>::isFull() const {
   return false; // Linked lists are never full
}

// Deep copy function: Creates a deep copy of another list
template <class DataType>
void LinkedADTList<DataType>::deepCopy(const LinkedADTList& other) {
   clear(); // Clear the current list

   if (other.head == nullptr) { // If the other list is empty
       head = nullptr; // Set head to nullptr
       size = 0; // Set size to 0
       return;
   }

   head = new Node; // Create a new head node
   Node* curr = head; // Pointer to the current node in the new list
   Node* other_curr = other.head; // Pointer to the current node in the other list

   curr->value = other_curr->value; // Copy the value from the other list
   curr->next = nullptr; // Set the next pointer to nullptr
   other_curr = other_curr->next; // Move to the next node in the other list

   while (other_curr != nullptr) { // Traverse the other list
       curr->next = new Node; // Create a new node in the new list.
       curr = curr->next; // Move to the new node
       curr->value = other_curr->value; // Copy the value from the other list
       curr->next = nullptr; // Set the next pointer to nullptr
       other_curr = other_curr->next; // Move to the next node in the other list
   }

   size = other.size; // Copy the size of the other list
}

// Clear the list: Deletes all nodes in the list
template <class DataType>
void LinkedADTList<DataType>::clear() {
   while (head != nullptr) { // Traverse the list
       Node* temp = head; // Store the current head node
       head = head->next; // Move head to the next node
       delete temp; // Delete the stored node
   }
   size = 0; // Reset the size to 0
}

// Iterator Constructor: Initializes an iterator with a list and a node
template <class DataType>
LinkedADTList<DataType>::Iterator::Iterator(LinkedADTList* myList, Node* current) {
   this->myList = myList; // Set the list pointer
   this->current = current; // Set the current node pointer
}

// Iterator Dereference Operator: Returns the value of the current node
template <class DataType>
DataType& LinkedADTList<DataType>::Iterator::operator*() const {
   if (current == nullptr) { // Check if the iterator is at the end
       throw std::out_of_range("Iterator is at the end of the list.");
   }
   return current->value; // Return the value of the current node
}

// Iterator Pre-increment Operator: Moves the iterator to the next node
template <class DataType>
typename LinkedADTList<DataType>::Iterator& LinkedADTList<DataType>::Iterator::operator++() {
   if (current == nullptr) { // Check if the iterator is at the end
       throw std::out_of_range("Iterator is at the end of the list.");
   }
   current = current->next; // Move to the next node
   return *this; // Return the updated iterator
}

// Iterator Equality Comparison: Checks if two iterators are equal
template <class DataType>
bool LinkedADTList<DataType>::Iterator::operator==(const Iterator& other) const {
   return (current == other.current); // Compare the current nodes
}

// Iterator Inequality Comparison: Checks if two iterators are not equal
template <class DataType>
bool LinkedADTList<DataType>::Iterator::operator!=(const Iterator& other) const {
   return !(*this == other); // Use the equality operator for comparison
}

// Begin: Returns an iterator pointing to the first node in the list
template <class DataType>
typename LinkedADTList<DataType>::Iterator LinkedADTList<DataType>::begin() {
   return Iterator(this, head); // Create and return an iterator at the head
}

// End: Returns an iterator pointing to one past the last node in the list
template <class DataType>
typename LinkedADTList<DataType>::Iterator LinkedADTList<DataType>::end() {
   return Iterator(this, nullptr); // Create and return an iterator at the end
}
