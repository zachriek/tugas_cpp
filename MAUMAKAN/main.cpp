#include <iostream>
#include <stdio.h>

using namespace std;

string foods[3] = {
    "1. Soto (Rp18.000)",
    "2. Sate (Rp22.500)",
    "3. Ayam Bakar (Rp20.000)"};

int foods_length = sizeof(foods) / sizeof(string);

string drinks[3] = {
    "4. Jus Mangga (Rp10.000)",
    "5. Es Teh (Rp5.000)",
    "6. Kopi (Rp7.000)"};

int drinks_length = sizeof(drinks) / sizeof(string);

float prices[6] = {
    18000, 22500, 20000, 10000, 5000, 7000};

string costs[3] = {
    "1. Jarak < 5 km (Rp9.500)",
    "2. Jarak 5 sampai 10 km (Rp12.500)",
    "3. Jarak > 10 km (Rp15.000)"};

float cost_prices[3] = {
    9500, 12500, 15000};

int costs_length = sizeof(costs) / sizeof(string);

float total = 0, discount = 0.1, cost = 0, discount_price = 30000;
int distance_option;

char is_run = 'y';

void print_line()
{
  printf("-------------------------------------\n");
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

  cout << "Total Harga: " << format_rupiah(to_string(int(total))) << endl;
  cout << "Total Ongkir: " << format_rupiah(to_string(int(cost))) << endl;
  cout << "Biaya yang Harus Dibayar: " << format_rupiah(to_string(int(total + cost))) << endl;
}

void show_menu()
{
  system("cls");

  printf("Selamat Datang di Resto MAUMAKAN :D\n");
  print_line();

  printf("Menu Makanan\n");
  for (int i = 0; i < foods_length; i++)
  {
    cout << foods[i] << endl;
  }
  print_line();

  printf("Menu Minuman\n");
  for (int i = 0; i < drinks_length; i++)
  {
    cout << drinks[i] << endl;
  }

  print_line();
  printf("7. Keluar \n");
}

void costs_menu()
{
  system("cls");
  for (int i = 0; i < costs_length; i++)
  {
    cout << costs[i] << endl;
  }
  printf("Berapa km jarak dari resto ke rumah? (contoh: 1)\n");
  scanf("%d", &distance_option);
}

void continue_menu()
{
  printf("Apakah kamu ingin memilih makanan/minuman lagi? (y/n)\n");
  scanf(" %c", &is_run);
}

void select_menu()
{
  int option, order_count;

  printf("Silahkan pilih menu yang tersedia! (contoh: 1)\n");
  scanf("%d", &option);

  if (option == 7 || !(option >= 1 && option <= 6))
  {
    return show_result();
  }

  if (option >= 1 && option <= 6)
  {
    system("cls");

    printf("Berapa makanan/minuman yang ingin kamu beli? (contoh: 1)\n");
    scanf("%d", &order_count);

    total += prices[option - 1] * order_count;

    if (cost == 0)
    {
      costs_menu();
    }
    cost = cost_prices[distance_option - 1] * (total >= discount_price ? 1.0 - discount : 1);

    system("cls");

    string my_option = (option >= 1 && option <= 3) ? foods[option - 1] : drinks[option - 3 - 1];
    cout << "Kamu memilih " << my_option << " " << order_count << "x" << endl;
    print_line();
    cout << "Total Harga: " << format_rupiah(to_string(int(total))) << endl;
    print_line();
    cout << "Total Ongkir: " << format_rupiah(to_string(int(cost))) << endl;
    print_line();
    continue_menu();

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
}

int main()
{
  show_menu();
  select_menu();

  return 0;
}