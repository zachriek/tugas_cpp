#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

string books[6] = {
    "1. Buku Melangkah (Rp69.750)",
    "2. Buku Laut Bercerita (Rp97.750)",
    "3. Buku Man's Search for Meaning (Rp69.000)",
    "4. Buku Rich Dad's Increase Your Financial IQ (Rp60.000)",
    "5. Buku Berani Tidak Disukai (Rp78.400)",
    "6. Buku Think and Grow Rich (Rp84.000)",
};

float book_prices[6] = {
    69750,
    97750,
    69000,
    60000,
    78400,
    84000,
};

int const books_length = sizeof(books) / sizeof(string);

string atk_list[6] = {
    "1. Stabilo (Rp12.500)",
    "2. Pulpen (Rp3.500)",
    "3. Pensil (Rp4.500)",
    "4. Penghapus (Rp1.500)",
    "5. Correction Tape / Tip X (Rp5.000)",
    "6. Penggaris (Rp18.500)",
};

float atk_prices[6] = {
    12500,
    3500,
    4500,
    1500,
    5000,
    18500,
};

int atk_length = sizeof(atk_list) / sizeof(string);

int book_option, atk_option;
float book_price_total = 0, atk_price_total = 0, price_total = 0;

void print_line()
{
  printf("------------------------------------------\n");
}

string format_rupiah(string value, char thousandSep = '.')
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

void result_menu()
{
  system("cls");

  cout << "Total Harga: " << format_rupiah(to_string(int(price_total))) << endl;
  cout << "Pajak (10%): " << format_rupiah(to_string(int(price_total * 0.1))) << endl;
  cout << "Total Harga yang Harus Dibayar: " << format_rupiah(to_string(int(price_total + (price_total * 0.1)))) << endl;
}

void welcome_menu()
{
  system("cls");

  print_line();
  printf("--- Selamat Datang di Toko Buku Siger ---\n");
  print_line();
}

void atk_menu()
{
  char is_continue = 'n';

  do
  {
    welcome_menu();

    for (int i = 0; i < atk_length; i++)
    {
      cout << atk_list[i] << endl;
    }

    print_line();
    printf("Pilih ATK di atas sesuai dengan nomornya (contoh: 1)\n");
    scanf("%d", &atk_option);

    switch (atk_option)
    {
    case 1 ... books_length:
      atk_price_total += atk_prices[atk_option - 1];
      break;
    default:
      printf("Pilihan ATK tidak valid!\n");
      return atk_menu();
      break;
    }

    system("cls");
    cout << "Kamu memilih: " << atk_list[atk_option - 1] << endl;
    cout << "Total Harga ATK: " << format_rupiah(to_string(int(atk_price_total))) << endl;
    print_line();

    printf("Ingin memilih ATK lagi? (y/n)\n");
    scanf(" %c", &is_continue);
  } while (tolower(is_continue) == 'y');

  price_total = book_price_total + atk_price_total;

  result_menu();
}

void books_menu()
{
  char is_continue = 'n';

  do
  {
    welcome_menu();

    for (int i = 0; i < books_length; i++)
    {
      cout << books[i] << endl;
    }

    print_line();
    printf("Pilih buku di atas sesuai dengan nomornya (contoh: 1)\n");
    scanf("%d", &book_option);

    switch (book_option)
    {
    case 1 ... books_length:
      book_price_total += book_prices[book_option - 1];
      break;
    default:
      printf("Pilihan buku tidak valid!\n");
      return books_menu();
      break;
    }

    system("cls");
    cout << "Kamu memilih: " << books[book_option - 1] << endl;
    cout << "Total Harga Buku: " << format_rupiah(to_string(int(book_price_total))) << endl;
    print_line();

    printf("Ingin memilih buku lagi? (y/n)\n");
    scanf(" %c", &is_continue);
  } while (tolower(is_continue) == 'y');

  atk_menu();
}

int main()
{
  books_menu();
  return 0;
}