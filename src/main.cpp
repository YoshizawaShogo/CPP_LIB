#include <vector>
#include <algorithm>

#include "my_sort.h"

using namespace my_lib;

int main() {
    std::vector<int> vec = random_int_vector(10, -100, 100);
    select_sort(vec.begin(), vec.end(), [](int a, int b){return a < b;});
    std::cout << "check_sorted: " << check_sorted(vec.begin(), vec.end()) << std::endl;
    return 0;
}