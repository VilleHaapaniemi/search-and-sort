#pragma once

const int max_list = 100000;

typedef Key Record;

enum Error_code {
	success, fail, utility_range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error, range_error
};

template <class List_entry>
class List {
public:
//  methods of the List ADT
   List();
   int size() const;
   bool full() const;
   bool empty() const;
   void clear();
   void traverse(void (*visit)(List_entry &));
   Error_code retrieve(int position, List_entry &x) const;
   Error_code replace(int position, const List_entry &x);
   Error_code remove(int position, List_entry &x);
   Error_code insert(int position, const List_entry &x);

protected:
//  data members for a contiguous list implementation
   int count;
   List_entry entry[max_list];
};

template <class List_entry>
List<List_entry>::List()
{
    count = 0;
}

template <class List_entry>
int List<List_entry>::size() const
{
    return count;
}

template <class List_entry>
bool List<List_entry>::full() const
{
    return count == max_list;
}

template <class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0;
}

template <class List_entry>
void List<List_entry>::clear()
{
    count = 0;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
{
    for (int i = 0; i < count; i++) {
        (*visit)(entry[i]);
    }
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
    if (position < 0 || position >= count) {
        return utility_range_error;
    } else {
        x = entry[position];
        return success;
    }
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
    if (position < 0 || position >= count) {
        return utility_range_error;
    } else {
        entry[position] = x;
        return success;
    }
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (position < 0 || position >= count) {
        return utility_range_error;
    } else {
        x = entry[position];
        for (int i = position; i < count - 1; i++) {
            entry[i] = entry[i + 1];
        }
        count--;
        return success;
    }
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
    if (position < 0 || position > count || full()) {
        return overflow;
    } else {
        for (int i = count - 1; i >= position; i--) {
            entry[i + 1] = entry[i];
        }
        entry[position] = x;
        count++;
        return success;
    }
}