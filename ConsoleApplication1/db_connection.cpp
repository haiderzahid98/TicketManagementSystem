
#pragma once

/*#include <string>
#include <iostream>
#include <pqxx/pqxx>*/

#include "db_connection.h"

//Function to connect to the PostgreSQL Database

pqxx::connection connectToDatabase() {
	//std::string connectionString = "host=localhost port=5432 dbname=air_ticket_db user=postgres password=Allahone7861";
	try {
		std::string connectionString = "host=localhost port=5432 dbname=air_ticket_db user=postgres password=Allahone7861";
		pqxx::connection connection(connectionString);

		if (connection.is_open()) {
			std::cout << "Connected to database successfully!\n: " << connection.dbname() << std::endl;
		}
		else {
			std::cerr << "Connection failed! " << std::endl;
		}
		return connection;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		throw;// rethrow the exception
	}
}