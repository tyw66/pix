#ifndef FUNNY_GLOBAL_H
#define FUNNY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FUNNY_LIBRARY)
#  define FUNNYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define FUNNYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FUNNY_GLOBAL_H
