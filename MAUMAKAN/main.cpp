#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string foods[3] = {
    "1. Soto (Rp18.000)",
    "2. Sate (Rp22.500)",
    "3. Ayam Bakar (Rp20.000)"};

string drinks[3] = {
    "4. Jus Mangga (Rp10.000)",
    "5. Es Teh (Rp5.000)",
    "6. Kopi (Rp7.000)"};

string costs[3] = {
    "1. Jarak < 5 km (Rp9.500)",
    "2. Jarak 5 – 10 km (Rp12.500)",
    "3. Jarak > 10 km (Rp15.000)"};

float discount = 0;

void print_line()
{
  printf("-------------------------------------\n");
}

int main()
{
  printf("Selamat Datang di Resto MAUMAKAN :D");
  print_line();
  return 0;
}