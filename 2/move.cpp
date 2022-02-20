/*
 * Reverse_String.cpp
 *
 *  Created on: May 22, 2012
 *      Author: Rachel
 */
 
#include"stdio.h"
#include"string.h"
 
void Reverse(char* str, int s, int e)
{
 char tmp;
 while (s < e)
 {
  tmp = str[s];
  str[s] = str[e];
  str[e] = tmp;
  s++;
  e--;
 }
}
 
void RightReverse(char* str, int k, int n)
{
 if (k > 0 && n > 0)//avoid exception
 {
  Reverse(str, 0, k - 1);
  Reverse(str, k, n - 1);
  Reverse(str, 0, n - 1);
  printf("%s\n", str);
 }
}
 
int main()
{
 char str[25];
 int k, n;
 while (scanf("%s%d", str, &k) != EOF)
 {
  n = strlen(str);
  if (k > n)
   k %= n;
  RightReverse(str, k, n);
 }
}