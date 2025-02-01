/// @file functions.h
/// @brief Plik nag��wkowy zawieraj�cy deklaracje funkcji operuj�cych na grafie.
#pragma once
#include "structures.h"

/// @brief Sprawdza, czy graf jest dwudzielny.
/// 
/// Funkcja wykorzystuje algorytm BFS do sprawdzenia, czy graf jest dwudzielny.
/// @param graph Obiekt grafu.
/// @param group1 Wektor przechowuj�cy jedn� grup� wierzcho�k�w.
/// @param group2 Wektor przechowuj�cy drug� grup� wierzcho�k�w.
/// @return true, je�li graf jest dwudzielny, je�li nie, false.
bool isBipartite(const Graph& graph, vector<int>& group1, vector<int>& group2);

/// @brief Wczytuje graf z pliku wej�ciowego.
/// 
/// Funkcja wczytuje dane grafu z pliku wej�ciowego. Pierwsze dwie liczby w ka�dej 
/// linii pliku reprezentuj� kraw�d� mi�dzy dwoma wierzcho�kami.
/// @param filename Nazwa pliku wej�ciowego.
/// @param graph Obiekt grafu, do kt�rego wczytujemy dane.
void readGraphFromFile(const string& filename, Graph& graph);

/// @brief Zapisuje wynik sprawdzenia grafu do pliku.
/// 
/// Funkcja zapisuje wynik sprawdzenia, czy graf jest dwudzielny, do pliku wyj�ciowego.
/// Dodatkowo zapisuje grupy wierzcho�k�w, je�li graf jest dwudzielny.
/// @param filename Nazwa pliku wyj�ciowego.
/// @param isBipartite Informacja, czy graf jest dwudzielny.
/// @param group1 Wektor z pierwsz� grup� wierzcho�k�w.
/// @param group2 Wektor z drug� grup� wierzcho�k�w.
void writeResultToFile(const string& filename, bool isBipartite, const vector<int>& group1, const vector<int>& group2);
