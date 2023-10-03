#include <iostream>

using namespace std;

int main()
{
  int pembilang1, penyebut1, pembilang2, penyebut2, pembilang, penyebut;

  cout << "Masukkan Pembilang 1 = ";
  cin >> pembilang1;
  cout << "Masukkan Penyebut 1 = ";
  cin >> penyebut1;

  cout << "Masukkan Pembilang 2 = ";
  cin >> pembilang2;
  cout << "Masukkan Penyebut 2 = ";
  cin >> penyebut2;

  penyebut = penyebut1 * penyebut2;
  pembilang = (penyebut / penyebut1 * pembilang1) + (penyebut / penyebut2 * pembilang2);

  cout << pembilang << "/" << penyebut;

  return 0;
}