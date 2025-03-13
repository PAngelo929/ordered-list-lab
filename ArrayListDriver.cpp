#include <iostream>
#include <fstream>
#include "ArrayADTList.h"
#include "Customer.h"

// Function prototypes
void loadCustomersIntoList(const std::string& filename, ArrayADTList<Customer>& customerList, int maxCustomers);
void demonstratePrimitiveDataType();
void demonstrateCustomerClass();

int main() {
   using namespace std;

   // Demonstrate the functionality of ArrayADTList with a primitive data type (int)
   cout << "Demonstrating ArrayADTList with primitive data type (int):" << endl;
   demonstratePrimitiveDataType();

   // Demonstrate the functionality of ArrayADTList with the Customer class
   cout << "\nDemonstrating ArrayADTList with Customer class:" << endl;
   demonstrateCustomerClass();

   return 0;
}

// Function implementations

// Loads customer data from a file into the provided customer list
void loadCustomersIntoList(const std::string& filename, ArrayADTList<Customer>& customerList, int maxCustomers) {
   std::ifstream file(filename); // Open the file for reading

   if (!file) { // Check if the file was successfully opened..
       std::cerr << "Error: Unable to open file!" << std::endl;
       return;
   }

   std::string line;
   std::getline(file, line); // Ignore the header line in the file

   int count = 0;
   while (std::getline(file, line) && count < maxCustomers) { // Read each line until maxCustomers is reached
       Customer customer(line); // Create a Customer object from the line
       customerList.putItem(customer); // Add the customer to the list
       count++; // Increment the count of loaded customers
   }

   file.close(); // Close the file
}

// Demonstrates the functionality of ArrayADTList using integers
void demonstratePrimitiveDataType() {
   ArrayADTList<int> intList; // Create a list of integers

   // Add integers to the list
   intList.putItem(5);
   intList.putItem(10);
   intList.putItem(15);
   intList.putItem(20);

   // Display the contents of the list
   std::cout << "Contents of intList: ";
   for (ArrayADTList<int>::Iterator it = intList.begin(); it != intList.end(); ++it) {
       std::cout << *it << " ";
   }
   std::cout << std::endl;

   // Display the size of the list
   std::cout << "Size of intList: " << intList.getLength() << std::endl;

   // Search for an item in the list
   int foundItem;
   if (intList.getItem(10, foundItem)) {
       std::cout << "Located in intList: " << foundItem << std::endl;
   } else {
       std::cout << "10 not found in intList." << std::endl;
   }

   // Delete an item from the list
   if (intList.deleteItem(10)) {
       std::cout << "Deleted 10 from intList." << std::endl;
   } else {
       std::cout << "Could not locate 10 in intList." << std::endl;
   }

   // Display the updated contents of the list
   std::cout << "Updated intList: ";
   for (ArrayADTList<int>::Iterator it = intList.begin(); it != intList.end(); ++it) {
       std::cout << *it << " ";
   }
   std::cout << std::endl;

   // Empty the list and display its size
   intList.makeEmpty();
   std::cout << "Size of intList after emptying: " << intList.getLength() << std::endl;
}

// Demonstrates the functionality of ArrayADTList using the Customer class
void demonstrateCustomerClass() {
   ArrayADTList<Customer> customerList; // Create a list of Customer objects

   // Load customer data from a file into the list
   loadCustomersIntoList("customer_data/Customer.txt", customerList, 5);

   // Display the total number of customers loaded
   std::cout << "Total customers loaded: " << customerList.getLength() << std::endl;
   std::cout << std::endl;

   // Display details of each customer in the list
   std::cout << "Customer details:" << std::endl;
   for (ArrayADTList<Customer>::Iterator it = customerList.begin(); it != customerList.end(); ++it) {
       std::cout << (*it).toString() << std::endl;
   }

   // Empty the list and display its size
   std::cout << std::endl;
   customerList.makeEmpty();
   std::cout << "Total customers after clearing list: " << customerList.getLength() << std::endl;
}
