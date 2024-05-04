#include <ftxui/dom/elements.hpp>
#include <string>
#include <fstream>

using namespace std;
using namespace ftxui;

class Dibujo
{
private:
    ifstream archivo;
    Element contenido;

public:
    Dibujo(string path)
    {
        archivo.open(path);

        Elements elementos;
        string linea;
        while (getline(archivo, linea))
        {
            elementos.emplace_back(text(linea));
        }
        contenido = vbox(elementos);
        archivo.close();
    }
    Element GetElement(){
        return this->contenido;
    }
    ~Dibujo() {}
};