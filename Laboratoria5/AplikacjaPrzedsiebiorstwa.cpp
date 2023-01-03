// AplikacjaPrzedsiebiorstwa.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "Bank.h"
#include "Przedsiebiorstwo.h"

using namespace std;

int main() {
    // Wsparcie polskich znaków w konsoli
    system("chcp 1250");
    system("cls");

    // G³ówny program
    cout << "Aplikacja Przedsiêbiorstwa\n\n";
   
    Bank PKOBP(3.5, 4.5, 3.0, "PKO BP");
    PKOBP.Drukuj();

    return 0;
}