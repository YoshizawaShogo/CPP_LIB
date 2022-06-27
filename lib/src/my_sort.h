#ifndef MY_SORT_H_
#define MY_SORT_H_

#include <cstdint>
#include <random>
#include <iostream>
#include <iomanip>

namespace my_lib {
    std::vector<int32_t> random_int_vector(uint32_t length, int32_t range_min, int32_t range_max, int32_t random_seed = 0);
    std::vector<double> random_double_vector(uint32_t length, double range_min, double range_max, int32_t random_seed = 0);

    template <typename iterator>
    bool check_sorted(iterator iter_begin, iterator iter_end)
    {
        bool descending_check = true;
        bool ascending_check = true;
        for(iterator it = iter_begin; it != iter_end-1; ++it){
            if(*it < *(it+1)){
                descending_check = false;
                break;
            }
        }
        for(iterator it = iter_begin; it != iter_end-1; ++it){
            if(*it > *(it+1)){
                ascending_check = false;
                break;
            }
        }
        return true;
    }

    template <typename iterator, typename Compare>
    bool check_sorted(iterator iter_begin, iterator iter_end, Compare comp)
    {
        bool descending_check = true;
        bool ascending_check = true;
        for(iterator it = iter_begin; it != iter_end-1; ++it){
            if(comp(*it, *(it+1))) return false;
        }
        return true;
    }

    template <typename iterator>
    void show_iterator(iterator iter, uint32_t limited_col_max = 10, uint8_t num_width = 4)
    {
        uint32_t counter = 0;
        for(auto x: iter){
            std::cout << std::setw(num_width) << x << ", ";
            counter += 1;
            if(limited_col_max && counter == limited_col_max){
                counter = 0;
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }

    template <typename iterator, typename Compare>
    void bubble_sort(iterator iter_begin, iterator iter_end, Compare comp)
    {
        uint32_t iter_length = iter_end - iter_begin;
        for (uint32_t i = 0; i < iter_length; ++i)
        {
            for (uint32_t j = 0; j < iter_length - i - 1; ++j)
            {
                if (comp(iter_begin[j], iter_begin[j+1])) std::swap(iter_begin[j], iter_begin[j+1]);
            }
        }
    }
    template <typename iterator>
    void bubble_sort(iterator iter_begin, iterator iter_end)
    {
        uint32_t iter_length = iter_end - iter_begin;
        for (uint32_t i = 0; i < iter_length; ++i)
        {
            for (uint32_t j = 0; j < iter_length - i - 1; ++j)
            {
                if (iter_begin[j] < iter_begin[j+1]) std::swap(iter_begin[j], iter_begin[j+1]);
            }
        }
    }

    template <typename iterator, typename Compare>
    void select_sort(iterator iter_begin, iterator iter_end, Compare comp)
    {
        uint32_t iter_length = iter_end - iter_begin;
        for (uint32_t i = 0; i < iter_length; ++i)
        {
            uint32_t select_index = 0;
            for (uint32_t j = 1; j < iter_length - i; ++j)
            {
                if (comp(iter_begin[j], iter_begin[select_index])) select_index = j;
            }
            std::swap(iter_begin[select_index], iter_begin[iter_length - i -1]);
        }
    }

    template <typename iterator>
    void select_sort(iterator iter_begin, iterator iter_end)
    {
        uint32_t iter_length = iter_end - iter_begin;
        for (uint32_t i = 0; i < iter_length; ++i)
        {
            uint32_t select_index = 0;
            for (uint32_t j = 1; j < iter_length - i; ++j)
            {
                if (iter_begin[j] < iter_begin[select_index]) select_index = j;
            }
            std::swap(iter_begin[select_index], iter_begin[iter_length - i -1]);
        }
    }

    template <typename iterator>
    void insertion_sort(iterator iter_begin, iterator iter_end)
    {
        // コピペ: https://www.geeksforgeeks.org/insertion-sort/
        uint32_t iter_length = iter_end - iter_begin;
        
        int i;
        int key;
        int j;
        for (i = 1; i < iter_length; i++)
        {
            key = iter_begin[i];
            j = i - 1;
            while (j >= 0 && iter_begin[j] > key)
            {
                iter_begin[j + 1] = iter_begin[j];
                j = j - 1;
            }
            iter_begin[j + 1] = key;
        }
    }
}

#endif
