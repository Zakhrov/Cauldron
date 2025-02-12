// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#ifdef __GNUC__
// do my gcc specific stuff
// C RunTime Header Files
#include <malloc.h>
#include <cassert>

// GFX API
#include <vulkan/vulkan.h>

// math API
#include "../../libs/DirextXMath/Inc/DirectXMath.h"
using namespace DirectX;

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <limits>
#include <algorithm>
#include <mutex>
#else
// ... handle this for other compilers


#include <SDKDDKVer.h>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#include <windows.h>
#include <windowsx.h>
#include <wrl.h>
#include <KnownFolders.h>
#include <shlobj.h>

// C RunTime Header Files
#include <malloc.h>
#include <tchar.h>
#include <cassert>

// GFX API
#include <vulkan/vulkan.h>

// math API
#include <DirectXMath.h>
using namespace DirectX;

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <limits>
#include <algorithm>
#include <mutex>

#endif

//#include <Shellapi.h>

// TODO: reference additional headers your program requires here
