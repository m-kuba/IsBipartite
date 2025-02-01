/// @file main.cpp
/// @brief Funkcje wczytywania, sprawdziania i zapisu.
/// 
#include "functions.h"

/// @brief Funkcja g��wna programu.
/// @param argc Liczba argument�w.
/// @param argv Tablica argument�w.
/// @return Kod zako�czenia programu.

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    Graph graph(100); ///< Tworzenie grafu o maksymalnej liczbie 100 wierzcho�k�w.
    readGraphFromFile(argv[1], graph); ///< Wczytanie grafu z pliku.

    vector<int> group1, group2; ///< Wektory przechowuj�ce grupy wierzcho�k�w.

    bool result = isBipartite(graph, group1, group2);  ///< Sprawdzenie, czy graf jest dwudzielny.

    writeResultToFile(argv[2], result, group1, group2);  ///< Zapisanie wyniku do pliku.

    return 0;
}
