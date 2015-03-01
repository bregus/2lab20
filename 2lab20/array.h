//
//  array.h
//  2lab20
//
//  Created by Рома Сумороков on 19.02.15.
//  Copyright (c) 2015 Рома Сумороков. All rights reserved.
//

#ifndef ___lab20__array__
#define ___lab20__array__

#include <stdio.h>

class StringArray {
    char **_items;
    int _logicalLength;      //  Количество заполненных элементов
    int _allocLength;        //  Количество выделленных элементов
    
    void increaseSize();
public:
    
    StringArray();
    ~StringArray();
    
    void addString (char *str);
    char *atIndex (int index);
    char *search (char *str);
    int getLength();
    
    StringArray *concat (StringArray *array);  //поэлементное сцепление
    StringArray *intersect (StringArray *array); //исключ. повторяющихся
    StringArray *difference (StringArray *array); //пересечение
};

#endif /* defined(___lab20__array__) */
