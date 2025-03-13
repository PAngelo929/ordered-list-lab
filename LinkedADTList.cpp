#ifndef LINKED_ADT_LIST_H
#define LINKED_ADT_LIST_H
#include <stdexcept>
/**
 * A linked list implementation of an Abstract Data Type (ADT) List.
 *
 * This class provides a linked list-based implementation of a list ADT.
 * It supports operations such as adding, removing, and finding items, as well as
 * iterating through the list.
 *
 * @param DataType The type of data stored in the list.
 */
template <class DataType>
class LinkedADTList {
private:
    /**
     * Node structure for storing data and the next pointer.
     */
    struct Node {
        DataType value;
        Node* next;
    };

    Node* head; // Pointer to the first node in the list.
    int size;   // Tracks the number of elements in the list.

    /**
     * Copies another list's contents into this one.
     *
     * @param other The list to be copied.
     */
    void deepCopy(const LinkedADTList& other);

    /**
     * Deallocates memory and resets the list.
     */
    void clear();

public:
    /**
     * Constructs an empty linked list.
     */
    LinkedADTList();

    /**
     * Destroys the list and releases allocated memory.
     */
    ~LinkedADTList();

    /**
     * Constructs a copy of another linked list.
     *
     * @param other The list to duplicate.
     */
    LinkedADTList(const LinkedADTList& other);

    /**
     * Assigns another list's contents to this one.
     *
     * @param other The list to assign.
     * @return A reference to this list.
     */
    LinkedADTList& operator=(const LinkedADTList& other);

    /**
     * Retrieves the number of elements in the list.
     *
     * @return The current size of the list.
     */
    int getLength() const;

    /**
     * Adds an item to the list.
     *
     * @param item The value to insert.
     */
    void putItem(const DataType& item);

    /**
     * Searches for an item in the list.
     *
     * @param item The value to find.
     * @param found_item Stores the located item if found.
     * @return True if found, otherwise false.
     */
    bool getItem(const DataType& item, DataType& found_item) const;

    /**
     * Empties the list, removing all elements.
     */
    void makeEmpty();

    /**
     * Removes a specified item from the list.
     *
     * @param item The value to delete.
     * @return True if deleted, otherwise false.
     */
    bool deleteItem(const DataType& item);

    /**
     * Determines if the list is full.
     *
     * @return Always false since a linked list is dynamically allocated.
     */
    bool isFull() const;

    /**
     * Iterator class for traversing the list.
     */
    class Iterator {
    public:
        /**
         * Constructs an iterator for the list.
         *
         * @param myList The list being traversed.
         * @param current Pointer to the current node.
         */
        Iterator(LinkedADTList* myList, Node* current);

        /**
         * Accesses the value at the iterator's current position.
         *
         * @return Reference to the stored data.
         */
        DataType& operator*() const;

        /**
         * Moves the iterator to the next node.
         *
         * @return Reference to the updated iterator.
         */
        Iterator& operator++();

        /**
         * Compares two iterators for equality.
         *
         * @param other The iterator to compare against.
         * @return True if both point to the same position, otherwise false.
         */
        bool operator==(const Iterator& other) const;

        /**
         * Checks if two iterators are different.
         *
         * @param other The iterator to compare against.
         * @return True if they differ, otherwise false.
         */
        bool operator!=(const Iterator& other) const;

    private:
        LinkedADTList* myList; // Pointer to the linked list.
        Node* current;         // Pointer to the current node.
    };

    /**
     * Provides an iterator to the start of the list.
     *
     * @return Iterator pointing to the first element...
     */
    Iterator begin();

    /**
     * Provides an iterator to the end of the list.
     *
     * @return Iterator pointing past the last element.
     */
    Iterator end();
};

#include "LinkedADTList.cpp"

#endif // LINKED_ADT_LIST_H
