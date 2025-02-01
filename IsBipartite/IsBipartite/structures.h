/// @file structures.h
/// @brief Plik nag³ówkowy zawieraj¹cy sdtrukturê grafu.
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

/// @brief Struktura reprezentuj¹ca graf nieskierowany.
/// 
/// Ta struktura przechowuje liczbê wierzcho³ków oraz listê s¹siedztwa reprezentuj¹c¹ graf.
/// Zawiera równie¿ funkcje do dodawania krawêdzi do grafu.
struct Graph {
    int vertices; ///< Liczba wierzcho³ków w grafie.
    vector<vector<int>> adjacencyList; ///< Lista s¹siedztwa wierzcho³ków grafu.

    /// @brief Konstruktor grafu.
    /// 
    /// Konstruktor tworzy graf o zadanej liczbie wierzcho³ków.
    /// @param v Liczba wierzcho³ków.
    Graph(int v) : vertices(v), adjacencyList(v) {}

    /// @brief Dodaje krawêdŸ do grafu.
    ///
    /// Funkcja ta dodaje krawêdŸ miêdzy dwoma wierzcho³kami w grafie. 
    /// Poniewa¿ graf jest nieskierowany, krawêdŸ zostaje dodana zarówno 
    /// do listy s¹siedztwa wierzcho³ka u, jak i v.
    /// @param u Pierwszy wierzcho³ek krawêdzi.
    /// @param v Drugi wierzcho³ek krawêdzi.
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
};
