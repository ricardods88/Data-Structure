#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/* Implements the recursive funtion for binary search.
 * @input	reference to vector
 * @input	left boundary for search
 * @input	right boundary for search
 */
template <typename T>
size_t binsearch (const std::vector<T>& vec, T key, const size_t left, const size_t right) {
	if (left > right) return -1;
	size_t mid = (left+right)/2;
	if (vec[mid] == key) return mid;
	if (key < vec[mid])
		return binsearch (vec, key, left, mid-1);
	return binsearch (vec, key, mid+1, right);
}

template <typename T>
size_t binary_search (const std::vector<T>& vec, T val) {
	return binsearch (vec, val, 0, vec.size ());
}

int main()
{
    std::vector<int> vect = {1,2,4,5,7,9,10,12,15,17,21};

    std::cout << std::fixed << std::setprecision(9) << std::left;
    
    std::cout << binary_search (vect, 4) << std::endl;
    
    return 0;
}

