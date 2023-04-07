#include<iostream>
#include "Key.h"
//#include "Record.h"
#include "List.h"
#include "Utility.h"

int main() {

    List<Record> list; // typedef Key Record for test purposes
    list.insert(0, 1); // Inserting Records as Keys in list. Key constructor set Key corresponds to the int (1).
    list.insert(0, 2);

    Error_code err;
    int position;
    err = sequential_search(list, 0, position);
    int count = Key::comparisons;



    return 0;
}