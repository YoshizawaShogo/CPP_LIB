#ifndef MY_SORT_H_
#define MY_SORT_H_

#include <cstdint>
#include <random>
#include <iostream>
#include <iomanip>

namespace my_lib {
    std::vector<int32_t> random_int_vector(uint32_t length, int32_t range_min, int32_t range_max, int32_t random_seed = 0);
    std::vector<double> random_double_vector(uint32_t length, double range_min, double range_max, int32_t random_seed = 0);

    template <typename T>
    void show_iterator(T iter, uint32_t limited_col_max = 10, uint8_t num_width = 4)
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
}

#endif
