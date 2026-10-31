// PetDBSet.cpp: implementation of the CPetDBSet class.
// Decompilation Completed -> All Same as WebZen
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PetDBSet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPetDBSet::CPetDBSet()
{

}

CPetDBSet::~CPetDBSet()
{

}

BOOL CPetDBSet::Connect()
{
	return this->CDBConBase::Connect(szDbConnectID, szDbConnectPass);
}

BOOL CPetDBSet::LoadPetInfo(DWORD number, int& Level, int& Exp)
{
	CString qSQL;

	qSQL.Format("SELECT Pet_Level, Pet_Exp FROM T_PetItem_Info WHERE ItemSerial=%u", number);

	if(this->m_DBQuery.Exec(qSQL) == FALSE)
	{
		return FALSE;
	}

	if(this->m_DBQuery.Fetch() == SQL_NO_DATA)
	{
		this->m_DBQuery.Clear();
		this->CreatePetItemInfo(number, 1, 0);
		return FALSE;
	}

	Level = this->m_DBQuery.GetInt("Pet_Level");
	Exp = this->m_DBQuery.GetInt("Pet_Exp");

	this->m_DBQuery.Clear();

	if(Level < 0)
	{
		Level = 1;
	}

	if(Exp < 0)
	{
		Exp = 0;
	}

	return TRUE;
}

BOOL CPetDBSet::SavePetInfo(DWORD number, int Level, int Exp)
{
	CString qSQL;

	qSQL.Format("UPDATE T_PetItem_Info SET Pet_Level=%d, Pet_Exp=%d WHERE ItemSerial=%u", Level, Exp, number);

	if(this->m_DBQuery.Exec(qSQL) == FALSE)
	{
		return FALSE;
	}

	this->m_DBQuery.Clear();

	return TRUE;
}

BOOL CPetDBSet::CreatePetItemInfo(DWORD serial, int Level, int Exp)
{
	CString qSQL;

	qSQL.Format("INSERT INTO T_PetItem_Info (ItemSerial,Pet_Level,Pet_Exp) VALUES(%u,%d,%d)", serial, Level, Exp);

	if(this->m_DBQuery.Exec(qSQL) == FALSE)
	{
		return FALSE;
	}

	return TRUE;
}