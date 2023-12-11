#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <vector>

struct DynamicArray {
    int *buffer;
    int capacity;
    int length;
};
//Declararea functiilor 
DynamicArray createDynamicArrayWithCapacity(int capacity);
DynamicArray createDynamicArray();
void addElementToArray(DynamicArray *arr, int element);
int getElementAtIndex(const DynamicArray *arr, int index);
std::vector<int> getCurrentSpan(DynamicArray *arr);
void clearDynamicArray(DynamicArray *arr);

#endif // DYNAMICARRAY_H