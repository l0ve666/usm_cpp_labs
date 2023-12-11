#include "dynamicArray.h"
#include <cassert>
#include <algorithm>
#include <vector>

///Crearea factory-functiei care returneaza un array cu lungimea maxima initiala
DynamicArray createDynamicArrayWithCapacity(int capacity) {
    DynamicArray arr;
    arr.buffer = new int[capacity];
    arr.capacity = capacity;
    arr.length = 0;
    return arr;
}

DynamicArray createDynamicArray() {
    return createDynamicArrayWithCapacity(4); // Capacitatea implicita 4
}

void addElementToArray(DynamicArray *arr, int element) { //Functia data adauga elemente in buffer si mentine elementele arr->length, si gestioneaza numarul actual de elemente sau cap. Dyn.Arr.
    if (arr->length >= arr->capacity) {
        int newCapacity = arr->capacity * 2;
        int *newBuffer = new int[newCapacity];
        std::copy(arr->buffer, arr->buffer + arr->length, newBuffer);
        delete[] arr->buffer;
        arr->buffer = newBuffer;
        arr->capacity = newCapacity;
    }
    arr->buffer[arr->length++] = element;
}

int getElementAtIndex(const DynamicArray *arr, int index) { // Verificarea validitatii indexului si returnarea elementului specificat in buferul D.A.
    assert(index >= 0 && index < arr->length);
    return arr->buffer[index];
    return -1;
}

std::vector<int> getCurrentSpan(DynamicArray *arr) { //Functia care poate extrage un segment specific din bufferul D.A., mai poate fi folosita pentru a obtine o copie a unui segment
  std::vector<int> span(arr->buffer, arr->buffer + arr->length);
    return span;
}

void clearDynamicArray(DynamicArray *arr) { ///Functia care curata memoria de elementele asociate
    delete[] arr->buffer;
    arr->buffer = nullptr;
    arr->capacity = 0;
    arr->length = 0;
}