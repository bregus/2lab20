//
//  strings.cpp
//  2lab20
//
//  Created by Рома Сумороков on 28.02.15.
//  Copyright (c) 2015 Рома Сумороков. All rights reserved.
//

#include "strings.h"

char *substring(char *src, int start, int end) {
    int length = strlength(src);
    if ((start > end) || (start > length) || (end > length)) {
        return NULL;
    }
    char *dest = new char[end-start+1];
    for (int i = start; i < end; i++) {
        dest[i] = src[i];
    }
    return dest;
}

int strcompare(char *str1, char *str2) {
    int i;
    for (i = 0; str1[i] == str2[i]; i++) {
        if (str1[i] == '\0')
            return 0;
    }
    return str1[i] - str2[i];
}

int startsWith(char *str, char *begin) {
    /*
       Проверяем является ли стркоа началом другой
       Если является, то возварщаем 0,
       иначе число, отличное от нуля
     */
    if (strlength(begin) > strlength(str)) {
        return -1;
    }
    if (strlength(begin) == strlength(str)) {
        return strcompare(str, begin);
    } else {
        char *string = substring(str, 0, strlength(begin));
        return strcompare(string, begin);
    }
}

int strlength(char *str){
    int n;
    for (n = 0; *str != '\0'; str++) {
        n++;
    }
    return n;
}

void strcopy(char *src, char *dest){
    while ((*dest++ = *src++));
}

char *strconcat(char *src, char *dest) {
    char *result = new char[strlength(src) + strlength(dest) + 1];
    int i;

    for (i = 0; *src != '\0'; i++, src++) {
        result[i] = *src;
    }

    for (; *dest != '\0'; i++, dest++) {
        result[i] = *dest;
    }
    result[++i] = '\0';
    return result;
}