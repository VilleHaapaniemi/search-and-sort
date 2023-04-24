#include "Key.h"
#include "List.h"
#include "Ordered_list.h"
#include "Utility.h"
#include "Sortable_list.h"


void Sortable_list::insertion_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
      the keys in all the  entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the contiguous List implementation of
      Chapter 6
*/
{
   int first_unsorted;    //  position of first unsorted entry
   int position;          //  searches sorted part of list
   Record current;        //  holds the entry temporarily removed from list

   for (first_unsorted = 1; first_unsorted < this->count; first_unsorted++)
      if (this->entry[first_unsorted] < this->entry[first_unsorted - 1]) {
         position = first_unsorted;
         current = this->entry[first_unsorted];         //  Pull unsorted entry out of the list.
         do {               //  Shift all entries until the proper position is found.
            this->entry[position] = this->entry[position - 1];
            position--;                           //  position is empty.
         } while (position > 0 && this->entry[position - 1] > current);
         this->entry[position] = current;
      }
}