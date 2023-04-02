#include <iostream>
#include <stdio.h>
using namespace std;
struct Data {
    short year;
    short month;
    short day;
};
bool compare(Data a, Data b) {
    if (a.year < b.year) {
        return 1;
    }
    if (a.year == b.year) {
        if (a.month < b.month) {
            return 1;
        }
        else if (a.month == b.month) {
            if (a.day < b.day) {
                return 1;
            }
        }
    }
    return 0;
}
void Quicksort(Data ciag[], int lewy, int prawy)
{
    int i = lewy;
    int j = prawy;
    Data os = ciag[lewy];
    do
    {
        while (compare(ciag[i], os))
            i++;

        while (compare(os, ciag[j]))
            j--;

        if (i <= j)
        {

            swap(ciag[i], ciag[j]);

            i++;
            j--;
        }
    } while (i <= j);

    if (lewy < j) Quicksort(ciag, lewy, j);

    if (prawy > i) Quicksort(ciag, i, prawy);

}



int main()
{
    int n;
    cin >> n;
    Data* ciag = new Data[n];

    char temp = '0';
    for (int i = 0; i < n; i++) {
        cin >> ciag[i].day >> temp >> ciag[i].month >> temp >> ciag[i].year;
    }
    Quicksort(ciag, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout.fill('0');
        cout.width(2);
        cout << ciag[i].day << temp;
        cout.fill('0');
        cout.width(2);
        cout << ciag[i].month << temp;
        cout.width(4);
        cout << ciag[i].year << endl;;
    }
    delete[] ciag;
}