#include <iostream>

using namespace std;

const unsigned long int a = 7939;
const unsigned long int m = 1801088541;
const unsigned long int c = 11;

unsigned long int generator(unsigned long int s)
{
    return (a*s+c)%m;
}

double srednia(double tab[])
{
    double suma_dla_sredniej = 0;
    for(int i = 0; i < 10000; i++)
    {
        suma_dla_sredniej += tab[i];
    }
    return (1.0/10000)*suma_dla_sredniej;
}

double wariancja(double tab[])
{
    double suma_dla_wariancji = 0;
    for(int i = 0; i < 10000; i++)
    {
        suma_dla_wariancji += (tab[i]-srednia(tab))*(tab[i]-srednia(tab));
    }
    return (1.0/10000)*suma_dla_wariancji;
}

int main()
{
    unsigned long int s = 4;
    unsigned long int x, x0;
    double u;

    cout << "x0 = "; cin>>x0; cout << endl;
	x = x0;

    double tab[10000];
    for(int i = 0; i < 10000; i++)
    {
        u = (1.0*x)/m;
        tab[i]=u;
        x = generator(x);
    }

    cout << "Srednia = " << srednia(tab) << endl;
    cout << "Wariancja = " << wariancja(tab) << endl;

    return 0;
}
