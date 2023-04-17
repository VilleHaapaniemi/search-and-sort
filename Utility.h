#pragma once
#include <string>
#include "Random.h"

Error_code sequential_search (const List<Record> &the_list,
                             const Key &target, int &position);

Error_code binary_search (const Ordered_list &the_list,
                            const Key &target, int &position);

void print_out(const std::string &status, double elapsed_time, int comparisons, int searches);

void search_performance_comparison();

void test_search(int searches, List<Record> &the_list, Ordered_list &binary_list, Random &random);