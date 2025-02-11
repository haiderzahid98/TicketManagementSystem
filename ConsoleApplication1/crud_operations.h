#pragma once

#ifndef CRUD_OPERATIONS_H
#define CRUD_OPERATIONS_H

#include <pqxx/pqxx>
#include <iostream>

//Function declarations

void insertCustomer(pqxx::connection& connection, const std::string& name, const std::string& phone, const std::string& email);
void fetchCustomer(pqxx::connection& connection, int customer_id);
void updateCustomerPhone(pqxx::connection& connection, int customer_id, const std::string& new_phone);
void deleteCustomer(pqxx::connection& connection, int customer_id);

#endif //CRUD_OPERATIONS_H