#include <iostream>
#include <vector>
using namespace std;

int exp(int base, int exponent)//funkcja potegujaca
{
    int result{ 1 };
    for (int i{}; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int main()
{
    int number{};

    cout << "Konwersja liczby dziesietnej na binarna (-2147483647 do 2147483647)\nWprowadz liczbe: ";
    cin >> number;
    vector <int> power;//wektor przechowujacy wartosci kolejnych poteg liczby 2
    for (int i{}; i <= 30; i++)
    {
        power.push_back(exp(2, i));
    }
    if (number < 0)//jesli liczba jest dodatnia pierwszy bit to 0 a jesli jest ujemna pierwszy bit to 1
    {
        cout << 1;
        number *= -1;
    }
    else
    {
        cout << 0;
    }
    for (int i{30}; i >= 0; i--)//algorytm zwraca 1 jesli liczba jest wieksza od danej potegi po czym odejmuje od wpisanej liczby ta potege az nie wyswietli 31 liczb (32 z bitem okreslajacym znak)
    {
        if (number < exp(2, i))
        {
            cout << 0;
        }
        else
        {
            cout << 1;
            number = number - exp(2, i);
        }
    }
    cout << endl;
    system("pause");
}