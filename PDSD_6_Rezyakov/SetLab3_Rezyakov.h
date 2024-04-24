#pragma once
#pragma once
#include <string>

using std::string;

namespace SetOnNode
{
	class Set;

	int RandomRange(int min, int max);

	int RandomRange(int min, int max, int mult);

	// F5. Создание множества.
	Set* CreateListSet(int count, int min, int max);

	// F5. Создание множества. Модифицированное
	Set* CreateListSet(int count, int min, int max, int mult);


	class Set
	{
		struct SetElement
		{
			int value;
			SetElement* next;
		};

		// Голова списка
		SetElement* first;

	public:
		// F1. Создание пустого множества
		Set();

		// F2. Пустое множество?
		bool IsEmpty();

		// F3. Проверка принадлежности элемента множеству. 
		bool HasElement(int element);

		// F4. Добавление нового элемента в множество.
		void AddToBegin(int element);

		// F6. Мощность множества.
		int	GetPower();

		// F7. Вывод элементов множества.
		string GetAllElements(string delimitter);

		// F8. Удаление множества (очистка памяти, занимаемой списком).
		~Set();

		// F9. Подмножество А-В.
		bool IsSubSet(Set* B);

		// F10. Равенство двух множеств А-В.
		bool IsEqual(Set* B);

		// F11. Объединение двух множеств. 
		Set* Combine(Set* B);

		// F12. Пересечение двух множеств.
		Set* Intersect(Set* B);

		// F13. Разность множеств.
		Set* Difference(Set* B);

		// F14. Симметричная разность. 
		Set* SymmetryDifference(Set* B);
	};

}