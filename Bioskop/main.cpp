#include <iostream>
#include <stdio.h>

using namespace std;

string films[6] = {
    "1. Kung Fu Panda",
    "2. Finding Nemo",
    "3. The Amazing Spiderman",
    "4. Harry Potter",
    "5. Zombie Strippers",
    "6. Antichrist",
};

int prices[6] = {
    25000, 30000, 50000, 60000, 100000, 120000};

int films_length = sizeof(films) / sizeof(string);
int age, option, ticket_count, price;

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

  printf("Usia kamu: %d tahun\n", age);
  cout << "Pilihan Judul Film: " << films[option - 1] << endl;
  printf("Jumlah tiket yang dipesan: %d tiket\n", ticket_count);
  cout << "Total Harga: " << format_rupiah(to_string(price)) << endl;
}

void print_hello()
{
  printf("Selamat Datang di Bioskop XXII\n");
  print_line();
}

void age_menu()
{
  printf("Masukkan usia kamu\n");
  scanf("%d", &age);
}

void show_menu()
{
  switch (age)
  {
  case 1 ... 12:
    printf("Pilihan Film untuk usia 0-12 tahun = anak-anak\n");
    print_line();
    for (int i = 0; i < 2; i++)
    {
      cout << films[i] << endl;
    }
    break;

  case 13 ... 16:
    printf("Pilihan Film untuk usia 13-16 tahun = remaja\n");
    print_line();
    for (int i = 0; i < 4; i++)
    {
      cout << films[i] << endl;
    }
    break;

  case 17 ... 150:
    printf("Pilihan Film untuk usia 17 tahun atau lebih = dewasa\n");
    print_line();
    for (int i = 0; i < films_length; i++)
    {
      cout << films[i] << endl;
    }
    break;

  default:
    printf("Usia tidak valid!");
  }
}

void ticket_menu()
{
  printf("Berapa tiket yang ingin kamu beli? (contoh: 1)\n");
  scanf("%d", &ticket_count);
  price = prices[option - 1] * ticket_count;
}

void select_menu()
{
  system("cls");

  show_menu();

  print_line();
  printf("Pilih film yang ada di atas (contoh: 1)\n");
  scanf("%d", &option);

  switch (option)
  {
  case 1 ... 6:
    system("cls");

    cout << "Kamu memilih Film " << films[option - 1] << endl;
    cout << "Harga 1 Tiket Film " << format_rupiah(to_string(prices[option - 1])) << endl;
    print_line();

    ticket_menu();
    show_result();
    break;
  default:
    printf("Pilihan Film tidak valid!");
    break;
  }
}

int main()
{
  system("cls");

  print_hello();
  age_menu();
  select_menu();

  return 0;
}