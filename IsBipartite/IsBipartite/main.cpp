/// @file main.cpp
/// @brief Funkcje wczytywania, sprawdziania i zapisu.
/// 
#include "functions.h"

/// @brief Funkcja główna programu.
/// @param argc Liczba argumentów.
/// @param argv Tablica argumentów.
/// @return Kod zakończenia programu.

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    Graph graph(100); ///< Tworzenie grafu o maksymalnej liczbie 100 wierzchołków.
    readGraphFromFile(argv[1], graph); ///< Wczytanie grafu z pliku.

    vector<int> group1, group2; ///< Wektory przechowujące grupy wierzchołków.

    bool result = isBipartite(graph, group1, group2);  ///< Sprawdzenie, czy graf jest dwudzielny.

    writeResultToFile(argv[2], result, group1, group2);  ///< Zapisanie wyniku do pliku.

    return 0;
}
