// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E37D8EB3_D113_431E_86A3_24980E357807__INCLUDED_)
#define AFX_STDAFX_H__E37D8EB3_D113_431E_86A3_24980E357807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define FOR_CHINA 1

#pragma warning ( disable : 4786 )


#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT 0x501	// Windows XP

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT

#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "..\\include\\define.h"
#include "..\common\Logproc.h"
#include "LogToFile.h"

#define DB_CONNECT_DSN			"MuOnlineJoinDB"
#define DB_CONNECT_UID			"MuOnlineAdmin"
#define DB_CONNECT_PWD			"wkfwkRnfRnf"

extern char szDbConnectID[];
extern char szDbConnectPass[];
extern char szDbConnectDsn[];

#include "CQuery.h"

extern char g_szDBID_DESC[];

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E37D8EB3_D113_431E_86A3_24980E357807__INCLUDED_)
