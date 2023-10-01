#include <iostream>
#include <string>

using namespace std;

string formatRupiah(string value, char thousandSep = '.')
{
  int len = value.length();
  int dlen = 3;

  while (len > dlen)
  {
    value.insert(len - dlen, 1, thousandSep);
    dlen += 4;
    len += 1;
  }
  return "Rp" + value;
}

int main()
{
  int jumlah_tepung = 20000,
      jumlah_gula = 10000,
      harga_donat = 6000,
      harga_tepung = 200000,
      harga_gula = 120000,
      total_modal, jumlah_donat_1,
      jumlah_donat_2, jumlah_donat,
      total_harga_donat, keuntungan;

  total_modal = harga_tepung + harga_gula;

  jumlah_donat_1 = jumlah_tepung / 500 * 10;
  jumlah_donat_2 = jumlah_gula / 100 * 10;
  jumlah_donat = jumlah_donat_1 > jumlah_donat_2 ? jumlah_donat_2 : jumlah_donat_1;

  total_harga_donat = jumlah_donat * harga_donat;
  keuntungan = total_harga_donat - total_modal;

  cout << "Banyak donat gula yang bisa dibuat oleh bu Dona adalah " << jumlah_donat << " donat" << endl;
  cout << "Keuntungan yang diperoleh bu Dona adalah " << formatRupiah(to_string(keuntungan)) << endl;

  return 0;
}