#include "dynamicArray.h"
#include <iostream>
#include <vector>
#include <cassert>

//Crearea functilor de testare 

static void test1() { // Test 1, functia de verificare daca se creaza functie cu capacitate dorita
    DynamicArray arr = createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
}

static void test2() { // Test 2, verificarea de introducere a elementelor si lungimea este actualizata corespunzator dupa adaugare
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    addElementToArray(&arr, 5);
    assert(arr.length == 1);
}

static void test3() { // Test 3 verificarea de introducere a elementelor si verificarea daca capacitatea se dubleaza 
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4);
}

static void test4() { //Test 4, verificarea de introducere a elementului si accesarea lui dupa index
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5); //<- element cu valoarea 5
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5); // el == 5  ? pass : failed
}

static void test5() { // Test 5 returnarea vectorului care contine corect segmentul specificat din bufferul DynamicArray
    DynamicArray arr{};
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    std::vector<int> span = getCurrentSpan(&arr);

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}