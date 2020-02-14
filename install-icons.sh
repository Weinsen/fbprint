#!/bin/sh

FOLDER=$(pwd)
HEADER=${PWD}/include/icons.h

cd icons
for B in $(ls *.bmp); do
	bmp2header -t 75 $B
	echo $B
done
cd ..

HEADERS=$(grep "const uint8_t .* = {" icons/*.h | awk '{print $3}')

if [ -z "$HEADERS" ]; then
	echo "Empty folder"
	printf "#ifndef FB_ICONS\r\n#define FB_ICONS\r\n\r\n#endif" > $HEADER
	exit 0
fi


printf "#ifndef FB_ICONS\r\n#define FB_ICONS\r\n#define FB_ICON_SET\r\n\r\n" > $HEADER
printf "#include \"fbprint.h\"\r\n" >> $HEADER

HEADERS=$(cd icons; ls *.h)
for H in $HEADERS; do
	printf "#include \"%s\"\r\n" "$H" >> $HEADER
done
printf "\r\n" >> $HEADER

printf "icon_t icon_list[] = {\r\n" >> $HEADER

HEADERS=$(grep "const uint8_t .* = {" icons/*.h | awk '{print $3}')
for H in $HEADERS; do
	ICON=${H%%[*}
	printf "\tINCLUDE_ICON($ICON),\r\n" >> $HEADER
done
printf "};\r\n\r\n" >> $HEADER

printf "#endif" >> $HEADER


