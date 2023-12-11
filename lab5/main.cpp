#include <iostream>
#include <array>
#include <string>
#include <ostream>
#include <istream>
#include <fstream>

enum class Gender {
    Male,
    Female
};

struct Person {
    std::array<char, 50> name;
    int age;
    Gender gender;
};

void serializeString(const std::array<char, 50>& str, std::ostream& os) {
    os << str.data();
}

void serializeInt(int value, std::ostream& os) {
    os << value;
}

void serializeEnum(Gender gender, std::ostream& os) { //Simplificarea citirii si interpretarii valorii enum la momentul deserializarii
    switch (gender) {
        case Gender::Male:
            os << "M";
            break;
        case Gender::Female:
            os << "F";
            break;
    }
}

void serializePerson(const Person& person, std::ostream& os) {//Separarea fiecarui camp serializat cu un caracter de virgula pentru a putea separa datele ulterior
    serializeString(person.name, os);
    os << ",";
    serializeInt(person.age, os);
    os << ",";
    serializeEnum(person.gender, os);
}

bool deserializeString(std::array<char, 50>& str, std::istream& is) { //Recuperarea a unei secvente de caractere din fluxul de intrare pana la intalnirea a unui delimitator 
    if (is.getline(str.data(), str.size(), ',')) {
        return true;
    } else {
        return false;
    }
}

bool deserializeInt(int& value, std::istream& is) { //Verificarea si gestionarea in cazurile cand conversia la int intampina probleme
    std::string strValue;
    std::getline(is, strValue, ',');

    try {
        value = std::stoi(strValue);
        return true;
    } catch (...) {
        return false;
    }
}

bool deserializeEnum(Gender& gender, std::istream& is) { //Ca mai sus doar ca inloc de int enum
    std::string strValue;
    std::getline(is, strValue, ',');

    if (strValue == "M") {
        gender = Gender::Male;
        return true;
    } else if (strValue == "F") {
        gender = Gender::Female;
        return true;
    } else {
        return false;
    }
}

bool deserializePerson(Person& person, std::istream& is) {//Deserializarea a unui obiect Person -> true, cand toate sunt cu succes
    if (!deserializeString(person.name, is)) return false;
    if (!deserializeInt(person.age, is)) return false;
    if (!deserializeEnum(person.gender, is)) return false;
    return true;
}

bool serializePersonObject(const Person& person, std::ostream& os) {//Separarea a mai multor obiecte serializate
    serializePerson(person, os);
    os << '\n';
    return true;
}

bool deserializePersonObject(Person& person, std::istream& is) {//Verificarea daca sunt corect separate
    if (!deserializePerson(person, is)) return false;
    char c;
    is.get(c);
    if (c != '\n') return false;
    return true;
}

int main() {
    Person person1 = { { 'I', 'o', 'n' ,'\0' }, 18, Gender::Male };
    Person person2 = { { 'A', 'n', 'i', 'u', 't','a', '\0' }, 32, Gender::Female };
    Person person3 = { {'A', 'B', 'O', 'B','U','S', '\0'}, 13, Gender::Female};
    Person person4 = { {'S','A','H','9','k','p','a','c','a','B','4','u','K', '\0'},21, Gender::Male};
    Person person5 = { {'Abobus', '\0'},-21, Gender::Male};

    std::ofstream outFile("persons.csv");
    if (outFile.is_open()) {
        serializePersonObject(person1, outFile);
        serializePersonObject(person2, outFile);
        serializePersonObject(person3, outFile);
        serializePersonObject(person4, outFile);
        serializePersonObject(person5, outFile);
        outFile.close();
    }

    std::ifstream inFile("persons.txt");
    if (inFile.is_open()) {
        Person deserializedPerson1, deserializedPerson2,deserializedPerson3,deserializedPerson4,deserializedPerson5;
        if (deserializePersonObject(deserializedPerson1, inFile)) {
            std::cout << "Deserialized Person 1: Name - " << deserializedPerson1.name.data() << ", Age - " << deserializedPerson1.age << ", Gender - ";
            if (deserializedPerson1.gender == Gender::Male) {
                std::cout << "Male";
            } else {
                std::cout << "Female";
            }
            std::cout << std::endl;
        }
        if (deserializePersonObject(deserializedPerson2, inFile)) {
            std::cout << "Deserialized Person 2: Name - " << deserializedPerson2.name.data() << ", Age - " << deserializedPerson2.age << ", Gender - ";
            if (deserializedPerson2.gender == Gender::Male) {
                std::cout << "Male";
            } else {
                std::cout << "Female";
            }
            std::cout << std::endl;
        }
        inFile.close();
        if (deserializePersonObject(deserializedPerson3, inFile)) {
            std::cout << "Deserialized Person 2: Name - " << deserializedPerson3.name.data() << ", Age - " << deserializedPerson3.age << ", Gender - ";
            if (deserializedPerson3.gender == Gender::Male) {
                std::cout << "Male";
            } else {
                std::cout << "Female";
            }
            std::cout << std::endl;
        }
        if (deserializePersonObject(deserializedPerson4, inFile)) {
            std::cout << "Deserialized Person 2: Name - " << deserializedPerson4.name.data() << ", Age - " << deserializedPerson4.age << ", Gender - ";
            if (deserializedPerson4.gender == Gender::Male) {
                std::cout << "Male";
            } else {
                std::cout << "Female";
            }
            std::cout << std::endl;
        }
        if (deserializePersonObject(deserializedPerson5, inFile)) {
            std::cout << "Deserialized Person 2: Name - " << deserializedPerson5.name.data() << ", Age - " << deserializedPerson5.age << ", Gender - ";
            if (deserializedPerson5.gender == Gender::Male) {
                std::cout << "Male";
            } else {
                std::cout << "Female";
            }
            std::cout << std::endl;
        }
        inFile.close();
    }

    return 0;
}
