/// @file functions.cpp
/// @brief Plik implementuj�cy funkcje operuj�ce na grafie.
#include "functions.h"

/// @brief Sprawdza, czy graf jest dwudzielny za pomoc� BFS.
/// 
/// Funkcja wykorzystuje algorytm BFS do sprawdzenia, czy graf jest dwudzielny. 
/// W przypadku, gdy graf jest dwudzielny, wierzcho�ki zostaj� podzielone na 
/// dwie grupy. W przeciwnym przypadku funkcja zwraca false.
/// @param graph Obiekt grafu.
/// @param group1 Wektor przechowuj�cy jedn� grup� wierzcho�k�w.
/// @param group2 Wektor przechowuj�cy drug� grup� wierzcho�k�w.
/// @return true, je�li graf jest dwudzielny, w przeciwnym razie false.
bool isBipartite(const Graph& graph, vector<int>& group1, vector<int>& group2) {
    vector<int> colors(graph.vertices, -1);  // Kolory wierzcho�k�w: -1 = niezbadany, 0 = grupa 1, 1 = grupa 2
    queue<int> q;

    // Sprawdzamy ka�dy wierzcho�ek (je�li jest odizolowany, te� sprawdzamy)
    for (int i = 0; i < graph.vertices; ++i) {
        if (colors[i] == -1) {  // Niezbadany wierzcho�ek
            colors[i] = 0;  // Przypisanie koloru (grupa 0)
            q.push(i);

            // BFS
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : graph.adjacencyList[node]) {
                    if (colors[neighbor] == -1) {  // Je�li s�siad nie ma przypisanego koloru
                        colors[neighbor] = 1 - colors[node];  // Przypisanie przeciwnego koloru
                        q.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[node]) {  // Je�li s�siad ma ten sam kolor
                        return false;  // Graf nie jest dwudzielny
                    }
                }
            }
        }
    }

    // Przypisanie wierzcho�k�w do odpowiednich grup
    for (int i = 0; i < graph.vertices; ++i) {
        if (colors[i] == 0) group1.push_back(i);
        else if (colors[i] == 1) group2.push_back(i);
    }
    return true;
}

/// @brief Odczytuje dane z pliku i tworzy graf.
/// 
/// Funkcja wczytuje dane z pliku wej�ciowego. Pierwsze dwie liczby w ka�dej linii 
/// reprezentuj� kraw�d� mi�dzy dwoma wierzcho�kami. Przed dodaniem kraw�dzi, 
/// funkcja oblicza liczb� wierzcho�k�w na podstawie maksymalnego numeru wierzcho�ka.
/// @param filename Nazwa pliku wej�ciowego.
/// @param graph Obiekt grafu, do kt�rego wczytujemy dane.
void readGraphFromFile(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    string line;
    int maxVertex = 0;

    // Pierwszy przebieg: znalezienie maksymalnego numeru wierzcho�ka
    while (getline(file, line)) {
        istringstream iss(line);
        int u, v;
        if (iss >> u >> v) {
            maxVertex = max(maxVertex, max(u, v));  // Maksymalny numer wierzcho�ka
        }
    }

    // Ustawienie liczby wierzcho�k�w na podstawie maksymalnego numeru wierzcho�ka + 1
    graph.vertices = maxVertex + 1;
    graph.adjacencyList.resize(graph.vertices);  // Zmieniamy rozmiar listy s�siedztwa

    // Drugi przebieg: dodanie kraw�dzi do grafu
    file.clear();
    file.seekg(0);  // Resetujemy wska�nik do pocz�tku pliku

    while (getline(file, line)) {
        istringstream iss(line);
        int u, v;
        if (iss >> u >> v) {
            graph.addEdge(u, v);  // Dodanie kraw�dzi
        }
    }
}

/// @brief Zapisuje wynik sprawdzenia grafu do pliku.
/// 
/// Funkcja zapisuje wynik sprawdzenia, czy graf jest dwudzielny. Je�eli graf jest 
/// dwudzielny, zapisuje r�wnie� grupy wierzcho�k�w. Je�li nie jest, zapisuje stosowny komunikat.
/// @param filename Nazwa pliku wyj�ciowego.
/// @param isBipartite Informacja, czy graf jest dwudzielny.
/// @param group1 Wektor z pierwsz� grup� wierzcho�k�w.
/// @param group2 Wektor z drug� grup� wierzcho�k�w.
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
