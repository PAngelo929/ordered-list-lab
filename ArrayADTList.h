#ifndef ARRAY_ADT_LIST_H
#define ARRAY_ADT_LIST_H

#include <stdexcept>

template <typename DataType>
class ArrayADTList {
private:
   static const int MAX_SIZE = 100;
   DataType* collection;
   int size;

public:
   /**
    * Nested iterator class for traversing the ArrayADTList.
    */
   class Iterator;

   /**
    * Constructs an empty ArrayADTList.
    */
   ArrayADTList();

   /**
    * Copy constructor that initializes a new list as a duplicate of an existing one.
    * @param other The list to duplicate.
    */
   ArrayADTList(const ArrayADTList& other);

   /**
    * Overloaded assignment operator to copy the contents of one list to another.
    * @param other The list to copy from.
    * @return A reference to the current list after assignment.
    */
   ArrayADTList& operator=(const ArrayADTList& other);

   /**
    * Determines whether the list has reached its maximum capacity.
    * @return true if the list is full, false otherwise.
    */
   bool isFull() const;

   /**
    * Retrieves the number of elements currently stored in the list.
    * @return The total number of elements in the list.
    */
   int getLength() const;

   /**
    * Clears the list, removing all elements.
    */
   void makeEmpty();

   /**
    * Inserts a new item into the list.
    * @param item The item to be added.
    * @throw std::out_of_range if the list has reached its maximum capacity.
    */
   void putItem(const DataType& item);

   /**
    * Performs a binary search to locate the specified item in the list.
    * @param item The item being searched for.
    * @return The index of the item if found; otherwise, -1.
    */
   int binarySearch(const DataType& item) const;

   /**
    * Looks for an item in the list.
    * @param item The target item to find.
    * @param foundItem The retrieved item if found.
    * @return true if the item exists in the list, otherwise false.
    */
   bool getItem(const DataType& item, DataType& foundItem) const;

   /**
    * Removes an item from the list if it exists.
    * @param item The item to be removed.
    * @return true if the item was successfully deleted, otherwise false.
    */
   bool deleteItem(const DataType& item);

   /**
    * Provides an iterator pointing to the first element of the list.
    * @return An iterator at the beginning of the list.
    */
   Iterator begin() const;

   /**
    * Provides an iterator pointing past the last element of the list.
    * @return An iterator at the end of the list.
    */
   Iterator end() const;

   class Iterator {
   private:
       const ArrayADTList<DataType>* list;
       int index;

   public:
       /**
        * Constructs an iterator with a specified list and position.
        * @param list The list being traversed.
        * @param index The current position within the list.
        */
       Iterator(const ArrayADTList<DataType>* list, int index);

       /**
        * Moves the iterator to the next item in the list.
        * @return A reference to the updated iterator.
        */
       Iterator& operator++();

       /**
        * Checks if two iterators point to different positions.
        * @param other The iterator to compare with.
        * @return true if the iterators differ, otherwise false.
        */
       bool operator!=(const Iterator& other) const;

       /**
        * Checks if two iterators point to the same position.
        * @param other The iterator to compare with.
        * @return true if both iterators are equal, otherwise false.
        */
       bool operator==(const Iterator& other) const;

       /**
        * Dereferences the iterator to access the current item.
        * @return A reference to the item at the iterator’s position.
        * @throw std::out_of_range if accessing beyond the list’s boundaries.
        */
       const DataType& operator*() const;
   };

   class FullError {
   public:
       /**
        * Retrieves an error message when the list is full.
        * @return A string indicating the list has reached capacity.
        */
       char const *message() { return "List is full."; }
   };
};

#include "ArrayADTList.cpp"

#endif
