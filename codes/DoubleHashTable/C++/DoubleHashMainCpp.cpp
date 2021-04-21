#include <iostream>
#include <cstdlib>
#include "PersonCpp.h"
#include "TableCpp.h"
#include "TableCpp.cpp"

int MyHashFunc1(int k)
{
	return k % 100;
}

int MyHashFunc2(int k)
{
	return 1 + (k % 7);
}

int main(void)
{
	Table<int, Person*> myTbl(MyHashFunc1, MyHashFunc2);
	Person* np;
	Person* sp;
	Person* rp;

	np = new Person(20120003, "LEE", "Seoul");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20130012, "KIM", "Jeju");
	myTbl.TBLInsert(np->GetSSN(), np);

	np = new Person(20170049, "HAN", "Kangwon");
	myTbl.TBLInsert(np->GetSSN(), np);

	sp = myTbl.TBLSearch(20120003);
	if (sp != NULL)
		sp->ShowPerInfo();

	sp = myTbl.TBLSearch(20130012);
	if (sp != NULL)
		sp->ShowPerInfo();

	sp = myTbl.TBLSearch(20170049);
	if (sp != NULL)
		sp->ShowPerInfo();

	rp = myTbl.TBLDelete(20120003);
	free(rp);

	rp = myTbl.TBLDelete(20130012);
	free(rp);

	rp = myTbl.TBLDelete(20170049);
	free(rp);
}