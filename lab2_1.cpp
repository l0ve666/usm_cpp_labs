#include <iostream>

int main() {
    int i = 69;
    int number = 72;
    i = 69 + 72;
  
    // Definirea unui grup de variabile (array) de 3 elemente inițializate la 0
    int arr[3] = {0};
    //Crearea pointerului pe i (iPointer)
    int* iPointer = &i;
    //Citirea datelor la adresă din pointer în variabila number
    number = *iPointer;
    //Inscrierea in i prin pointer a valorii 15
    *iPointer = 15;
    //Schimbarea adresei in iPointer la primul element din array
    iPointer = &arr[0];
    //Ne mutam in al 3 element din array, folosind pointer aritmetic
    iPointer += 2;
    //Inscrierea in primul element al array-ului a numarului 5
    arr[0] = 5;
    //Inscrierea in al 3 element al array-ului prin iPointer a numarului 6
    *iPointer = 6;
    //Afișează valorile pe ecran
    std::cout << "i = " << i << std::endl;
    std::cout << "number = " << number << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "arr[2] = " << arr[2] << std::endl;

    return 0;
}
