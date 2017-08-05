// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include <ObjBase.h>
#include <UIlib.h>

using namespace DuiLib;

#ifdef _DEBUG
#pragma comment (lib, "duilib_ud.lib")
#else
#pragma comment (lib, "duilib_u.lib")
#endif

// TODO: reference additional headers your program requires here
