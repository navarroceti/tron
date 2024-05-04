#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread> // Hilos de procesos
#include <fstream> // flujos de archivos
#include <string> // Control de cadenas
#include <iostream> // Flujos entrada y salida
#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Dibujo moto("./assets/images/moto.txt");
    Dibujo bloque("./assets/images/bloque.txt");

    int fotograma = 0;
    while (true)
    {
        this_thread::sleep_for(0.1s);
        fotograma++;
        Element personaje = spinner(21, fotograma) | bold | color(Color::Red) | bgcolor(Color::White);
        Element dibujo = vbox({personaje, moto.GetElement(), bloque.GetElement()});
        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla, dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();
    }
    return EXIT_SUCCESS;
}