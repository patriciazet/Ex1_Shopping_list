#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>


int main()
{
    std::cout << "Please enter the product and amount: " << std::endl;
    std::string str;
    std::string product;
    std::string amountOfProduct;
    int amount = 0;
    std::map<std::string, int> shoppingList;
        
        do
    {
        std::cout << "Enter the product name: ";
        std::getline(std::cin, str);

        int it = str.find_last_of(" ");

        for (int i = 0; i < it; ++i)
        {
            str[i] = std::tolower(str[i]);
            product += str[i];
        }

        for (int i = ++it; i < str.length(); ++i)
        {
            amountOfProduct += str[i];
        }
        amount = std::atoi(amountOfProduct.c_str());


        if (shoppingList.find(product) != shoppingList.end() && str != "finish")
        {

            std::cout << "This product was entered previously: " << str << "What dou you want to do?" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Enter 1 if you wanto overwrite." << std::endl;
            std::cout << "Enter 2 if you want to sum." << std::endl;
            std::cout << "Enter 3 to skip." << std::endl;
            std::cout << "-----------------------------" << std::endl;

            int choice;

            std::cin >> choice;


            std::map<std::string, int>::iterator it = shoppingList.find(product);

            switch (choice)
            {
            case 1:
                it->second = amount;
                shoppingList.insert({ product, amount });
                break;
            case 2:
                it->second = it->second + amount;
                shoppingList.insert({ product, amount });
                break;
            case 3:
                break;
            default:
                choice = 0;
            }
        }
        else
        {
            shoppingList.insert({ product, amount });
        }
        product = {};
        amountOfProduct = {};
        amount = 0;

    } while (str != "finish");


    std::string fileName("C:\\Users\\Patrycja\\repos\\Ex1_Shopping_list\\shopping_list.txt");
    std::ofstream fileToWrite(fileName, std::ios::out | std::ios::trunc);

    if (fileToWrite.is_open())
    {
        for (auto& kv : shoppingList) {
            fileToWrite << kv.first << " " << kv.second << "\n";
        }
        fileToWrite.close();
    }
    else
    {
        std::cout << "Cannot open this file.";
        return -1;
    }
}