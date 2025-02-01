/// @file main.cpp
/// @brief G³ówna funkcja programu obs³uguj¹ca wczytywanie, sprawdzanie i zapis wyników.
#include "functions.h"

/// @brief Funkcja g³ówna programu.
/// @param argc Liczba argumentów wiersza poleceñ.
/// @param argv Tablica argumentów wiersza poleceñ.
/// @return Kod zakoñczenia programu.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    Graph graph(100); ///< Tworzenie grafu o maksymalnej liczbie 100 wierzcho³ków.
    readGraphFromFile(argv[1], graph); ///< Wczytanie grafu z pliku.

    vector<int> group1, group2; ///< Wektory przechowuj¹ce grupy wierzcho³ków.

    bool result = isBipartite(graph, group1, group2);  ///< Sprawdzenie, czy graf jest dwudzielny.

    writeResultToFile(argv[2], result, group1, group2);  ///< Zapisanie wyniku do pliku.

    return 0;
}
