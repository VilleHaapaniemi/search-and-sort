#pragma once

//typedef Key Record;

Error_code sequential_search (const List<Record> &the_list,
                             const Key &target, int &position);

Error_code binary_search (const Ordered_list &the_list,
                            const Key &target, int &position);