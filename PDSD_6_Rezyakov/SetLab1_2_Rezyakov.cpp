#include <iostream>
#include <string>
#include <random>
#include "stdlib.h"
#include "SetLab1_2_Rezyakov.h"

using namespace std;

int RandomRange(int min, int max)
{
	int range = max - min + 1;

	return rand() % range + min;
}

int RandomRange(int min, int max, int mult)
{
	int range = max - min + 1;

	int num = (rand() % range + min);

	num -= num % mult;

	return num;
}


// F1. Создание пустого множества
SetElement* CreateListSet()
{
	return nullptr;
}

// F2. Пустое множество?
bool IsEmpty(SetElement* first)
{
	if (first == nullptr)
		return true;
	else
		return false;
}

// F3. Проверка принадлежности элемента множеству. 
bool HasElement(SetElement* first, int element)
{
	if (IsEmpty(first)) return false;

	SetElement* nextel = first;
	while (nextel)
	{
		if (nextel->value == element) return true;

		nextel = nextel->next;
	}

	return false;
}

// F4. Добавление нового элемента в множество.
SetElement* AddToBegin(SetElement* first, int element)
{
	if (HasElement(first, element)) return first;

	SetElement* el = new SetElement();

	el->value = element;

	el->next = first;

	return el;
}

// F5. Создание множества.
SetElement* CreateListSet(int count, int min, int max)
{
	if (count <= 0)
		throw exception("CreateListSet параметр количества элементов меньше или равен нулю");
	if (max < min)
		throw exception("max < min");
	if ((max - min) < count)
		throw exception("нет свободных чисел для множества ");


	auto set = CreateListSet();
	set = AddToBegin(set, RandomRange(min, max));

	/*
	for (int i = 1; i < count; i = GetPower())
	{
		int randint = RandomRange(min, max);
		while (HasElement(set, randint))
		{
			randint = RandomRange(min, max);
		}

		set = AddToBegin(set, randint);
	}
	*/

	while (GetPower(set) < count)
	{
		set = AddToBegin(set, RandomRange(min, max));
	}

	return set;
}

// F5. Создание множества. Модифицированное
SetElement* CreateListSet(int count, int min, int max, int mult)
{
	if (count <= 0)
		throw exception("CreateListSet параметр количества элементов меньше или равен нулю");
	if (max < min)
		throw exception("max < min");
	if ((max - min) < count)
		throw exception("нет свободных чисел для множества ");


	/*
	set = AddToBegin(set, RandomRange(min, max, mult));

	for (int i = 1; i < count; i++)
	{
		int randint = RandomRange(min, max, mult);
		while (HasElement(set, randint))
		{
			randint = RandomRange(min, max, mult);
		}

		set = AddToBegin(set, randint);
	}
	*/

	auto set = CreateListSet();

	while (GetPower(set) < count)
	{
		set = AddToBegin(set, RandomRange(min, max, mult));
	}

	return set;
}



// F6. Мощность множества.
int	GetPower(SetElement* first)
{
	int power = 0;

	if (IsEmpty(first)) return power;

	auto nextel = first;
	while (nextel)
	{
		power++;
		nextel = nextel->next;
	}

	return power;
}

// F7. Вывод элементов множества.
string GetAllElements(SetElement* first, string delimitter)
{
	string out;
	if (IsEmpty(first)) return out;

	out.append(to_string(first->value));

	auto next = first->next;
	while (next)
	{
		out.append(delimitter);
		out.append(to_string(next->value));

		next = next->next;
	}

	return out;
}

// F8. Удаление множества (очистка памяти, занимаемой списком).
SetElement* Clear(SetElement* first)
{
	if (IsEmpty(first)) return first;

	SetElement* next = first->next;

	delete first;
	first = nullptr;

	while (next)
	{
		auto nextel = next->next;

		delete next;
		next = nextel;
	}

	return first;
}


///---------------------------------------------------------------------------------------------------------------
// LABA 2

// F9. Подмножество А-В.
bool IsSubSet(SetElement* A, SetElement* B)
{
	if (IsEmpty(A)) return true;
	if (IsEmpty(B)) return false;

	if (GetPower(A) > GetPower(B)) return false;

	auto nexta = A;
	while (nexta != nullptr)
	{
		if (!HasElement(B, nexta->value))
			return false;

		nexta = nexta->next;
	}

	return true;
}

// F10. Равенство двух множеств А-В.
bool IsEqual(SetElement* A, SetElement* B)
{
	/*
	if (GetPower(A) != GetPower(B)) return false;
	if (!IsSubSet(A, B)) return false;

	auto nexta = A;
	while (nexta != nullptr)
	{
		if (!HasElement(B, nexta->value))
			return false;

		nexta = nexta->next;
	}

	return true;
	*/

	if (IsSubSet(A, B) && IsSubSet(B, A))
		return true;
	else
		return false;

}
// F11. Объединение двух множеств. 
SetElement* Combine(SetElement* A, SetElement* B)
{
	if (IsEmpty(A)) return B;
	if (IsEmpty(B)) return A;

	auto res = CreateListSet();

	auto nexta = A;
	while (nexta != nullptr)
	{
		res = AddToBegin(res, nexta->value);
		nexta = nexta->next;
	}

	auto nextb = B;
	while (nextb != nullptr)
	{
		res = AddToBegin(res, nextb->value);
		nextb = nextb->next;
	}

	return res;
}
// F12. Пересечение двух множеств.
SetElement* Intersect(SetElement* A, SetElement* B)
{
	if (IsEmpty(A) || IsEmpty(B)) return nullptr;

	auto res = CreateListSet();

	auto nexta = A;
	while (nexta != nullptr)
	{
		if (HasElement(B, nexta->value))
			res = AddToBegin(res, nexta->value);

		nexta = nexta->next;
	}

	return res;
}

// F13. Разность множеств.
SetElement* Difference(SetElement* A, SetElement* B)
{
	if (IsEmpty(A)) return nullptr;
	if (IsEmpty(B)) return A;

	auto res = CreateListSet();

	auto nexta = A;
	while (nexta != nullptr)
	{
		if (!HasElement(B, nexta->value))
			res = AddToBegin(res, nexta->value);

		nexta = nexta->next;
	}

	return res;
}

// F14. Симметричная разность. 
SetElement* SymmetryDifference(SetElement* A, SetElement* B)
{
	return Difference
	(
		Combine(A, B),
		Intersect(A, B)
	);
}
