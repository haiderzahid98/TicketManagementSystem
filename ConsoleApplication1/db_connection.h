#pragma once

#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <pqxx/pqxx> //include pqxx for database connection
#include <iostream>

//Function to connect to the db

pqxx::connection connectToDatabase();

#endif //db_connection_h
