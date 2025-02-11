#include <iostream>
#include <pqxx/pqxx>
#include "db_connection.h" // connection string
#include "crud_operations.h" //create/update/delete operations file

int main() {

	try {

		//Establis a connection to the db

		pqxx::connection connection = connectToDatabase();
		//Test insert
		insertCustomer(connection, "Haider Zahid", "11118888", "test@test.com");

		//test fetch
		fetchCustomer(connection, 1);

		//test update
		updateCustomerPhone(connection, 1, "789876123");

		//Test delete

		deleteCustomer(connection, 2);
	}
	catch (const std::exception& e) {
		std::cout << "Error" << e.what() << std::endl;
	}

	return 0;


}