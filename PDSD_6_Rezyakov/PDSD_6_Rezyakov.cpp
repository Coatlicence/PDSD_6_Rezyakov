#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "SetLab1_2_Rezyakov.h"
#include "SetLab3_Rezyakov.h"
#include "SetLab4_Rezyakov.h"
#include "SetLab5_Rezyakov.h"
using namespace std;

int main()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	int SetSize1;
	int SetSize2;
	unsigned int start_time;
	unsigned int end_time;
	const int col_width = 25;

	string headers[] = { "", "Односвязный список", "Класс список", "List", "Set" };
	cout << "Введите размер первого множества (от 1000 до 4000): ";
	cin >> SetSize1;
	while (SetSize1 > 4000 || SetSize1 < 1000) {
		cout << "Неверный размер" << endl;
		cout << "Введите размер первого множества (от 1000 до 4000): ";
		cin >> SetSize1;
	}
	cout << "Введите размер второго множества (от 1000 до 4000): ";
	cin >> SetSize2;
	while (SetSize2 > 4000 || SetSize2 < 1000) {
		cout << "Неверный размер" << endl;
		cout << "Введите размер первого множества (от 1000 до 4000): ";
		cin >> SetSize2;
	}
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	for (int i = 0; i < end(headers) - begin(headers); i++) {
		cout << left << setw(col_width) << setfill(' ') << (headers[i]) << "|";
	}
	cout << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;

	SetElement* setOnNodes2			= CreateListSet(SetSize2, 0, 10 * SetSize2, 5);
	SetOnNode::Set* setOnNodeList2	= SetOnNode::CreateListSet(SetSize2, 0, 10 * SetSize2, 5);
	SetOnList::Set* setOnList2		= SetOnList::CreateListSet(SetSize2, 0, 10 * SetSize2, 5);
	SetOnSet::Set* setOnSet2		= SetOnSet::CreateListSet(SetSize2, 0, 10 * SetSize2, 5);

	//Создание множества
	cout << left << setw(col_width) << setfill(' ') << "Создание множества" << '|';

	srand(0);
	start_time = clock();
	SetElement* setOnNodes = CreateListSet(SetSize1, 0, 10 * SetSize1, 10);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	SetOnNode::Set* setOnNodeList = SetOnNode::CreateListSet(SetSize1, 0, 10 * SetSize1, 10);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	SetOnList::Set* setOnList = SetOnList::CreateListSet(SetSize1, 0, 10 * SetSize1, 10);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	SetOnSet::Set* setOnSet = SetOnSet::CreateListSet(SetSize1, 0, 10 * SetSize1, 10);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Мощность множества
	cout << left << setw(col_width) << setfill(' ') << "Мощность" << '|';
	srand(0);
	start_time = clock();
	GetPower(setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->GetPower();
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->GetPower();
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->GetPower();
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Подмножество A-A
	cout << left << setw(col_width) << setfill(' ') << "Подмножество A-A " << '|';
	srand(0);
	start_time = clock();
	IsSubSet(setOnNodes, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->IsSubSet(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->IsSubSet(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->IsSubSet(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Подмножество B-A
	cout << left << setw(col_width) << setfill(' ') << "Подмножество B-A " << '|';
	srand(0);
	start_time = clock();
	IsSubSet(setOnNodes2, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList2->IsSubSet(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList2->IsSubSet(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet2->IsSubSet(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Равенство А-А
	cout << left << setw(col_width) << setfill(' ') << "Равенство A-A " << '|';
	srand(0);
	start_time = clock();
	IsEqual(setOnNodes, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->IsEqual(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->IsEqual(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->IsEqual(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Равенство B-A
	cout << left << setw(col_width) << setfill(' ') << "Равенство B-A " << '|';
	srand(0);
	start_time = clock();
	IsEqual(setOnNodes2, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList2->IsEqual(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList2->IsEqual(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet2->IsEqual(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Объединение множеств
	cout << left << setw(col_width) << setfill(' ') << "Объединение " << '|';
	srand(0);
	start_time = clock();
	Combine(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->Combine(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->Combine(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->Combine(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Пересечение множеств
	cout << left << setw(col_width) << setfill(' ') << "Пересечение " << '|';
	srand(0);
	start_time = clock();
	Intersect(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->Intersect(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->Intersect(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->Intersect(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Разность A-B
	cout << left << setw(col_width) << setfill(' ') << "Разность A - B" << '|';
	srand(0);
	start_time = clock();
	Difference(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->Difference(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->Difference(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->Difference(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Разность B-A
	cout << left << setw(col_width) << setfill(' ') << "Разность B - A" << '|';
	srand(0);
	start_time = clock();
	Difference(setOnNodes2, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList2->Difference(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList2->Difference(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet2->Difference(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	
	//Симметричная разность
	cout << left << setw(col_width) << setfill(' ') << "Симметричная разность" << '|';
	srand(0);
	start_time = clock();
	SymmetryDifference(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnNodeList->SymmetryDifference(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnList->SymmetryDifference(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	
	srand(0);
	start_time = clock();
	setOnSet->SymmetryDifference(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}