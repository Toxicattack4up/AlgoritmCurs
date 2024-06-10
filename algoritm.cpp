#include <iostream>
#include <limits>
#include "Client.h"
#include "HashTable.h"
#include "SkipList.h"
#include "Utils.h"
#include "TreeUtils.h"

void showMenu() 
{
    std::cout << "Выберите действие:\n";
    std::cout << "1. Добавить клиента в HashTable\n";
    std::cout << "2. Найти клиента в HashTable\n";
    std::cout << "3. Добавить клиента в SkipList\n";
    std::cout << "4. Найти клиента в SkipList\n";
    std::cout << "5. Сортировка массива (Distribution Sort)\n";
    std::cout << "6. Прямой обход дерева (Preorder Traversal)\n";
    std::cout << "7. Прямой поиск слова в тексте (Brute Force Search)\n";
    std::cout << "0. Выйти\n";
    std::cout << "Ваш выбор: ";
}

int getIntInput() 
{
    int input;
    while (true) 
    {
        std::cin >> input;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Неверный ввод. Пожалуйста, введите целое число: ";
        }
        else 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
    }
}

std::string getStringInput() 
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int main() 
{
    system("chcp 1251");
    try 
    {
        HashTable ht(10);
        SkipList sl(4, 0.5);

        while (true) 
        {
            showMenu();
            int choice = getIntInput();

            if (choice == 0) 
            {
                std::cout << "Выход из программы.\n";
                break;
            }

            switch (choice) 
            {
            case 1: 
            {
                std::cout << "Введите ID клиента: ";
                int id = getIntInput();
                std::cout << "Введите имя клиента: ";
                std::string name = getStringInput();
                std::cout << "Введите информацию об аренде: ";
                std::string rental_info = getStringInput();

                Client client = { id, name, rental_info };
                ht.insert(id, client);
                std::cout << "Клиент добавлен в HashTable.\n";
                break;
            }
            case 2: 
            {
                std::cout << "Введите ID клиента для поиска: ";
                int id = getIntInput();
                try 
                {
                    Client client = ht.search(id);
                    std::cout << "Найден клиент: " << client.getName() << "\n";
                }
                catch (const std::exception& e) 
                {
                    std::cerr << e.what() << "\n";
                }
                break;
            }
            case 3: 
            {
                std::cout << "Введите ID клиента: ";
                int id = getIntInput();
                std::cout << "Введите имя клиента: ";
                std::string name = getStringInput();
                std::cout << "Введите информацию об аренде: ";
                std::string rental_info = getStringInput();

                Client client = { id, name, rental_info };
                sl.insert(id, client);
                std::cout << "Клиент добавлен в SkipList.\n";
                break;
            }
            case 4: 
            {
                std::cout << "Введите ID клиента для поиска: ";
                int id = getIntInput();
                try 
                {
                    Client client = sl.search(id);
                    std::cout << "Найден клиент: " << client.getName() << "\n";
                }
                catch (const std::exception& e) 
                {
                    std::cerr << e.what() << "\n";
                }
                break;
            }
            case 5: 
            {
                std::cout << "Введите размер массива: ";
                int size = getIntInput();
                if (size <= 0) 
                {
                    std::cerr << "Размер массива должен быть положительным числом.\n";
                    break;
                }

                int* data = new int[size];
                std::cout << "Введите элементы массива:\n";
                for (int i = 0; i < size; i++) 
                {
                    std::cout << "Элемент " << (i + 1) << ": ";
                    data[i] = getIntInput();
                }

                distributionSort(data, size);
                std::cout << "Отсортированные данные: ";
                for (int i = 0; i < size; i++) 
                {
                    std::cout << data[i] << " ";
                }
                std::cout << "\n";
                delete[] data;
                break;
            }
            case 6: 
            {
                TreeNode* root = new TreeNode(1);
                root->left = new TreeNode(2);
                root->right = new TreeNode(3);
                root->left->left = new TreeNode(4);
                root->left->right = new TreeNode(5);

                std::cout << "Прямой обход дерева: ";
                preorderTraversal(root);
                std::cout << "\n";

                delete root->left->left;
                delete root->left->right;
                delete root->left;
                delete root->right;
                delete root;
                break;
            }
            case 7: 
            {
                std::cout << "Введите текст: ";
                std::string text = getStringInput();
                std::cout << "Введите шаблон для поиска: ";
                std::string pattern = getStringInput();

                int position = bruteForceSearch(text, pattern);
                if (position != -1) 
                {
                    std::cout << "Шаблон найден на позиции: " << position << "\n";
                }
                else 
                {
                    std::cout << "Шаблон не найден\n";
                }
                break;
            }
            default: 
            {
                std::cerr << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
            }
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}