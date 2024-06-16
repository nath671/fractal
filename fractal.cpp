#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class complex
{
private:
    double re;
    double im;

public:
    complex(double, double);
    complex();

    void affiche();
    complex addition_avec(complex);
    complex soustrais_avec(complex);
    complex multipli(complex);
    double norme();

    double get_im() { return im; };
    double get_re() { return re; };
    void set_im(double a) { im = a; };
    void set_re(double a) { re = a; };
};
complex::complex(double RE, double IM)
{
    re = RE;
    im = IM;
}
complex::complex()
{
    re = 0;
    im = 0;
}
void complex::affiche()
{
    cout << re << " + " << im << "i" << endl;
}
complex complex::multipli(complex z2)
{
    complex mult;
    mult.re = re * z2.re - im * z2.im;
    mult.im = re * z2.im + im * z2.re;
    return mult;
}
complex complex::addition_avec(complex z2)
{
    complex add;
    add.re = re + z2.re;
    add.im = im + z2.im;
    return add;
}
complex complex::soustrais_avec(complex z2)
{
    complex add;
    add.re = re - z2.re;
    add.im = im - z2.im;
    return add;
}
double complex::norme()
{
    return sqrt(im * im + re * re);
}

complex suite(complex c)
{
    complex z0(0, 0);
    complex zn;

    zn = c.addition_avec(z0.multipli(z0));
    z0 = zn;

    return zn;
}

int main()
{
    ofstream fichier("fractal.txt");

    double x_min = -2;
    double x_max = 0.6;
    double y_min = -1.3;
    double y_max = 1.3;
    double h = 0.00035;
    int Nx = (x_max - x_min) / h;
    int Ny = (y_max - y_min) / h;

    int div = 0;

    bool appartient = true;

    complex z0(0, 0);
    complex c(x_min, y_min);

    for (int j = 1; j <= Ny; j++) // a modifier
    {
        for (int i = 1; i <= Nx; i++)
        {
            z0.set_im(0);
            z0.set_re(0);
            div = 0;
            // appartient = true;

            for (int n = 0; n < 30; n++)
            {
                div++;
                z0 = c.addition_avec(z0.multipli(z0));

                if (z0.norme() >= 2)
                {
                    // appartient = false;
                    break;
                }
            }
            // if (appartient == true)
            // {
            //     fichier << c.get_re() << "   " << c.get_im() << endl;
            // }
            if (i != 1)
            {
                fichier << c.get_re() << "   " << c.get_im() << "   " << div << endl;
            }

            c.set_re(x_min + i * h);
        }
        fichier << c.get_re() << "   " << c.get_im() << "   " << div << endl;
        fichier << endl;

        c.set_im(y_min + j * h);
    }

    fichier.close();
    return 0;
}