#include <iostream>
#include "Key.h"
// #include "Record.h"
#include "List.h"
#include "Ordered_list.h"
//#include "Random.h"
#include "Utility.h"
#include "Timer.h"

using std::cout, std::cin, std::endl, std::string;

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

void print_out(const std::string &status, double elapsed_time, int comparisons, int searches)
{
   cout << "Status: " << status << endl;
   cout << "Elapsed per search (ms): " << elapsed_time << endl;
   cout << "Comparisons per search: " << comparisons << endl;
   cout << "Searches: " << searches << endl;
}

void search_performance_comparison()
{
   cout << "\nData inserted to lists and target to find are random generated.\n";
   cout << "List sizes are 10 000\n";
   // Initialize new sequential and binary lists. Ordered list inherits from List and insert numbers on order.
   List<Record> sequential_list;
   Ordered_list binary_list;

   // Insert same random numbers on lists.
   Random random(0);
   int list_size = 10000;
   for (int i = 0 ; i < list_size ; i++)
   {
      int random_num = random.random_integer(1, list_size);
      sequential_list.insert(i, random_num);
      binary_list.insert(random_num);
   }

   test_search(10, sequential_list, binary_list, random);
}

void test_search(int searches, List<Record> &the_list, Ordered_list &binary_list, Random &random)
   /*

Pre:  None.
Post: The number of key comparisons and CPU time for a
      sequential searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
      together with an output function print_out
*/
{
   int list_size = the_list.size();
   if (searches <= 0 || list_size < 0) {
      cout << " Exiting test: " << endl
           << " The number of searches must be positive." << endl
           << " The number of list entries must exceed 0." << endl;
      return;
   }
   int i, found_at;
   int num_not_find = list_size + 1;
   Key::comparisons = 0;
   //Random number(0);
   Timer clock;
   int target_found[searches];
   int target_not_found[searches];

   // Generate random numbers to array so target numbers are same for both searches.
   int num;
   for (int i = 0 ; i < searches ; i++)
   {
      // Random number must be found from list.
      while(true)
      {
         num = random.random_integer(1, list_size * 2);
         if (binary_search(binary_list, num, found_at) == success)
            break;
      }
      target_found[i] = num;
   }

   for (int i = 0 ; i < searches ; i++)
   {
      // Random number must be found from list.
      while(true)
      {
         num = random.random_integer(1, list_size * 2);
         if (binary_search(binary_list, num, found_at) == not_present)
            break;
      }
      target_not_found[i] = num;
   }

   // Sequential performance searches.
   Key::comparisons = 0;
   clock.reset();
   cout << "\nSequential search\n";
   cout << "****************************\n";
   for (i = 0; i < searches; i++) {
      if (sequential_search(the_list, target_found[i], found_at) == not_present)
         cout << "Error: Failed to find expected target " << target_found[i] << endl;
   }
   print_out("Successful", clock.elapsed_time(), Key::comparisons, searches);
   cout << endl;

   Key::comparisons = 0;
   clock.reset();
   for (i = 0; i < searches; i++) {
      if (sequential_search(the_list, target_not_found[i], found_at) == success)
         cout << "Error: Found unexpected target " << target_not_found[i]
              << " at " << found_at << endl;
   }
   print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches);
   cout << endl;

   // Binary performance searches.
   cout << "Binary search\n";
   cout << "****************************\n";
   Key::comparisons = 0;
   clock.reset();
   for (i = 0; i < searches; i++) {
      if (binary_search(binary_list, target_found[i], found_at) == not_present)
         cout << "Error: Failed to find expected target " << target_found[i] << endl;
   }
   print_out("Successful", clock.elapsed_time(), Key::comparisons, searches);
   cout << endl;

   Key::comparisons = 0;
   clock.reset();
   for (i = 0; i < searches; i++) {
      if (binary_search(binary_list, target_not_found[i], found_at) == success)
         cout << "Error: Found unexpected target " << target_not_found[i]
              << " at " << found_at << endl;
   }
   print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches);
   cout << endl;
}