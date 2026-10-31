// CharDBSet.h: interface for the CCharDBSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHARDBSET_H__BED5C4C4_EA0B_4126_A05F_9584C5F0E889__INCLUDED_)
#define AFX_CHARDBSET_H__BED5C4C4_EA0B_4126_A05F_9584C5F0E889__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\include\prodef.h"
#include "..\..\include\Sprodef.h"

enum DB_CLASS_TYPE
{
	DB_CLASS_TYPE_WIZARD = 0x0,
	DB_CLASS_TYPE_KNIGHT = 0x10,
	DB_CLASS_TYPE_ELF = 0x20,
	DB_CLASS_TYPE_MAGUMSA = 0x30,
#ifdef DARKLORD_WORK
	DB_CLASS_TYPE_DARKLORD = 0x40,
#endif
#ifdef ADD_SEASON_3_NEW_CHARACTER_SUMMONER_20070912	// 기본값 설정
	DB_CLASS_TYPE_SUMMONER = 0x50,
#endif
#if 0
	DB_CLASS_TYPE_MONK = 0x60,
	DB_CLASS_TYPE_LANCER = 0x70,
#endif
};

typedef struct
{
	int registry;
	char AccountID[MAX_IDSTRING+1];
	char Name[MAX_IDSTRING+1];
	BYTE Class;
	int Level;
	int LevelUpPoint;
	int Experience;
	int NextExperience;
	int Money;
	WORD Strength;
	WORD Dexterity;
	WORD Vitality;
	WORD Energy;
#ifdef DARKLORD_WORK
	WORD Leadership;
#endif
	WORD ChatLitmitTime;
	float Life;
	float MaxLife;
	float Mana;
	float MaxMana;
	int PkCount;
	int PkLevel;
	int PkTime;
	BYTE dbInventory[MAX_DBINVENTORY];
	BYTE dbMagicList[MAX_DBMAGIC];
	BYTE dbQuest[MAX_DBQUEST];
	BYTE MapNumber;
	BYTE MapX;
	BYTE MapY;
	BYTE Dir;
	BYTE CtlCode;
	BYTE DbVersion;
	int FruitPoint;
#if 0
	BYTE btExtendedInvenCount;
	BYTE btExtendedWarehouseCount;
	short sExGameServerCode;
#endif
}CharacterInfo_Struct, *LPCharacterInfo_Struct;

class CCharDBSet  
{
public:
	CCharDBSet();
	virtual ~CCharDBSet();

	BOOL Connect();
	int DeleteCharacter(char* AccoundID, char* CharacterID);
	int DeleteCharacter_DregInfo(char* CharacterID);
	int CreateCharacter(CString accountId, CString Name, BYTE Class);
	BOOL DefaultCharacterCreate(BYTE classskin);
	BOOL DefaultCreateCharacterInsert(LPCharacterInfo_Struct lpObj);
	BOOL DefaultCreateCharacterAllDelete();
	BYTE SaveCharacter(char* Name, LPCharacterInfo_Struct lpObj);
	BOOL GetCharacter(char* szAccountID, char* Name, LPCharacterInfo_Struct lpObj);
	BOOL GetCharacter(char* name);
	BOOL SaveItem(char* Name, BYTE* ItemBuf);
	void SaveMacroInfo(char* szAccountID, char* Name, BYTE* lpMacroInfo);
	BOOL LoadMacroInfo(char* szAccountID, char* Name, BYTE* lpMacroInfo);
	int CharServerMove(char* Name);
	void SetSP_WZ_CreateCharacterGetVersion(int version);
	BOOL CheckSP_WZ_CreateCharacterGetVersion();
	BYTE CurCharNameSave(char* Name);
	int ChangeName(char* AccountId, char* OldName, char* NewName);
	int GetCharacterID(char* chName, char* chUserID);
	DWORD GetCharacterClass(char* chName);
	bool GetResetInfo(char *AccountID, char *CharName, int *ResetCount);
	bool UpdateResetInfo(char *AccountID, char *CharName, int ResetCount);
public:
	int m_CreateCharacterVer;
	CQuery m_DBQuery;
};

#endif // !defined(AFX_CHARDBSET_H__BED5C4C4_EA0B_4126_A05F_9584C5F0E889__INCLUDED_)
