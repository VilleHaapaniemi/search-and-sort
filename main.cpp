#include <iostream>
#include "Key.h"
// #include "Record.h"
#include "List.h"
#include "Utility.h"

using std::cout, std::cin, std::endl;

// typedef Key Record for test purposes. Inserting Records as Keys in list.

void sequential_program()
// Function creates a list of odd numbers and performs a sequential search to find a given key.
{
    List<Record> list;
    int list_size, position, insert_num = 1;
    cout << "Enter data size added to list: ";
    cin >> list_size;

    // Fill the list with odd numbers, starting from 1.
    for (position = 0; position < list_size; position++)
    {
        list.insert(position, insert_num);
        insert_num = insert_num + 2;
    }

    Error_code result;
    int key;
    position = 0;
    cout << "Enter key (integer) to be searched from list: ";
    cin >> key;
    result = sequential_search(list, key, position);
    if (result == success)
    {
        cout << "Key found from list at location " << position << endl;
    }
    else if (result == not_present)
    {
        cout << "Key not found from list." << endl;
    }
}

int main()
{
    /*
        List<Record> list; // typedef Key Record for test purposes
        list.insert(0, 1); // Inserting Records as Keys in list. Key constructor set Key corresponds to the int (1).
        list.insert(0, 2);

        Error_code err;
        int position;
        err = sequential_search(list, 0, position);
        int count = Key::comparisons;
    */
    int choice;
    while (choice != 6)
    {
        cout << "**********************************************\n";
        cout << "1. Sequential search\n";
        cout << "6. Quit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sequential_program();
            break;
        }
    }

    return 0;
}