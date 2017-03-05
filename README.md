This GFXBoot theme is based on openSUSE's GFXBoot implementation,
thus it is released under the same license therms.

The Artwork is licensed under the Creative Commons -by ND
http://creativecommons.org/licenses/by-nd/2.0/
YOU ARE NOT ALLOWED TO CREATE DERIVATIONS FROM THIS ARTWORK
WITHOUT ASKING THE ORIGINAL CREATOR.

Chakra modifications by

Manuel Tortosa <manutortosa@chakra-project.org> - Source code, settings
Malcer - <malcer@gmx.com> Graphical Artist, code, Settings

Adapted for Antergos by

Alexandre Filgueira <alexfilgueira@antergos.com>

Additions for Antergos by

Phil Wyett <philwyett.rebellion@gmail.com>


HOW-TO
---------------------------------------------------------------

* Compiling

First you need to make sure you have CPIO and GFXBOOT installed.

Run 'make' for creating the theme,
this will generate a folder called 'isolinux', just copy the folder into
the Antergos Live profile, inside boot-files, replacing completelly
the folder 'isolinux' and all it's contents.

Run 'make clean' for cleanning completelly the build

* Tweaking

MAIN FOLDER:

config: This is the master config file. Sets some variables for many parts of the theme.

-------------

DATA FOLDER: This folder cointains the graphics, the binaries and the configuration files for isolinux

about.txt: If this file is present, the "F1" key doesn't lead directly to the help system
but it shows first some "About" text- Once the user press F1, this key gets assigned to help.

backXXXxXXX.jpg backgrounds for several resolutions

*.c32 *.cat *.bin memtest: those are binary modules. It is recommended to update the modules
time to time from your syslinux local package but ensuring it still works. The provided
isolinux.bin and gfxboot.c32 are special versions for Chakra,  so it is not recommended to
change those, else you may loose some features.

isolinux.cfg: This is the master config file for the menu entries. Any option after "showopts" is
shown in the "boot options" line in the menu, however, the rest is also passed to the kernel. You
can either use direct tags as "Start_Live_System" (notice that gfxboot will replace "_" by " ") or
a tag defined in the POT like txt_start. You should define later in the src code the tags you want to
translate in the src/*.ini files.

isolinux.msg: This is the menu shown in text mode in case Isolinux fails to load GFXBoot. You should
use directly the same labels or tags for booting into the several options.

pci.ids: This file is a dababase about PCI devices, used by the provided Hardware Detection Tool and
may be updated time to time from here: http://pciids.sourceforge.net/v2.2/pci.ids

text.jpg: Fade-in text image shown in the Welcome splash.

timer_a.jpg: Timeout spinner for the main menu

welcome.jpg: Splash background

WARNING: All the graphics need to have some special bits set, else GFXBoot will show just black images.

Use the 'imagemagick' packages tools to create the files in the correct format.

Examples:

convert -resize 640 -quality 90 -sampling-factor 2x2 -interlace none my_background.jpg back640x480.jpg

convert -resize 800 -quality 90 -sampling-factor 2x2 -interlace none my_background.jpg back800x600.jpg

Note: Kolourpaint also saves jpeg images in the correct format.

--------------

FONTS FOLDER: This folder cointains any font used in the menu, should be UTF+8 compatible and have
a complete set for the worldwide set of languages, it is not recommended to change the font as the
supplied one is the most complete you may find anywhere regarding language support.

--------------

HELP FOLDER: This folder cointains the html templates for generating the helo system.
TODO: make this folder translatable using translate-toolkit's html2po and many magic :)

--------------

KEYMAPS FOLDER: this folder have xkb keymap files directly from X.Org. you shouldn't remove or
tweak nothing as it have support for every known keyboard already.

--------------

PO FOLDER: Translation files for the main menu. Inside the "bin" folder you will find the several
helpers for adding and removing strings to the POT. It is heavily recommended to use an automated
system like Transifex, so you need only to update the POT file online, then fetch the translations
using the provided ./sync-transifex to update the rest of languages.

---------------

SCREENSHOT FOLDER: Includes several screenshot with the current theme. As we create Git branches
for each release, this folder will show the theme used for this branch.

-----------------

SCRIPTS FOLDER: This folder cointains any special script used during the bootup for catching the
parameters passed by GFXBoot to the kernel, it is here just for referece so in case a theme need
some special tweaking.

locale_setup.sh: Should be used in chakra-init-live, for setting the vconsole keymap, the
locale and the keyboard layout for 10-keyboard.conf

----------------

SRC FOLDER: This folder cointains the main source code for the menu, you need to have GFXBoot
and CPIO installed in order to compile it.

bsplash.inc: Source code for the Welcome splash.

button.inc: Source code for drawing buttons.

common.inc: The main menu generator and handling, parses gfxboot.cfg

dia_*.inc: Those files have the several dialogs source code.

gfxboot.cfg: Master config file.

help.inc: Handles the help system.

keytables.inc: Handles the keyboard settings.

locale.inc Handles the locale settings.

main.bc: bit-compiling includes file.

menu.inc: Generates the main menu.

panel.inc: Generates the bottom panel.

system.inc: Abstracted low-level functions.

timeout.inc: Handles the timeout spinner.

windows.inc: Draws the main window.

xmenu.inc: Several functions for drawing the menu elements.
