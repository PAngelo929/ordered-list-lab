#include <iostream>
#include <fstream>
#include "LinkedADTList.h"
#include "Customer.h"

// Function declarations
void loadCustomersIntoList(const std::string& filename, LinkedADTList<Customer>& customerList, int maxCustomers);
void demonstrateIntDataType();
void demonstrateCustomerClass();

int main() {
   using namespace std;

   // Demonstrate the functionality of LinkedADTList with the int data type
   cout << "Testing LinkedADTList with int data type:" << endl;
   demonstrateIntDataType();

   // Demonstrate the functionality of LinkedADTList with the Customer class
   cout << "\nNow demonstrating LinkedADTList with Customer class:" << endl;
   demonstrateCustomerClass();

   return 0;
}

// Function implementations

// Loads customer data from a file into the provided customer list
void loadCustomersIntoList(const std::string& filename, LinkedADTList<Customer>& customerList, int maxCustomers) {
   std::ifstream file(filename); // Open the file for reading

   if (!file) { // Check if the file was successfully opened
       std::cerr << "Unable to open file!" << std::endl;
       return;
   }

   std::string line;
   std::getline(file, line);  // Skip the header line in the file

   int count = 0;
   while (std::getline(file, line) && count < maxCustomers) { // Read each line until maxCustomers is reached
       Customer customer(line); // Create a Customer object from the line
       customerList.putItem(customer); // Add the customer to the list
       count++; // Increment the count of loaded customers
   }

   file.close(); // Close the file
}

// Demonstrates the functionality of LinkedADTList using integers
void demonstrateIntDataType() {
   LinkedADTList<int> intList; // Create a list of integers

   // Add integers to the list
   intList.putItem(5);
   intList.putItem(10);
   intList.putItem(15);
   intList.putItem(20);

   // Display the number of items in the list
   std::cout << "intList contains " << intList.getLength() << " items." << std::endl;

   // Search for an item in the list
   int foundItem;
   if (intList.getItem(10, foundItem)) {
       std::cout << "Found item: " << foundItem << " in the list." << std::endl;
   } else {
       std::cout << "Item not found in the list." << std::endl;
   }

   // Delete an item from the list
   if (intList.deleteItem(10)) {
       std::cout << "Deleted item 10 from the list." << std::endl;
   } else {
       std::cout << "Could not delete item 10 from the list." << std::endl;
   }

   // Display the contents of the list
   std::cout << "Items in the list: ";
   for (LinkedADTList<int>::Iterator it = intList.begin(); it != intList.end(); ++it) {
       std::cout << *it << " ";
   }
   std::cout << std::endl;

   // Demonstrate copy constructor
   LinkedADTList<int> intListCopy = intList;
   std::cout << "After copy, intListCopy contains: ";
   for (LinkedADTList<int>::Iterator it = intListCopy.begin(); it != intListCopy.end(); ++it) {
       std::cout << *it << " ";
   }
   std::cout << std::endl;

   // Demonstrate assignment operator
   LinkedADTList<int> intListAssigned;
   intListAssigned = intList;
   std::cout << "After assignment, intListAssigned has: ";
   for (LinkedADTList<int>::Iterator it = intListAssigned.begin(); it != intListAssigned.end(); ++it) {
       std::cout << *it << " ";
   }
   std::cout << std::endl;

   // Empty the list and display its size
   intList.makeEmpty();
   std::cout << "intList now has " << intList.getLength() << " items after clearing." << std::endl;
}

// Demonstrates the functionality of LinkedADTList using the Customer class
void demonstrateCustomerClass() {
   LinkedADTList<Customer> customerList; // Create a list of Customer objects

   // Load customer data from a file into the list
   loadCustomersIntoList("customer_data/Customer.txt", customerList, 5);

   // Display the total number of customers in the list
   std::cout << "There are " << customerList.getLength() << " customers in the list." << std::endl;
   std::cout << "Customer details: " << std::endl;
   for (LinkedADTList<Customer>::Iterator it = customerList.begin(); it != customerList.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }

   // Demonstrate copy constructor
   LinkedADTList<Customer> customerListCopy = customerList;
   std::cout << "\nAfter copy, customerListCopy contains: " << std::endl;
   for (LinkedADTList<Customer>::Iterator it = customerListCopy.begin(); it != customerListCopy.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }

   // Demonstrate assignment operator
   LinkedADTList<Customer> customerListAssigned;
   customerListAssigned = customerList;
   std::cout << "\nAfter assignment, customerListAssigned has: " << std::endl;
   for (LinkedADTList<Customer>::Iterator it = customerListAssigned.begin(); it != customerListAssigned.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }

   // Empty the list and display its size
   customerList.makeEmpty();
   std::cout << "\ncustomerList now has " << customerList.getLength() << " customers after clearing." << std::endl;

   // Display the contents of the list after clearing
   std::cout << "Listing contents of customerList after clearing: " << std::endl;
   for (LinkedADTList<Customer>::Iterator it = customerList.begin(); it != customerList.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }

   // Display the contents of the copied list
   std::cout << "\ncustomerListCopy still contains: " << std::endl;
   for (LinkedADTList<Customer>::Iterator it = customerListCopy.begin(); it != customerListCopy.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }

   // Display the contents of the assigned list
   std::cout << "\ncustomerListAssigned still holds: " << std::endl;
   for (LinkedADTList<Customer>::Iterator it = customerListAssigned.begin(); it != customerListAssigned.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }
}

