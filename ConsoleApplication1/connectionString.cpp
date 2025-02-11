
#pragma once

#include <string>
#include <iostream>
#include <pqxx/pqxx>

int main()
{
    std::string connectionString = "host=localhost port=5432 dbname=air_ticket_db user=postgres password =Allahone7861";

    try
    {
        pqxx::connection connectionObject(connectionString.c_str()); //pqxx library using connection class to connect with db server

        pqxx::work worker(connectionObject); //pqxx lib uses work class to manage db transaction

        pqxx::result response = worker.exec("SELECT * FROM customers"); //pqxx lib uses result class to get response of query

        //Commented code got from imlint wiki which helped me setup this c++ connection with postgres, with this one i get errors
        /*for (size_t i = 0; i < response.size(); i++)
        {
            std::cout << "Id: " << response[i][0] << " Username: " << response[i][1] << " Password: " << response[i][2] << " Email: " << response[i][3] << std::endl;
        }*/
     
        //this one got from chatgpt that works, need to understand whats the difference
    
        for (size_t i = 0; i < response.size(); i++)
        {
            std::cout << "customer_id: " << response[i][0].as<std::string>()
                << " name: " << response[i][1].as<std::string>()
                << " phone_number: " << response[i][2].as<std::string>()
                << " email: " << response[i][3].as<std::string>() << std::endl;
        }


    }
    //to handle error if there's any
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    system("pause");
}