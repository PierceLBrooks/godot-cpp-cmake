// BK - MinGW dirent is super broken, using MSVC compatibility one...
#ifdef __MINGW32__
#ifndef _DIRENT_H_
#define _DIRENT_H_
#include "../msvc/dirent.h"
#endif // _DIRENT_H_
#else
#include_next <dirent.h>
#endif // __MINGW32__
