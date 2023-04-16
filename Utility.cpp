#include "Key.h"
// #include "Record.h"
#include "List.h"
#include "Ordered_list.h"
#include "Utility.h"

Error_code sequential_search(const List<Record> &the_list,
                             const Key &target, int &position)
/*
Post: If an entry in the_list has key equal to target, then return
      success and the output parameter position locates such an entry
      within the list.
      Otherwise return not_present and position becomes invalid.
*/
{
   int s = the_list.size();
   for (position = 0; position < s; position++)
   {
      Record data;
      the_list.retrieve(position, data);
      if (data == target)
         return success;
   }
   position = -1;
   return not_present;
}

Error_code binary_search(const Ordered_list &the_list,
                         const Key &target, int &position)
/*
Post: If a Record in the_list  has Key equal to target, then position locates
      one such entry and a code of success is returned.
      Otherwise, not_present is returned and position is undefined.
Uses: Methods for classes List and Record.
*/
{
   Record data;
   int bottom = 0, top = the_list.size() - 1;

   while (bottom < top)
   {
      int mid = (bottom + top) / 2;
      the_list.retrieve(mid, data);
      if (data < target)
         bottom = mid + 1;
      else
         top = mid;
   }
   if (top < bottom)
   {
      position = -1;
      return not_present;
   }
   else
   {
      position = bottom;
      the_list.retrieve(bottom, data);
      if (data == target)
         return success;
      else
      {
         position = -1;
         return not_present;
      }
   }
}