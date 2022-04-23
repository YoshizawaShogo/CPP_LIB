#include "my_sort.h"

namespace my_lib {
    std::vector<int32_t> random_int_vector(uint32_t length, int32_t range_min, int32_t range_max, int32_t random_seed)
    {
        std::vector<int32_t> vec;
        std::mt19937 rand_src(random_seed);
        for(uint32_t i=0; i<length; ++i){
            std::uniform_int_distribution<int32_t> rand_dist(range_min, range_max);
            vec.push_back(rand_dist(rand_src));
        }
        return vec;
    }
    
    std::vector<double> random_double_vector(uint32_t length, double range_min, double range_max, int32_t random_seed)
    {
        std::vector<double> vec;
        std::mt19937 rand_src(random_seed);
        for(uint32_t i=0; i<length; ++i){
            std::uniform_real_distribution<double> rand_dist(range_min, range_max);
            vec.push_back(rand_dist(rand_src));
        }
        return vec;
    }
}