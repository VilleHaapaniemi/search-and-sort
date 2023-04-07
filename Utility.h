#pragma once

typedef Key Record;

Error_code sequential_search(const List<Record> &the_list,
                             const Key &target, int &position);