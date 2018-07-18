cmake_minimum_required(VERSION 3.8)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        add-and-search-word-data-structure-design.cpp
        Best_Time_to_Buy_and_Sell_Stock.cpp
        Binary_tree_level_order.cpp
        combination-sum-iii.cpp
        combinations.cpp
        convert_list_to_bst.cpp
        Find_Largest_Value_in_Each_Tree_Row.cpp
        generate_parentheses.cpp
        gray-code.cpp
        implement-trie-prefix-tree.cpp
        Longest_Increasing_Subsequence.cpp
        longest_substring.cpp
        Minimum_Path_Sum.cpp
        n_queen.cpp
        permutation.cpp
        permutations-ii.cpp
        subsets-ii.cpp
        subsets.cpp
        test.cpp
        "Word Search.cpp"
        word-search-ii.cpp
        Word_Search.cpp)

add_executable(leetcode ${SOURCE_FILES})