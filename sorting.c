/*    sorting.c
    Implementations of primary sorting algorithms

    by: Steven Skiena
    begun: February 5, 2002

*/


/*
Copyright 2003 by Steven S. Skiena; all rights reserved.

Permission is granted for use in non-commerical applications
provided this copyright notice remains intact and unchanged.

This program appears in my book:

"Programming Challenges: The Programming Contest Training Manual"
by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.

See our website www.programming-challenges.com for additional information.

This book can be ordered from Amazon.com at

http://www.amazon.com/exec/obidos/ASIN/0387001638/thealgorithmrepo/

*/

/* #include <math.h> */
/* #include <stdio.h> */
/* #include <stdlib.h> */

#include "bool.h"
#include "priority_queue.h"
#include "queue.h"
/* #include "random.h" */
#include "sorting.h"

bool
compare (item_type a, item_type b)
{
  if (a < b)
    {
      return (LESS_THAN);
    }

  if (a > b)
    {
      return (GREATER_THAN);
    }

  return (EQUAL_TO);
}

/*    Swap the ith and jth elements of array s.    */

void
newswap (item_type s[], int i, int j)
{
  item_type tmp;                /* placeholder */

  tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}

/* [[[ insertion_cut */
void
insertion_sort (item_type s[], int n)
{
  int i, j;                     /* counters */

/* [[[ insertion_inner_cut */
  for (i = 1; i < n; i++)
    {
      j = i;
      while ((j > 0) && (s[j] < s[j - 1]))
        {
          newswap (s, j, j - 1);
          j = j - 1;
        }
    }
/* ]]] */
}

/* ]]] */

/* [[[ selection_cut */
void
selection_sort (item_type s[], int n)
{
  int i, j;                     /* counters */
  int min;                      /* index of minimum */

  for (i = 0; i < n; i++)
    {
      min = i;
      for (j = i + 1; j < n; j++)
        {
          if (s[j] < s[min])
            {
              min = j;
            }
        }
      newswap (s, i, min);
    }
}

/* ]]] */

/* [[[ partition_cut */
int
partition (item_type s[], int l, int h)
{
  int i;                        /* counter */
  int p;                        /* pivot element index */
  int firsthigh;                /* divider position for pivot element */

  p = h;
  firsthigh = l;
  for (i = l; i < h; i++)
    {
      if (s[i] < s[p])
        {
          newswap (s, i, firsthigh);
          firsthigh++;
        }
    }
  newswap (s, p, firsthigh);

  return (firsthigh);
}

/* ]]] */

/*    quicksort array s from the index l to index h.    */
/* [[[ quicksort_cut */
void
quicksort (item_type s[], int l, int h)
{
  int p;                        /* index of partition */

  if ((h - l) > 0)
    {
      p = partition (s, l, h);
      quicksort (s, l, p - 1);
      quicksort (s, p + 1, h);
    }
}

/* ]]] */

/* [[[ heapsort_cut */
void
heapsort (item_type s[], int n)
{
  int i;                        /* counters */
  priority_queue q;             /* heap for heapsort */

  make_heap (&q, s, n);

  for (i = 0; i < n; i++)
    {
      s[i] = extract_min (&q);
    }
}

/* ]]] */

/* [[[ binary_search_cut */
int
binary_search (item_type s[], item_type key, int low, int high)
{
  int middle;                   /* index of middle element */

  if (low > high)
    {
      return (-1);              /* key not found */
    }

  middle = (low + high) / 2;

  if (s[middle] == key)
    {
      return (middle);
    }

  if (s[middle] > key)
    {
      return (binary_search (s, key, low, middle - 1));
    }
  else
    {
      return (binary_search (s, key, middle + 1, high));
    }
}

/* ]]] */

/* [[[ merge_cut */
void
merge (item_type s[], int low, int middle, int high)
{
  int i;                        /* counter */
  queue buffer1, buffer2;       /* buffers to hold elements for merging */

  init_queue (&buffer1);
  init_queue (&buffer2);

  for (i = low; i <= middle; i++)
    {
      enqueue (&buffer1, s[i]);
    }

  for (i = middle + 1; i <= high; i++)
    {
      enqueue (&buffer2, s[i]);
    }

  i = low;
  while (!(empty_queue (&buffer1) || empty_queue (&buffer2)))
    {
      if (headq (&buffer1) <= headq (&buffer2))
        {
          s[i++] = dequeue (&buffer1);
        }
      else
        {
          s[i++] = dequeue (&buffer2);
        }
    }

  while (!empty_queue (&buffer1))
    {
      s[i++] = dequeue (&buffer1);
    }

  while (!empty_queue (&buffer2))
    {
      s[i++] = dequeue (&buffer2);
    }
}

/* ]]] */

/* [[[ mergesort_cut */
void
mergesort (item_type s[], int low, int high)
{
  int middle;                   /* index of middle element */

  if (low < high)
    {
      middle = (low + high) / 2;
      mergesort (s, low, middle);
      mergesort (s, middle + 1, high);

      merge (s, low, middle, high);
    }
}

/* ]]] */
