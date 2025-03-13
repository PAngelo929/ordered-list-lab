#include "ArrayADTList.h"

// --- Constructor & Destructor ---

// Default constructor: Initializes an empty list with a dynamically allocated array of MAX_SIZE.
template <typename DataType>
ArrayADTList<DataType>::ArrayADTList() {
   collection = new DataType[MAX_SIZE]; // Allocate memory for the array
   size = 0; // Initialize size to 0 (empty list)
}

// Copy constructor: Initializes a new list as a copy of another list.
template <typename DataType>
ArrayADTList<DataType>::ArrayADTList(const ArrayADTList& other) {
   collection = new DataType[MAX_SIZE]; // Allocate memory for the array
   size = other.size; // Copy the size from the other list
   for (int i = 0; i < size; ++i) {
       collection[i] = other.collection[i]; // Copy each element from the other list
   }
}

// Copy assignment operator: Assigns the contents of another list to this list.
template <typename DataType>
ArrayADTList<DataType>& ArrayADTList<DataType>::operator=(const ArrayADTList& other) {
   if (this != &other) { // Check for self-assignment
       size = other.size; // Copy the size from the other list
       for (int i = 0; i < size; ++i) {
           collection[i] = other.collection[i]; // Copy each element from the other list
       }
   }
   return *this; // Return the current object for chaining
}

// --- Basic Methods ---

// isFull: Checks if the list is full (i.e., size equals MAX_SIZE).
template <typename DataType>
bool ArrayADTList<DataType>::isFull() const {
   return size == MAX_SIZE; // Return true if size equals MAX_SIZE, otherwise false
}

// getLength: Returns the current number of elements in the list.
template <typename DataType>
int ArrayADTList<DataType>::getLength() const {
   return size; // Return the current size of the list
}

template <typename DataType>
int ArrayADTList<DataType>::binarySearch(const DataType& item) const {
   int low = 0;
   int high = size - 1;


   while (low <= high) {
      int mid = low + (high - low) / 2;


      // Check if the item is present at mid
      if (collection[mid] == item) {
         return mid; // Item found, return the index
      }


      // If item is greater, ignore the left half
      if (collection[mid] < item) {
         low = mid + 1;
      }
      // If item is smaller, ignore the right half
      else {
         high = mid - 1;
      }
   }


   return -1; // Item not found
}

// makeEmpty: Resets the list to an empty state by setting size to 0.
template <typename DataType>
void ArrayADTList<DataType>::makeEmpty() {
   size = 0; // Reset size to 0 (effectively making the list empty)
}

template <typename DataType>
void ArrayADTList<DataType>::putItem(const DataType& item) {


   if (isFull()) {
      throw FullError();
   }


   // Start from the last element and shift elements until the correct spot is found.
   int i = size;
   while (i > 0 && collection[i - 1] > item) {
      collection[i] = collection[i - 1];
      i--;
   }


   // Insert the new item.
   collection[i] = item;


   size++; // Increase the size.
}


template <typename DataType>
bool ArrayADTList<DataType>::getItem(const DataType& item, DataType& foundItem) const {
   int index = binarySearch(item); // Use binary search to find the item


   if (index != -1) { // If the item is found
      foundItem = collection[index];
      return true;
   }


   return false; // Item not found
}

// deleteItem: Deletes an item from the list if it exists.
template <typename DataType>
bool ArrayADTList<DataType>::deleteItem(const DataType& item) {
   int i = binarySearch(item);
   if (i == -1) {
      return false;
   }
   for (; i < size - 1; ++i) {
      collection[i] = collection[i + 1];
   }
   size--;
   return true;
}


// --- Iterator Methods ---

// begin: Returns an iterator pointing to the first element in the list.
template <typename DataType>
typename ArrayADTList<DataType>::Iterator ArrayADTList<DataType>::begin() const {
   return Iterator(this, 0); // Create and return an iterator pointing to the first element
}

// end: Returns an iterator pointing to one past the last element in the list.
template <typename DataType>
typename ArrayADTList<DataType>::Iterator ArrayADTList<DataType>::end() const {
   return Iterator(this, size); // Create and return an iterator pointing to one past the last element
}

// Iterator constructor: Initializes an iterator with a pointer to the list and an index.
template <typename DataType>
ArrayADTList<DataType>::Iterator::Iterator(const ArrayADTList<DataType>* list, int index) : list(list), index(index) {}

// Pre-increment operator: Moves the iterator to the next element in the list.
template <typename DataType>
typename ArrayADTList<DataType>::Iterator& ArrayADTList<DataType>::Iterator::operator++() {
   if (index <= list->size) { // Check if the iterator is within bounds
       ++index; // Increment the index to point to the next element
   }
   return *this; // Return the updated iterator
}

// Inequality operator: Checks if two iterators are not equal.
template <typename DataType>
bool ArrayADTList<DataType>::Iterator::operator!=(const Iterator& other) const {
   return !(*this == other); // Return true if the iterators are not equal
}

// Equality operator: Checks if two iterators are equal..
template <typename DataType>
bool ArrayADTList<DataType>::Iterator::operator==(const Iterator& other) const {
   return (this->index == other.index && this->list == other.list); // Return true if the iterators are equal
}

// Dereference operator: Returns the element at the current iterator position...
template <typename DataType>
const DataType& ArrayADTList<DataType>::Iterator::operator*() const {
   if (index >= list->size) { // Check if the iterator is out of bounds
       throw std::out_of_range("Dereferencing end iterator."); // Throw an exception if out of bounds
   }
   return list->collection[index]; // Return the element at the current index
}
