#ifndef FB_ICONS
#define FB_ICONS
#define FB_ICON_SET

#include "fbprint.h"
#include "beer_tap.h"
#include "cloud.h"
#include "download.h"
#include "ethernet.h"
#include "my.h"
#include "nfc.h"
#include "Tapp.h"

icon_t icon_list[] = {
	INCLUDE_ICON(beer_tap),
	INCLUDE_ICON(cloud),
	INCLUDE_ICON(download),
	INCLUDE_ICON(ethernet),
	INCLUDE_ICON(my),
	INCLUDE_ICON(nfc),
	INCLUDE_ICON(Tapp),
};

#endif