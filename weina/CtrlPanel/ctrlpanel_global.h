#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CTRLPANEL_LIB)
#  define CTRLPANEL_EXPORT Q_DECL_EXPORT
# else
#  define CTRLPANEL_EXPORT Q_DECL_IMPORT
# endif
#else
# define CTRLPANEL_EXPORT
#endif


#define CTRLPANEL_API extern "C" CTRLPANEL_EXPORT