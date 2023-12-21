To use this font, simply copy or checkout the "master" folder to your ProffieOS/config/ folder, and then in your proffieboard config, #include "master/Master_v2.h" for Proffieboard 2, or "master/Master_v3.h" for Proffieboard 3, like so:

#include "master/Master_v3.h"

then simply create ur styles like this to use the master font.

// Basic blade style.
{ "WHITE;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	()  //, "white"
},

Use EDIT MODE to modify and choose the various options. comments are in the respective master/Master_v2.h or master/Master_v3.h files.
