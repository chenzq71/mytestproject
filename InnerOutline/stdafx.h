// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS         // remove support for MFC controls in dialogs
#define NO_WARN_MBCS_MFC_DEPRECATION  //多字节字符系统MFC库不包含在vs中，定义这个宏消除编译时的警告（'MBCS_Support_Deprecated_In_MFC': MBCS support in MFC is deprecated and may be removed in a future version of MFC.）

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include <afx.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>
// Windows Header Files:
#include <windows.h>



// TODO: reference additional headers your program requires here
using namespace std;
#include <vector>
#include <map>
#include <list>
#include <numeric>
#include <algorithm>
#include <iterator>
//#include <boost\smart_ptr\shared_ptr.hpp>
#include <memory> //shared_ptr
//using namespace boost;

#include "targetver.h"

#include "THMath\TH_Math_API.h"
using namespace THMATH;
//#include "THMath\DblPoint.h"
#include "THCurveLib\THCurveLibShare.h"
#include "THCurveLib\THCSArc2.h"
#include "BwDesign/BWDesignMacro.h"
#include "BwDesign/BWDesignInc.h"
#include "BwDesign/DesignToDraw/BWRefLineMan.h"
#include "BwDesign/DesignBase/BWSteelQun.h"
#include "BwDesign/DesignBase/BWSteelGroup.h"
#include "BwDesign\DesignBase\BWSteelNumOrder.h"
#include "BwDesign\DesignBase\BWComponentSteelP0.h"
#include "BwDesign\DesignBase\BWSteel.h"
#include "BwDesign\DesignToDraw\BWRefLine.h"
#include "BwDesign\Tool\StrChange.h"
#include "BwDesign\DesignBase\BWSteelMan.h"
#include "BwDesign\DesignToDraw\BWDWGJBlock.h"
#include "BwDesign\DrawCellGroup\BWDrawGroup.h"
#include "BwDesign\DrawCell\BWLineGroup\BWLineGroup.h"
#include "BwDesign\DrawCell\BWLineGroup\BWLineName.h"
#include "BwDesign/DesignBase/BWComponentP0Base.h"

using namespace BWDSGNMOD;
#include "geometry\geometryMacro.h"
#include "geometry\THAnyLine.h"
#include "geometry\THLine.h"
#include "geometry\THCircle.h"
#include "geometry\THArc.h"
using namespace GEOMETRY;

#include "tools\toolsMacro.h"
#include "tools\toolsInc.h"
#include "tools\BoostSerilization.h"
using namespace TOOLS;

#include "InnerOutline.h"

#include "TunnelData\macro.h"
