#ifndef FB_ICONS
#define FB_ICONS
#define FB_ICON_SET

#include "fbprint.h"
#include "connection_0.h"
#include "connection_1.h"
#include "connection_2.h"
#include "connection.h"

icon_t icon_list[] = {
	INCLUDE_ICON(connection),
	INCLUDE_ICON(connection_0),
	INCLUDE_ICON(connection_1),
	INCLUDE_ICON(connection_2)
};

#endif