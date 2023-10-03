#include <iostream>

using namespace std;

string foods[3] = {
    "1. Makanan 1 (Rp10.000)",
    "2. Makanan 2 (Rp20.000)",
    "3. Makanan 3 (Rp30.000)",
};

int foods_length = sizeof(foods) / sizeof(string);

float prices[3] = {
    10000, 20000, 30000};

int prices_length = sizeof(prices) / sizeof(int);

int main()
{
  int option;

  cout << "Selamat Datang :D" << endl;

  for (int i = 0; i < foods_length; i++)
  {
    cout << foods[i] << endl;
  }

  cout << "Pilih menu diatas" << endl;
  cin >> option;

  if (option >= 1 && option <= 3)
  {
    cout << foods[option - 1] << endl;
    cout << prices[option - 1] << endl;
  }

  return 0;
}