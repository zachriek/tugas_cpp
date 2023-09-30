#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string books[6] = {
    "1. Buku Laut Bercerita | Rp99.000",
    "2. Buku Dunia Shopie | Rp114.000",
    "3. Buku Harry Potter and the Deathly Hallows: Part 1 | Rp200.000",
    "4. Buku No Longer Human | Rp160.000",
    "5. Buku Man's Search for Meaning | Rp300.000",
    "6. Buku Think and Grow Rich | Rp320.000"};

float prices[6] = {
    99000.0,
    114000.0,
    200000.0,
    160000.0,
    300000.0,
    320000.0};

float discounts[3] = {0.93, 0.9, 0.88};

int books_length = sizeof(books) / sizeof(string);

float money = 0, real_total = 0, total = 0;

char is_run = 'y';

void print_line()
{
  printf("----------------------------------\n");
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

void show_result()
{
  system("cls");

  cout << "Total Belanja (tanpa diskon): " << format_rupiah(to_string(int(real_total))) << endl;
  cout << "Total yang Harus Dibayar (dengan diskon): " << format_rupiah(to_string(int(total))) << endl;
  cout << "Kembalian Uang: " << format_rupiah(to_string(int(money))) << endl;
}

void show_menu()
{
  system("cls");

  printf("Selamat Datang di Toko MARIBACA :D\n");
  print_line();
  for (int i = 0; i < books_length; i++)
  {
    cout << books[i] << endl;
  }
  printf("7. Keluar \n");
}

void continue_menu()
{
  printf("Apakah kamu ingin memilih buku lagi? (y/n)\n");
  scanf(" %c", &is_run);
}

void select_menu()
{
  int option, books_count;
  float price;

  printf("Silahkan pilih buku! (contoh: 1)\n");
  scanf("%d", &option);

  if (option == 7 || !(option >= 1 && option <= 6))
  {
    return show_result();
  }

  if (option >= 1 && option <= 6)
  {
    printf("Berapa buku yang ingin kamu beli? (contoh: 1)\n");
    scanf("%d", &books_count);

    if (prices[option - 1] >= 100000 && prices[option - 1] < 150000)
    {
      price = prices[option - 1] * discounts[0];
    }
    else if (prices[option - 1] >= 150000 && prices[option - 1] <= 250000)
    {
      price = prices[option - 1] * discounts[1];
    }
    else if (prices[option - 1] > 250000)
    {
      price = prices[option - 1] * discounts[2];
    }
    else
    {
      price = prices[option - 1];
    }

    total += price * books_count;
    real_total += prices[option - 1] * books_count;

    if (money < price)
    {
      system("cls");

      printf("Maaf Uang Kamu Tidak Cukup :(\n");
      printf("Silahkan pilih kembali buku yang ingin kamu beli...\n");
      print_line();
      select_menu();
    }
    else
    {
      system("cls");

      money -= price * books_count;
      cout << "Kamu memilih " << books[option - 1] << endl;
      print_line();
      cout << "Total Harga: " << format_rupiah(to_string(int(total))) << endl;
      print_line();
      cout << "Sisa uang kamu: " << format_rupiah(to_string(int(money))) << endl;
      print_line();
      continue_menu();
    }
  }

  if (tolower(is_run) == 'y')
  {
    show_menu();
    select_menu();
  }
  else
  {
    show_result();
  }
}

void money_menu()
{
  printf("Masukkan Jumlah Uang: Rp");
  scanf("%f", &money);
  print_line();
}

int main()
{
  printf("Selamat Datang di Toko MARIBACA :D\n");
  print_line();

  money_menu();
  show_menu();
  select_menu();

  return 0;
}
