#include "SetLab4_Rezyakov.h"
#include <random>
#include <exception>

using std::exception;
using std::to_string;

namespace SetOnList
{

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
	Set::Set()
	{
		first = new list<int>;
	}

	// F2. Пустое множество?
	bool Set::IsEmpty()
	{
		return first->empty();
	}

	// F3. Проверка принадлежности элемента множеству. 
	bool Set::HasElement(int element)
	{
		if (IsEmpty()) return false;

		for (list<int>::iterator it = first->begin(); it != first->end(); ++it)
		{
			if (*it == element) return true;
		}

		return false;
	}

	// F4. Добавление нового элемента в множество.
	bool Set::AddToBegin(int element)
	{
		if (HasElement(element)) return false;

		first->push_front(element);

		return true;
	}

	// F5. Создание множества.
	Set* CreateListSet(int count, int min, int max)
	{
		if (count <= 0)
			throw exception("CreateListSet параметр количества элементов меньше или равен нулю");
		if (max < min)
			throw exception("max < min");
		if ((max - min) < count)
			throw exception("нет свободных чисел для множества ");

		Set* set = new Set();
		set->AddToBegin(RandomRange(min, max));

		int i = 1;
		while (i != count)
		{
			if (set->AddToBegin(RandomRange(min, max)))
				i++;
		}
		return set;
	}

	// F5. Создание множества. Модифицированное
	Set* CreateListSet(int count, int min, int max, int mult)
	{
		if (count <= 0)
			throw exception("CreateListSet параметр количества элементов меньше или равен нулю");
		if (max < min)
			throw exception("max < min");
		if ((max - min) < count)
			throw exception("нет свободных чисел для множества ");

		Set* set = new Set();
		set->AddToBegin(RandomRange(min, max));

		int i = 1;
		while (i != count)
		{
			if (set->AddToBegin(RandomRange(min, max)))
				i++;
		}
		return set;
	}

	// F6. Мощность множества.
	int	Set::GetPower()
	{
		return first->size();
	}

	// F7. Вывод элементов множества.
	string Set::GetAllElements(string delimitter)
	{
		string out;
		if (IsEmpty()) return out;

		for (list<int>::iterator it = first->begin(); it != first->end(); ++it)
		{
			out.append(std::to_string(*it));
			out.append(delimitter);
		}

		return out;
	}

	// F8. Удаление множества (очистка памяти, занимаемой списком).
	Set::~Set()
	{
		delete first;
	}


	///---------------------------------------------------------------------------------------------------------------
	// LABA 2

	// F9. Подмножество А-В.
	bool Set::IsSubSet(Set* B)
	{
		if (IsEmpty()) return true;
		if (B->IsEmpty()) return false;

		if (GetPower() > B->GetPower()) return false;

		for (list<int>::iterator it = first->begin(); it != first->end(); ++it)
		{
			if (!B->HasElement(*it)) return false;
		}

		return true;
	}

	// F10. Равенство двух множеств А-В.
	bool Set::IsEqual(Set* B)
	{
		return IsSubSet(B) && B->IsSubSet(this);
	}

	// F11. Объединение двух множеств. 
	Set* Set::Combine(Set* B)
	{
		if (IsEmpty()) return B;
		if (B->IsEmpty()) return this;

		auto res = new Set();

		for (list<int>::iterator it = first->begin(); it != first->end(); ++it)
		{
			res->AddToBegin(*it);
		}

		for (list<int>::iterator it = B->first->begin(); it != B->first->end(); ++it)
		{
			res->AddToBegin(*it);
		}

		return res;
	}
	// F12. Пересечение двух множеств.
	Set* Set::Intersect(Set* B)
	{
		if (IsEmpty() || B->IsEmpty()) return nullptr;

		auto res = new Set();

		for (list<int>::iterator it = first->begin(); it != first->end(); ++it)
		{
			if (B->HasElement(*it))
				res->AddToBegin(*it);
		}

		return res;
	}

	// F13. Разность множеств.
	Set* Set::Difference(Set* B)
	{
		if (IsEmpty()) return nullptr;
		if (B->IsEmpty()) return this;

		auto res = new Set();

		for (list<int>::iterator it = first->begin(); it != first->end(); ++it)
		{
			if (!B->HasElement(*it))
				res->AddToBegin(*it);
		}

		return res;
	}

	// F14. Симметричная разность. 
	Set* Set::SymmetryDifference(Set* B)
	{
		return Combine(B)->Difference(Intersect(B));
	}
}