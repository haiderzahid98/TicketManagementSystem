#include <pqxx/pqxx>
#include <iostream>

//Insert a new customer
void insertCustomer(pqxx::connection& connection, const std::string& name, const std::string& phone, const std::string& email) {
	try {
		pqxx::work worker(connection); //start a transaction
		std::string query = "INSERT INTO customers (name, phone_number, email) VALUES (" + worker.quote(name) + ", " + worker.quote(phone) + ", " + worker.quote(email) + ");";
		worker.exec(query); //Execute the insert query
		worker.commit(); //Commit the transaction
		std::cout << "Customer inserted successfully!" << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << "Insert Error: " << e.what() << std::endl;
	}
}

//Fetch customer details by ID

void fetchCustomer(pqxx::connection& connection, int customer_id) {

	try {
		pqxx::work worker(connection); //Start a transaction
		//std::string query = "Select * from customers where customer_id = " + std::to_string(customer_id) + ";";
		pqxx::result response = worker.exec("Select * from customers where customer_id = " + worker.quote(customer_id)); // Execute the select query

		if (response.empty()) {

			std::cout << "No customer found with id: " << customer_id << std::endl;

				/* << " name: " << response[0][1].as<std::string>()
				<< " phone_number: " << response[0][2].as<std::string>()
				<< " email: " << response[0][3].as<std::string>() << std::endl;*/
		}
		else {
			for (auto row : response) {
				std::cout << "Customer ID: " << row["customer_id"].as<int>() << "\n";
				std::cout << "Name: " << row["name"].as<std::string>() << "\n";
				std::cout << "Phone: " << row["phone_number"].as<std::string>() << "\n";
				std::cout << "Email: " << row["email"].as<std::string>() << "\n";
			}
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Fetch Error: " << e.what() << std::endl;
	}
}

//Update a customer's phone number by ID
void updateCustomerPhone(pqxx::connection& connection, int customer_id, const std::string& new_phone) {
	try {
		pqxx::work worker(connection); //start a transaction
		std::string query = "UPDATE customers SET phone_number = " + worker.quote(new_phone) + " WHERE customer_id = " + worker.quote(customer_id) + ";";
		worker.exec(query); //Execute the update query
		worker.commit(); // Commit the transaction
		std::cout << "Customer's phone number updated successfully!" << std::endl;

	}
	catch (const std::exception e) {
		std::cerr << "Update Error! " << e.what() << std::endl;
	}
}


//Delete a customer by ID
void deleteCustomer(pqxx::connection& connection, int customer_id) {
	try {
		pqxx::work worker(connection); //Start a transaction
		std::string query = "DELETE FROM CUSTOMERS WHERE customer_id = " +worker.quote(customer_id) + ";";
		worker.exec(query); //Execute the delete query
		worker.commit(); //Commit the transaction
		std::cout << "Customer deleted successfully!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Delete Error!" << e.what() << std::endl;
	}

}