//
//  strings.h
//  2lab20
//
//  Created by Рома Сумороков on 28.02.15.
//  Copyright (c) 2015 Рома Сумороков. All rights reserved.
//

#ifndef ___lab20__strings__
#define ___lab20__strings__

#include <stdio.h>

int strlength(char *str);
void strcopy(char *src, char *dest);
int strcompare(char *str1, char *str2);
char *substring(char *src, int start, int end);
int startsWith(char *str, char *begin);
char *strconcat(char *src, char *dest);

#endif /* defined(___lab20__strings__) */
