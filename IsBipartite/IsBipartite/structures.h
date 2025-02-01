/// @file structures.h
/// @brief Plik nag��wkowy zawieraj�cy sdtruktur� grafu.
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>

using namespace std;

/// @brief Struktura reprezentuj�ca graf nieskierowany.
/// 
/// Ta struktura przechowuje liczb� wierzcho�k�w oraz list� s�siedztwa reprezentuj�c� graf.
/// Zawiera r�wnie� funkcje do dodawania kraw�dzi do grafu.
struct Graph {
    int vertices; ///< Liczba wierzcho�k�w w grafie.
    vector<vector<int>> adjacencyList; ///< Lista s�siedztwa wierzcho�k�w grafu.

    /// @brief Konstruktor grafu.
    /// 
    /// Konstruktor tworzy graf o zadanej liczbie wierzcho�k�w.
    /// @param v Liczba wierzcho�k�w.
    Graph(int v) : vertices(v), adjacencyList(v) {}

    /// @brief Dodaje kraw�d� do grafu.
    ///
    /// Funkcja ta dodaje kraw�d� mi�dzy dwoma wierzcho�kami w grafie. 
    /// Poniewa� graf jest nieskierowany, kraw�d� zostaje dodana zar�wno 
    /// do listy s�siedztwa wierzcho�ka u, jak i v.
    /// @param u Pierwszy wierzcho�ek kraw�dzi.
    /// @param v Drugi wierzcho�ek kraw�dzi.
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
};
