// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the INNEROUTLINE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// INNEROUTLINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef INNEROUTLINE_EXPORTS
#define INNEROUTLINE_API __declspec(dllexport)
#else
#define INNEROUTLINE_API __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib,"InnerOutline_d.lib")
#pragma message("Automatically linking with InnerOutline_d.lib")
#else
#pragma comment(lib,"InnerOutline.lib")
#pragma message("Automatically linking with InnerOutline.lib")
#endif
#endif

//macro
#define THDRAW_INNEROUTLINE_BEGIN namespace INNEROUTLINE{
#define THDRAW_INNEROUTLINE_END }

//// This class is exported from the InnerOutline.dll
//class INNEROUTLINE_API CInnerOutline {
//public:
//	CInnerOutline(void);
//	// TODO: add your methods here.
//};

extern INNEROUTLINE_API int nInnerOutline;

INNEROUTLINE_API int fnInnerOutline(void);
