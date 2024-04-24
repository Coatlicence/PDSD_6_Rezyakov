#pragma once
#include <iostream>
#include <string>
#include <random>
#include "stdlib.h"

using namespace std;

int RandomRange(int min, int max);

struct SetElement
{
	int value;
	SetElement* next;
};

// F1. Создание пустого множества
SetElement* CreateListSet();

// F2. Пустое множество?
bool IsEmpty(SetElement* first);

// F3. Проверка принадлежности элемента множеству. 
bool HasElement(SetElement* first, int element);

// F4. Добавление нового элемента в множество.
SetElement* AddToBegin(SetElement* first, int element);

// F5. Создание множества.
SetElement* CreateListSet(int count, int min, int max);

// F5. Создание множества. Модифицированное
SetElement* CreateListSet(int count, int min, int max, int mult);


// F6. Мощность множества.
int	GetPower(SetElement* first);

// F7. Вывод элементов множества.
string GetAllElements(SetElement* first, string delimitter);

// F8. Удаление множества (очистка памяти, занимаемой списком).
SetElement* Clear(SetElement* first);


///-----------------------------------------------------------------------------------------------
// LABA 2

// F9. Подмножество А-В.
bool IsSubSet(SetElement* A, SetElement* B);

// F10. Равенство двух множеств А-В.
bool IsEqual(SetElement* A, SetElement* B);

// F11. Объединение двух множеств. 
SetElement* Combine(SetElement* A, SetElement* B);

// F12. Пересечение двух множеств.
SetElement* Intersect(SetElement* A, SetElement* B);

// F13. Разность множеств.
SetElement* Difference(SetElement* A, SetElement* B);

// F14. Симметричная разность. 
SetElement* SymmetryDifference(SetElement* A, SetElement* B);