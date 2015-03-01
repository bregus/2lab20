//
//  array.cpp
//  2lab20
//
//  Created by Рома Сумороков on 19.02.15.
//  Copyright (c) 2015 Рома Сумороков. All rights reserved.
//

#include "array.h"
#include <iostream>
#include "strings.h"

StringArray::StringArray() {
    this->_allocLength = 4;
    this->_logicalLength = 0;
    this->_items = new char*[this->_allocLength];
    for (int i = 0; i < this->_allocLength; i++) {
        this->_items[i] = strdup("");
    }
}

StringArray::~StringArray() {
    for (int i = 0; i < this->_logicalLength; i++) {
        delete &this->_items[i];
    }
    delete this->_items;
}

void StringArray::addString (char *str) {
    if (this->_logicalLength == this->_allocLength) {
        this->increaseSize();
    }

    char *copy = new char[strlength(str) + 1];
    strcopy(str, copy);
    this->_items[this->_logicalLength] = copy;
    this->_logicalLength++;

}

void StringArray::increaseSize() {
    char **temp = new char*[this->_allocLength*2];
    for (int i = 0; i < this->_allocLength*2; i++) {
        temp[i] = strdup("");
    }
    for (int i = 0; i < this->_allocLength; i++) {
        temp[i] = this->_items[i];
    }
    delete this->_items;
    
    this->_items = temp;
    
    this->_allocLength *= 2;
}

char *StringArray::atIndex(int index){
    if (index > this->_logicalLength) {
        return NULL;
    }
    return this->_items[index];
}

int StringArray::getLength (){
    return this->_logicalLength;
}

char *StringArray::search(char *str) {
    /*
     Поиск по фрагменту
     Возварщает только первый найденый элемент либо ноль
    */
    for (int i = 0; i < this->_logicalLength; i++) {
        if (startsWith(this->_items[i], str) == 0) {
            return this->_items[i];
        }
    }
    return NULL;
}

StringArray *StringArray::concat(StringArray *array) {
    StringArray *result = new StringArray();
    int length = this->_logicalLength;
    if (this->_logicalLength < array->getLength()) {
        length = array->getLength();
    }
    char *str1, *str2;
    for (int i = 0; i < length; i++) {
        str1 = this->atIndex(i);
        if (str1 == NULL) {
            str1 = strdup("");
        }
        str2 = array->atIndex(i);
        if (str2 == NULL) {
            str2 = strdup("");
        }
        char *con = strconcat(str1, str2);
        result->addString(con) ;
    }
    return result;
}

StringArray *StringArray::intersect (StringArray *array) {
    StringArray *result = new StringArray();
    char *found;
    for (int i = 0; i < this->_logicalLength; i++) {
        found = array->search(this->atIndex(i));
        if (found != NULL) {
            result->addString(found);
        }
    }
    return result;
}

StringArray *StringArray::difference(StringArray *array) {
    StringArray *result = new StringArray();
    int *dup = new int[this->_logicalLength + array->getLength()];
    int length = this->_logicalLength;
    if (this->_logicalLength < array->getLength()) {
        length = array->getLength();
    }
    bool found = false;
    int k = 0;
    for (int i = 0; i < this->_logicalLength; i++) {
        found = false;
        for (int j = 0; j < array->getLength(); j++) {
           if (strcompare(this->atIndex(i), array->atIndex(j)) == 0) {
               dup[k++] = j;
               found = true;
               break;
           }
        }
        if (!found) {
            if (result->search(this->atIndex(i)) == NULL) {
                result->addString(this->atIndex(i));
            }
        }
    }
    for (int i = 0; i < array->getLength(); i++) {
        found = false;
        for (int j = 0; j < k; j++) {
            if (i == dup[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            if (result->search(array->atIndex(i)) == NULL) {
                result->addString(array->atIndex(i));
            }
        }
    }
    return result;
}
