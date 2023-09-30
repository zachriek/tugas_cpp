#include <iostream>
#include <cmath>

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
  int panjang_tanah = 15;
  int lebar_tanah = 20;
  int luas_tanah;
  int tinggi_trapesium = 10;
  float diameter_lingkaran = 3;
  float jari_jari_lingkaran = diameter_lingkaran / 2;
  int alas_bawah_trapesium = 15;
  int alas_atas_trapesium = alas_bawah_trapesium - diameter_lingkaran;
  float luas_trapesium;
  float luas_lingkaran;
  float luas_rumput;
  int upah_per_meter = 5000;
  int total_upah;

  luas_tanah = panjang_tanah * lebar_tanah;
  luas_trapesium = ((alas_atas_trapesium + alas_bawah_trapesium) * tinggi_trapesium) / 2;
  luas_lingkaran = 3.14 * jari_jari_lingkaran * jari_jari_lingkaran;
  luas_rumput = luas_tanah - luas_trapesium - luas_lingkaran;
  total_upah = round(luas_rumput) * upah_per_meter;

  cout << "Jadi upah yang akan diterima pak Mustofa setelah memotong semua rumput di halaman rumah pak Ali adalah " << formatRupiah(to_string(total_upah));

  return 0;
}