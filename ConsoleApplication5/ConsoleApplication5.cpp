#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

struct Product { // Struct, where are all parametrs about inventory
	string name;
	string producer;
	double price = 0.0;
	string category;
	string arrivalDate;
	string expirationDate;
};


void addProduct(vector<Product>& inventory) {
	Product product;
	cout << "Enter product details:" << endl;
	cout << "Name: ";
	cin >> product.name;
	cout << "Manufacturer: ";
	cin >> product.producer;
	cout << "Price: ";
	cin >> product.price;
	cout << "Category: ";
	cin >> product.category;
	cout << "Arrival date: ";
	cin >> product.arrivalDate;
	cout << "Expiration date: ";
	cin >> product.expirationDate;
	inventory.push_back(product); // Add the product to the end of vector
	cout << "Product added to inventory." << endl;
}


void replaceProduct(vector<Product>& inventory) {
	string name;
	cout << "Enter the name of the product to replace: ";
	cin >> name;
	auto it = find_if(inventory.begin(), inventory.end(), [&](const Product& p) { // find iterator of the product
		return p.name == name; // if find return true, else false and continue finding
	});

	if (it != inventory.end()) { // if iterator is not equal to the end of vector, than user input new parametrs
		Product newProduct;
		cout << "Enter new product details:\n";
		cout << "Name: ";
		cin >> newProduct.name;
		cout << "Manufacturer: ";
		cin >> newProduct.producer;
		cout << "Price: ";
		cin >> newProduct.price;
		cout << "Category: ";
		cin >> newProduct.category;
		cout << "Arrival date: ";
		cin >> newProduct.arrivalDate;
		cout << "Expiration date: ";
		cin >> newProduct.expirationDate;
		*it = newProduct;
		cout << "Product replaced in inventory.\n";
	}
	else { // if iterator is equal to the end of vector
		cout << "Product not found in inventory.\n";
	}
}


void Print_functions_Names() {  // Print all functions that can user 
	cout << "\n\tInventory Menu \n";
	cout << "1. Add product\n";
	cout << "2. Remove product\n";
	cout << "3. Replace product\n";
	cout << "4. Search product by name\n";
	cout << "5. Search product by producer\n";
	cout << "6. Search product by price\n";
	cout << "7. Search product by category\n";
	cout << "8. Search product by arrival date\n";
	cout << "9. Search product by expiration date\n";
	cout << "10. Sort inventory by name\n";
	cout << "11. Sort inventory by price\n";
	cout << "12. Sort inventory by category\n";
	cout << "13. Print all parametrs of each Product\n";
	cout << "14. Clear console\n";
	cout << "0. Exit\n\n";
	cout << "Enter your choice: ";
}

void deleteProduct(vector<Product>& inventory) {
	string name;
	cout << "Enter the name of the product to remove: ";
	cin >> name;
	auto iterator = find_if(inventory.begin(), inventory.end(), [&](const Product& p) { // find iterator of the product
		return p.name == name; // if find return true, else false and continue finding
	});

	if (iterator != inventory.end()) { // if iterator is not equal to the end of vector, than the product delete
		inventory.erase(iterator);
		cout << "Product removed from inventory.\n";
	}
	else {// if iterator is equal to the end of vector
		cout << "Product not found in inventory.\n";
	}
}





void searchByArrivalDate(vector<Product>& inventory) 
{
	string arrivalDate;
	cout << "Enter the arrival date of the product to search: ";
	cin >> arrivalDate;
	bool found = false;
	for (const auto& product : inventory) // take the product in the variable product and find throuht if, 
	{
		if (product.arrivalDate == arrivalDate) //  if there is arrival Date, print all parametrs about product that have this arrival Date
		{
			cout << "Product details:\n";
			cout << "Name: " << product.name << endl;
			cout << "Producer: " << product.producer << endl;
			cout << "Price: " << product.price << endl;
			cout << "Category: " << product.category << endl;
			cout << "Arrival date: " << product.arrivalDate << endl;
			cout << "Expiration date: " << product.expirationDate << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Product not found in inventory.\n";
	}
}


void searchByCategory(vector<Product>& inventory)
{
	string category;
	cout << "Enter the category of the product to search: ";
	cin >> category;
	bool found = false;
	for (const auto& product : inventory) // take the product in the variable product and find throuht if, 
	{
		if (product.category == category) //  if there is category, print all parametrs about product that have this category
		{
			cout << "Product details:\n";
			cout << "Name: " << product.name << endl;
			cout << "Producer: " << product.producer << endl;
			cout << "Price: " << product.price << endl;
			cout << "Category: " << product.category << endl;
			cout << "Arrival date: " << product.arrivalDate << endl;
			cout << "Expiration date: " << product.expirationDate << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Product not found in inventory.\n";
	}
}

void searchByExpirationDate(vector<Product>& inventory) // take the product in the variable product and find throuht if, 
{
	string expirationDate;
	cout << "Enter the expiration date of the product to search: ";
	cin >> expirationDate;
	bool found = false;
	for (const auto& product : inventory)  // take the product in the variable product and find throuht if, 
	{
		if (product.expirationDate == expirationDate) //  if there is expiration Date, print all parametrs about product that have this expiration Date
		{
			cout << "Product details:\n";
			cout << "Name: " << product.name << std::endl;
			cout << "Producer: " << product.producer << std::endl;
			cout << "Price: " << product.price << std::endl;
			cout << "Category: " << product.category << std::endl;
			cout << "Arrival date: " << product.arrivalDate << std::endl;
			cout << "Expiration date: " << product.expirationDate << std::endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "Product not found in inventory.\n";
	}
}


void searchByName(vector<Product>& inventory) 
{
	string name;
	cout << "Enter the name of the product to search: ";
	cin >> name;
	bool found = false;
	for (auto& product : inventory) // take the product in the variable product and find throuht if, 
	{
		if (product.name == name) //  if there is producer, print all parametrs about product that have this producer
		{
			cout << "Product details:" << endl;
			cout << "Name: " << product.name << endl;
			cout << "Producer: " << product.producer << endl;
			cout << "Price: " << product.price << endl;
			cout << "Category: " << product.category << endl;
			cout << "Arrival date: " << product.arrivalDate << endl;
			cout << "Expiration date: " << product.expirationDate << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Product not found in inventory.\n";
	}
}



void searchByPrice(vector<Product>& inventory) 
{
	double price;
	cout << "Enter the price of the product to search: ";
	cin >> price;
	bool found = false;
	for (auto& product : inventory) // take the product in the variable product and find throuht if, 
	{
		if (product.price == price) //  if there is producer, print all parametrs about product that have this producer
		{
			cout << "Product details:\n";
			cout << "Name: " << product.name << endl;
			cout << "Producer: " << product.producer << endl;
			cout << "Price: " << product.price << endl;
			cout << "Category: " << product.category << endl;
			cout << "Arrival date: " << product.arrivalDate << endl;
			cout << "Expiration date: " << product.expirationDate << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "Product not found in inventory.\n";
	}
}


void searchByProducer(vector<Product>& inventory)
{
	string producer;
	cout << "Enter the producer of the product to search: ";
	cin >> producer;
	bool found = false;
	for (auto& product : inventory) // take the product in the variable product and find throuht if, 
	{
		if (product.producer == producer) //  if there is producer, print all parametrs about product that have this producer
		{
			cout << "Product details:" << endl;
			cout << "Name: " << product.name << endl;
			cout << "Producer: " << product.producer << endl;
			cout << "Price: " << product.price << endl;
			cout << "Category: " << product.category << endl;
			cout << "Arrival date: " << product.arrivalDate << endl;
			cout << "Expiration date: " << product.expirationDate << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "Product not found in inventory.\n";
	}
}

void sortByName(vector<Product>& inventory)
{
	sort(inventory.begin(), inventory.end(), [](const Product& p1, const Product& p2) {// Take first element
		return p1.name < p2.name;  // of the name and following element of the name and if 
	});							  // p1 < p2, return false, else true
	cout << "Inventory sorted by name.\n";
}

void sortByPrice(vector<Product>& inventory) 
{
	sort(inventory.begin(), inventory.end(), [](const Product& p1, const Product& p2) {// Take first element
		return p1.price < p2.price;	  // of the price and following element of the price and if 
    });                              // p1 < p2, return false, else true
	cout << "Inventory sorted by price.\n";
}


void sortByCategory(vector<Product>& inventory)
{
	sort(inventory.begin(), inventory.end(), [](const Product& p1, const Product& p2) { // Take first element
		return p1.category < p2.category; // of the category and following element of the category and if 
	});                                   // p1 < p2, return false, else true
	cout << "Inventory sorted by category.\n";
}



void Print_All(vector<Product>& inventory) {
	int i = 1;
	for (auto& product : inventory) { // Print all parametrs about product
		cout << "---Inventory of " << i << " product---\n";
		cout << "Name: " << product.name << endl;
		cout << "Producer: " << product.producer << endl;
		cout << "Price: " << product.price << endl;
		cout << "Category: " << product.category << endl;
		cout << "Arrival date: " << product.arrivalDate << endl;
		cout << "Expiration date: " << product.expirationDate << endl << endl << endl;
		i++;
	}
}


void Ñlear_Console() {
	system("cls");
}


int main() {
	vector<Product> inventory;
	int choice = 0;

	do {
		Print_functions_Names();
		cin >> choice;

		Ñlear_Console();

		switch (choice) { // if choice is equal to number from 1 - 13, some function is called
		case 1:
			addProduct(inventory);
			break;
		case 2:
			deleteProduct(inventory);
			break;
		case 3:
			replaceProduct(inventory);
			break;
		case 4:
			searchByName(inventory);
			break;
		case 5:
			searchByProducer(inventory);
			break;
		case 6:
			searchByPrice(inventory);
			break;
		case 7:
			searchByCategory(inventory);
			break;
		case 8:
			searchByArrivalDate(inventory);
			break;
		case 9:
			searchByExpirationDate(inventory);
			break;
		case 10:
			sortByName(inventory);
			break;
		case 11:
			sortByPrice(inventory);
			break;
		case 12:
			sortByCategory(inventory);
			break;
		case 13:
			Print_All(inventory);
			break;
		case 14:
			Ñlear_Console();
			break;
		case 0:
			cout << "Program End!!!\n"; // Program ending
			break;
		default: // if user input invalid number
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 0); // Starts the loop again unless the user enters 0
}