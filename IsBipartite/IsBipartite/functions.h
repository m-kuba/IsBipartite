/// @file functions.h
/// @brief Plik nag³ówkowy zawieraj¹cy deklaracje funkcji operuj¹cych na grafie.
#pragma once
#include "structures.h"

/// @brief Sprawdza, czy graf jest dwudzielny.
/// 
/// Funkcja wykorzystuje algorytm BFS do sprawdzenia, czy graf jest dwudzielny.
/// @param graph Obiekt grafu.
/// @param group1 Wektor przechowuj¹cy jedn¹ grupê wierzcho³ków.
/// @param group2 Wektor przechowuj¹cy drug¹ grupê wierzcho³ków.
/// @return true, jeœli graf jest dwudzielny, jeœli nie, false.
bool isBipartite(const Graph& graph, vector<int>& group1, vector<int>& group2);

/// @brief Wczytuje graf z pliku wejœciowego.
/// 
/// Funkcja wczytuje dane grafu z pliku wejœciowego. Pierwsze dwie liczby w ka¿dej 
/// linii pliku reprezentuj¹ krawêdŸ miêdzy dwoma wierzcho³kami.
/// @param filename Nazwa pliku wejœciowego.
/// @param graph Obiekt grafu, do którego wczytujemy dane.
void readGraphFromFile(const string& filename, Graph& graph);

/// @brief Zapisuje wynik sprawdzenia grafu do pliku.
/// 
/// Funkcja zapisuje wynik sprawdzenia, czy graf jest dwudzielny, do pliku wyjœciowego.
/// Dodatkowo zapisuje grupy wierzcho³ków, jeœli graf jest dwudzielny.
/// @param filename Nazwa pliku wyjœciowego.
/// @param isBipartite Informacja, czy graf jest dwudzielny.
/// @param group1 Wektor z pierwsz¹ grup¹ wierzcho³ków.
/// @param group2 Wektor z drug¹ grup¹ wierzcho³ków.
void writeResultToFile(const string& filename, bool isBipartite, const vector<int>& group1, const vector<int>& group2);
