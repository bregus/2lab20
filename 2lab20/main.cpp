//
//  main.cpp
//  2lab20
//
//  Created by Рома Сумороков on 18.02.15.
//  Copyright (c) 2015 Рома Сумороков. All rights reserved.
//

#include <iostream>
#include "array.h"
#include <stdio.h>
#include <stdlib.h>


void printElement(StringArray *array, int index) {
    char *str = array->atIndex(index);
    if (str != NULL) {
        std::cout << array->atIndex(index) << std::endl;
    } else {
        std::cout << "Неверный индекс" << std::endl;
    }
}

void printAll(StringArray *array) {
    for (int i = 0; i < array->getLength(); i++) {
        std::cout << array->atIndex(i) << std::endl;
    }
}

char *readline(char *prompt, int user_block_size) {
    char *result;

    int block_size = 4;
    if (user_block_size) {
        block_size = user_block_size;
    }

    char *block, *tmp;
    int size = block_size;
    int length = 0;

    if (prompt) {
        printf("%s: ", prompt);
    }

    result = block = (char *)malloc(size * sizeof(char *));

    if (result == NULL) {
        return NULL;
    }

    *result = '\0';

    for (;;) {
        if (fgets(block, block_size, stdin) == NULL) {
            break;
        }

        length += strlen(block);

        if (result[length - 1] == '\n') {
            break;
        }

        size += block_size;
        tmp = (char *)realloc(result, size * sizeof(char *));
        if (tmp == NULL) {
            break;
        }

        result = tmp;
        block = result + length;
    }

    if (result[0] == '\0') {
        free(result);
        result = NULL;
    }


    return result;
}

int menu()
{
    int choise;
    std::cout << "Выберите вариант" << std::endl;
    std::cout << "1. Добавить стркочку." << std::endl;
    std::cout << "2. Найти строчку." << std::endl;
    std::cout << "3. Поэлементно сцепить с другим массивом." << std::endl;
    std::cout << "4. Объедининть два массива с исключением повторяющихся." << std::endl;
    std::cout << "5. Найти строки, имеющиеся в обоих массивах." << std::endl;
    std::cout << "6. Вывести один элемент массива." << std::endl;
    std::cout << "7. Вывести весь массив." << std::endl;
    std::cout << "8. Выход." << std::endl;
    std::cin >> choise;
    return choise;
}

int main() {
    /*
    Составить описание класса одномерных массивов строк, каждая строка задается
    длиной и указателем на выделенную для нее память. Предусмотреть возможность
    обращения к отдельным строкам массива по индексам и по начальной комбинации
    символов, контроль выхода за пределы массивов, выполнения операций
    поэлементного сцепления двух массивов с образованием нового массива, слияния
    двух массивов с исключением повторяющихся элементов, пересечения двух
    массивов (строки, имеющиеся в обоих массивах), вывод на экран элемента
    массива и всего массива. Программа должна содержать меню, позволяющее
    осуществлять проверку всех методов.
    */
    StringArray *mass = new StringArray();
    while (true) {
        int menuChoise = menu();
        if (menuChoise == 8) break;
        switch (menuChoise) {
            case 1:
                char *str1;

        }
    }




//    const char *str[] = {"Bob", "Alum", "qwerwe", "Asd", "Rtfdv", "Opun"};
//
//    for (int i = 0; i < 6; i++) {
//        char *copy = strdup(str[i]);
//        mass->addString(copy);
//    }
////    char *str2 = strdup("Bo");
////    std::cout << mass->search(str2) << std::endl;
////    printElement(mass, 10);
////    printAll(mass);
//
//    StringArray *mass2 = new StringArray();
//    const char *str2[] = {"sdf", "ewqe", "xvcb", "Bob", "hnfhd", "fdgs", "Dan", "Lisa"};
//    for (int i = 0; i < 8; i++) {
//        char *copy = strdup(str2[i]);
//        mass2->addString(copy);
//    }
//    StringArray *mass3 = mass->difference(mass2);
//    printAll(mass3);

    return 0;
}