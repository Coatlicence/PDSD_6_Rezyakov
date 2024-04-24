#include "SetLab3_Rezyakov.h"
#include <random>
#include <exception>

using std::exception;
using std::to_string;

namespace SetOnNode
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
		first = nullptr;
	}

	// F2. Пустое множество?
	bool Set::IsEmpty()
	{
		if (first == nullptr)
			return true;
		else
			return false;
	}

	// F3. Проверка принадлежности элемента множеству. 
	bool Set::HasElement(int element)
	{
		if (IsEmpty()) return false;

		Set::SetElement* nextel = first;
		while (nextel)
		{
			if (nextel->value == element) return true;

			nextel = nextel->next;
		}

		return false;
	}

	// F4. Добавление нового элемента в множество.
	void Set::AddToBegin(int element)
	{
		if (HasElement(element)) return;

		SetElement* el = new SetElement();

		el->value = element;

		if (first == nullptr)
			first = el;
		else
		{
			el->next = first;
			first = el;
		}
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

		/*
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
		*/

		Set* set = new Set();

		while (set->GetPower() < count)
		{
			set->AddToBegin(RandomRange(min, max));
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

		/*
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
		*/

		Set* set = new Set();

		while (set->GetPower() < count)
		{
			set->AddToBegin(RandomRange(min, max, mult));
		}

		return set;
	}



	// F6. Мощность множества.
	int	Set::GetPower()
	{
		int power = 0;

		if (IsEmpty()) return power;

		auto nextel = first;
		while (nextel)
		{
			power++;
			nextel = nextel->next;
		}

		return power;
	}

	// F7. Вывод элементов множества.
	string Set::GetAllElements(string delimitter)
	{
		string out;
		if (IsEmpty()) return out;

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
	Set::~Set()
	{
		if (IsEmpty()) return;

		SetElement* next = first->next;

		delete first;
		first = nullptr;

		while (next)
		{
			auto nextel = next->next;

			delete next;
			next = nextel;
		}
	}


	///---------------------------------------------------------------------------------------------------------------
	// LABA 2

	// F9. Подмножество А-В.
	bool Set::IsSubSet(Set* B)
	{
		if (IsEmpty()) return true;
		if (B->IsEmpty()) return false;

		if (GetPower() > B->GetPower()) return false;

		auto nexta = first;
		while (nexta != nullptr)
		{
			if (!B->HasElement(nexta->value))
				return false;

			nexta = nexta->next;
		}

		return true;
	}

	// F10. Равенство двух множеств А-В.
	bool Set::IsEqual(Set* B)
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

		if (IsSubSet(B) && B->IsSubSet(this))
			return true;
		else
			return false;

	}
	// F11. Объединение двух множеств. 
	Set* Set::Combine(Set* B)
	{
		if (IsEmpty()) return B;
		if (B->IsEmpty()) return this;

		auto res = new Set();

		auto nexta = first;
		while (nexta != nullptr)
		{
			res->AddToBegin(nexta->value);
			nexta = nexta->next;
		}

		auto nextb = B->first;
		while (nextb != nullptr)
		{
			res->AddToBegin(nextb->value);
			nextb = nextb->next;
		}

		return res;
	}
	// F12. Пересечение двух множеств.
	Set* Set::Intersect(Set* B)
	{
		if (IsEmpty() || B->IsEmpty()) return nullptr;

		auto res = new Set();

		auto nexta = first;
		while (nexta != nullptr)
		{
			if (B->HasElement(nexta->value))
				res->AddToBegin(nexta->value);

			nexta = nexta->next;
		}

		return res;
	}

	// F13. Разность множеств.
	Set* Set::Difference(Set* B)
	{
		if (IsEmpty()) return nullptr;
		if (B->IsEmpty()) return this;

		auto res = new Set();

		auto nexta = first;
		while (nexta != nullptr)
		{
			if (!B->HasElement(nexta->value))
				res->AddToBegin(nexta->value);

			nexta = nexta->next;
		}

		return res;
	}

	// F14. Симметричная разность. 
	Set* Set::SymmetryDifference(Set* B)
	{
		return Combine(B)->Difference(Intersect(B));
	}

}