/// @file main.cpp
/// @brief Program do wczytywania grafu, sprawdzania jego dwudzielno�ci i zapisywania wynik�w.

#include <iostream>
#include <string>
#include <vector>
#include "functions.h"

/// @brief Struktura przechowuj�ca opcje CLI.
struct CLIOptions {
    std::string input_file;
    std::string output_file;
    bool help_requested = false;
};

/// @brief Wy�wietla informacje o u�yciu programu.
/// @param program_name Nazwa wykonywalnego pliku (zwykle argv[0]).
void print_help(const std::string& program_name) {
    std::cout << "Usage: " << program_name << " [OPTIONS]\n"
        << "  -i, --input <FILE>   Input file containing graph.\n"
        << "  -o, --output <FILE>  Output file for result saving.\n"
        << "  -h, --help           Display help window.\n"
        << std::endl;
}

/// @brief Parsuje argumenty wiersza polece�.
/// @param argc Liczba argument�w.
/// @param argv Tablica argument�w.
/// @param options Struktura do przechowywania sparsowanych opcji.
/// @return True, je�li u�ytkownik za��da� pomocy, false w przeciwnym razie.
bool parse_arguments(int argc, char* argv[], CLIOptions& options) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            options.help_requested = true;
            return true;
        }
        else if ((arg == "-i" || arg == "--input") && i + 1 < argc) {
            options.input_file = argv[++i];
        }
        else if ((arg == "-o" || arg == "--output") && i + 1 < argc) {
            options.output_file = argv[++i];
        }
        else {
            std::cerr << "Unknown or incomplete option: " << arg << "\n";
            options.help_requested = true;
            return true;
        }
    }

    return false;
}

/// @brief Funkcja g��wna programu.
/// @param argc Liczba argument�w.
/// @param argv Tablica argument�w.
/// @return Kod zako�czenia programu.
int main(int argc, char* argv[]) {
    CLIOptions options;

    if (parse_arguments(argc, argv, options)) {
        print_help(argv[0]);
        return options.help_requested ? 0 : 1;
    }

    if (options.input_file.empty() || options.output_file.empty()) {
        std::cerr << "Missing required options: -i <input_file> -o <output_file>\n";
        print_help(argv[0]);
        return 1;
    }

    Graph graph(100); ///< Tworzenie grafu o maksymalnej liczbie 100 wierzcho�k�w.
    readGraphFromFile(options.input_file, graph); ///< Wczytanie grafu z pliku.

    std::vector<int> group1, group2; ///< Wektory przechowuj�ce grupy wierzcho�k�w.
    bool result = isBipartite(graph, group1, group2);  ///< Sprawdzenie, czy graf jest dwudzielny.

    writeResultToFile(options.output_file, result, group1, group2);  ///< Zapisanie wyniku do pliku.

    return 0;
}
