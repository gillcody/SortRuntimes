#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

/********* QUICKSORT FOR STRING FROM PROJECT_PART1 (STUDENT BASED) **********/
void quickSort_str(char arr[][MAX_LEN], int left, int right)
{
  int i, j;
  char *x;
  char temp[10][MAX_LEN];
  i = left;
  j = right;
  x = arr[right];  //pivot

  do {
    while((strcmp(arr[i],x) < 0) && (i < right)) {
       i++;
    }
    while((strcmp(arr[j],x) > 0) && (j > left)) {
        j--;
    }
    if(i <= j) {
      strcpy(*temp, arr[i]);
      strcpy(arr[i], arr[j]);
      strcpy(arr[j], *temp);
      i++;
      j--;
   }
  } while(i <= j);

  if(left < j) {
     quickSort_str(arr, left, j);
  }
  if(i < right) {
     quickSort_str(arr, i, right);
  }
}

