#include "SetLab5_Rezyakov.h"
#include <random>
#include <exception>

using std::exception;
using std::to_string;

namespace SetOnSet
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
		first = new set<int>;
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

		for (auto it = first->begin(); it != first->end(); ++it)
		{
			if (*it == element) return true;
		}

		return false;
	}

	// F4. Добавление нового элемента в множество.
	void Set::AddToBegin(int element)
	{
		first->insert(element);
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

		for (int i = 1; i < count; i++)
		{
			int randint = RandomRange(min, max);
			while (set->HasElement(randint))
			{
				randint = RandomRange(min, max);
			}

			set->AddToBegin(randint);
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


		set->AddToBegin(RandomRange(min, max, mult));

		for (int i = 1; i < count; i++)
		{
			int randint = RandomRange(min, max, mult);
			while (set->HasElement(randint))
			{
				randint = RandomRange(min, max, mult);
			}

			set->AddToBegin(randint);
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

		for (auto it = first->begin(); it != first->end(); ++it)
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

		for (auto it = first->begin(); it != first->end(); ++it)
			if (!B->HasElement(*it)) return false;

		return true;
	}

	// F10. Равенство двух множеств А-В.
	bool Set::IsEqual(Set* B)
	{
		return first == B->first;
	}

	// F11. Объединение двух множеств. 
	Set* Set::Combine(Set* B)
	{
		auto res = new Set();

		res->first->insert(first->begin(), first->end());

		res->first->insert(B->first->begin(), B->first->end());

		return res;
	}

	// F12. Пересечение двух множеств.
	Set* Set::Intersect(Set* B)
	{
		auto res = new Set();

		if (IsEmpty() || B->IsEmpty()) return res;

		for (auto it = first->begin(); it != first->end(); ++it)
			if (B->HasElement(*it))
				res->AddToBegin(*it);

		return res;
	}

	// F13. Разность множеств.
	Set* Set::Difference(Set* B)
	{
		auto res = new Set();

		if (IsEmpty()) return res;

		for (auto it = first->begin(); it != first->end(); ++it)
			if (!B->HasElement(*it)) res->AddToBegin(*it);

		return res;
	}

	// F14. Симметричная разность. 
	Set* Set::SymmetryDifference(Set* B)
	{
		return Combine(B)->Difference(Intersect(B));
	}
}