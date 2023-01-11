#include "my_sort.h"

using namespace my_lib;

int main (void){
    auto array = random_int_vector(10, 0, 1000);
    std::cout << "Before sort:" << std::endl;
    show_iterator(array);
    insertion_sort(array.begin(), array.end());
    std::cout << "After sort:" << std::endl;
    show_iterator(array);
    return 0;
}
