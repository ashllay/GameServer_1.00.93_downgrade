#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__


#include "..\include\prodef.h"
#include "..\include\Sprodef.h"
//#include "User.h"
#pragma pack(1)
typedef struct
{
	PBMSG_HEAD h;
	int iUserIndex;
	char szCharName[MAX_IDSTRING+1];
}PMSG_REQ_QUESTEXP_INFO,*LPPMSG_REQ_QUESTEXP_INFO;
#pragma pack()
//----------------------------------------------------------------------------
extern void ProtocolCore(BYTE protoNum, BYTE *aRecv, int aLen, short aIndex);

//----------------------------------------------------------------------------

#endif