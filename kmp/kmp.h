#ifndef _KMP_H
#define _KMP_H
#include <string>

using namespace std;

void getNext(string patten, int next[]);

void getNextval(string patten, int next[], int nextval[]);

void getFinal(int next[], int len);

void kmp(string patten, string text);

#endif
