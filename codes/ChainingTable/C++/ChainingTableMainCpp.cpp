#include <iostream>
#include <cstdlib>
#include "PersonCpp.h"
#include "PersonCpp.cpp"
#include "ChainingTableCpp.h"
#include "ChainingTableCpp.cpp"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table<int, Person*> myTbl(MyHashFunc);
	Person* np;
	Person* sp;
	Person* rp;

	np = new Person(900254, "LEE", "Seoul");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(900139, "KIM", "Jeju");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(900827, "HAN", "Kangwon");
	myTbl.TBLInsert(np->GetSSN(), np);

	sp = myTbl.TBLSearch(900254);
	if (sp != NULL)
		sp->ShowPerInfo();

	sp = myTbl.TBLSearch(900139);
	if (sp != NULL)
		sp->ShowPerInfo();

	sp = myTbl.TBLSearch(900827);
	if (sp != NULL)
		sp->ShowPerInfo();

	rp = myTbl.TBLDelete(900254);
	if (rp != NULL)
		free(rp);

	rp = myTbl.TBLDelete(900139);
	if (rp != NULL)
		free(rp);

	rp = myTbl.TBLDelete(900827);
	if (rp != NULL)
		free(rp);

	return 0;
}