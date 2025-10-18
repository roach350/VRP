#pragma once


bool charIsInt(char c);
void initStr(char *str, int len);
int countNonZero(char *str, int len);
void appendStr(char *base, const char *addition, int index);
int countChar(char *str, int key);
void strncmpExclude(char *dest, const char *src, int key, int len);
