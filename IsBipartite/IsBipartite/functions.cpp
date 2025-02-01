/// @file functions.cpp
/// @brief Plik implementuj¹cy funkcje operuj¹ce na grafie.
#include "functions.h"

/// @brief Sprawdza, czy graf jest dwudzielny za pomoc¹ BFS.
/// 
/// Funkcja wykorzystuje algorytm BFS do sprawdzenia, czy graf jest dwudzielny. 
/// W przypadku, gdy graf jest dwudzielny, wierzcho³ki zostaj¹ podzielone na 
/// dwie grupy. W przeciwnym przypadku funkcja zwraca false.
/// @param graph Obiekt grafu.
/// @param group1 Wektor przechowuj¹cy jedn¹ grupê wierzcho³ków.
/// @param group2 Wektor przechowuj¹cy drug¹ grupê wierzcho³ków.
/// @return true, jeœli graf jest dwudzielny, w przeciwnym razie false.
bool isBipartite(const Graph& graph, vector<int>& group1, vector<int>& group2) {
    vector<int> colors(graph.vertices, -1);  // Kolory wierzcho³ków: -1 = niezbadany, 0 = grupa 1, 1 = grupa 2
    queue<int> q;

    // Sprawdzamy ka¿dy wierzcho³ek (jeœli jest odizolowany, te¿ sprawdzamy)
    for (int i = 0; i < graph.vertices; ++i) {
        if (colors[i] == -1) {  // Niezbadany wierzcho³ek
            colors[i] = 0;  // Przypisanie koloru (grupa 0)
            q.push(i);

            // BFS
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : graph.adjacencyList[node]) {
                    if (colors[neighbor] == -1) {  // Jeœli s¹siad nie ma przypisanego koloru
                        colors[neighbor] = 1 - colors[node];  // Przypisanie przeciwnego koloru
                        q.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[node]) {  // Jeœli s¹siad ma ten sam kolor
                        return false;  // Graf nie jest dwudzielny
                    }
                }
            }
        }
    }

    // Przypisanie wierzcho³ków do odpowiednich grup
    for (int i = 0; i < graph.vertices; ++i) {
        if (colors[i] == 0) group1.push_back(i);
        else if (colors[i] == 1) group2.push_back(i);
    }
    return true;
}

/// @brief Odczytuje dane z pliku i tworzy graf.
/// 
/// Funkcja wczytuje dane z pliku wejœciowego. Pierwsze dwie liczby w ka¿dej linii 
/// reprezentuj¹ krawêdŸ miêdzy dwoma wierzcho³kami. Przed dodaniem krawêdzi, 
/// funkcja oblicza liczbê wierzcho³ków na podstawie maksymalnego numeru wierzcho³ka.
/// @param filename Nazwa pliku wejœciowego.
/// @param graph Obiekt grafu, do którego wczytujemy dane.
void readGraphFromFile(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    string line;
    int maxVertex = 0;

    // Pierwszy przebieg: znalezienie maksymalnego numeru wierzcho³ka
    while (getline(file, line)) {
        istringstream iss(line);
        int u, v;
        if (iss >> u >> v) {
            maxVertex = max(maxVertex, max(u, v));  // Maksymalny numer wierzcho³ka
        }
    }

    // Ustawienie liczby wierzcho³ków na podstawie maksymalnego numeru wierzcho³ka + 1
    graph.vertices = maxVertex + 1;
    graph.adjacencyList.resize(graph.vertices);  // Zmieniamy rozmiar listy s¹siedztwa

    // Drugi przebieg: dodanie krawêdzi do grafu
    file.clear();
    file.seekg(0);  // Resetujemy wskaŸnik do pocz¹tku pliku

    while (getline(file, line)) {
        istringstream iss(line);
        int u, v;
        if (iss >> u >> v) {
            graph.addEdge(u, v);  // Dodanie krawêdzi
        }
    }
}

/// @brief Zapisuje wynik sprawdzenia grafu do pliku.
/// 
/// Funkcja zapisuje wynik sprawdzenia, czy graf jest dwudzielny. Je¿eli graf jest 
/// dwudzielny, zapisuje równie¿ grupy wierzcho³ków. Jeœli nie jest, zapisuje stosowny komunikat.
/// @param filename Nazwa pliku wyjœciowego.
/// @param isBipartite Informacja, czy graf jest dwudzielny.
/// @param group1 Wektor z pierwsz¹ grup¹ wierzcho³ków.
/// @param group2 Wektor z drug¹ grup¹ wierzcho³ków.
void writeResultToFile(const string& filename, bool isBipartite, const vector<int>& group1, const vector<int>& group2) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    file << (isBipartite ? "Graph is bipartite\n" : "Graph is not bipartite\n");
    if (isBipartite) {
        file << "Group 1: ";
        for (int node : group1) file << node << " ";
        file << "\nGroup 2: ";
        for (int node : group2) file << node << " ";
        file << "\n";
    }
}
