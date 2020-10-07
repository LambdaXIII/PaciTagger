#ifndef PACISTRINGKIT_GLOBAL_H
#define PACISTRINGKIT_GLOBAL_H

//#include <QtCore/qglobal.h>

#ifdef OS_WIN
  #ifdef DLL_EXPORT
    #define PACISTRINGKITSHARED_EXPORT __declspec(dllexport)
  #else
    #define PACISTRINGKITSHARED_EXPORT __declspec(dllimport)
  #endif
#else // OSWIN
  #define PACISTRINGKITSHARED_EXPORT
#endif // OSWIN

#endif // PACISTRINGKIT_GLOBAL_H
