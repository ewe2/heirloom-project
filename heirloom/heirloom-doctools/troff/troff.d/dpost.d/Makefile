#
# A BSD-compatible install command.
#
INSTALL=install

#
# Packaging prefix.
#
PREFIX=/usr/local

#
# Where to place binaries.
#
BINDIR=$(PREFIX)/ucb

#
# Where to place libraries.
#
LIBDIR=$(PREFIX)/ucblib

#
# Where to place ASCII charts and the like.
#
PUBDIR=$(PREFIX)/pub

#
# Where to place manual pages.
#
MANDIR=$(PREFIX)/share/heirloom-doctools/man

#
# Where to place the troff macro packages.
#
MACDIR=$(LIBDIR)/doctools/tmac

#
# Where to place the troff font files.
#
FNTDIR=$(LIBDIR)/doctools/font

#
# Where to place PostScript helper files.
#
PSTDIR=$(FNTDIR)/devpost/postscript

#
# Where to place the nroff terminal description files.
#
TABDIR=$(LIBDIR)/doctools/nterm

#
# Where to place troff hyphenation files.
#
HYPDIR=$(LIBDIR)/doctools/hyphen

#
# Where to place files belonging to the "refer" utility.
#
REFDIR=$(LIBDIR)/reftools

#
# Define this if you want troff and nroff to be able to process
# locale-specific (8-bit) characters. It requires appropriate support
# from the C library, so it does not work e.g. with diet libc.
#
EUC=-DEUC

#
# Binaries are stripped with this command after installation.
#
STRIP=strip

#
# The C compiler.
#
#CC=

#
# The C++ compiler.
#
#CXX=

#
# Compiler flags.
#
_CFLAGS=$(CFLAGS) $(_CPPFLAGS) $(__CDBG) $(__CLDBG)

#
# C preprocessor flags.
#
# Use -D_GNU_SOURCE for Linux with GNU libc.
# Use -D_INCLUDE__STDC_A1_SOURCE for HP-UX.
#
_CPPFLAGS=$(CPPFLAGS) -D_GNU_SOURCE

#
# Linker flags.
#
_LDFLAGS=$(LDFLAGS) $(__CLDBG)

#
# Additional libraries to link with.
#
#LIBS=

#
# A Bourne-compatible shell.
#
SHELL=/bin/sh
RELEASE = Git snapshot 190405
#RELEASE = release 160308
BST = ../../../stuff/bst

OBJ = dpost.o draw.o color.o pictures.o ps_include.o afm.o \
	makedev.o glob.o misc.o request.o version.o \
	asciitype.o otf.o ../fontmap.o $(BST)/bst.o

FLAGS = -I. -I.. -DFNTDIR='"$(FNTDIR)"' -DPSTDIR='"$(PSTDIR)"' $(EUC) \
	$(DEFINES) -I../../../include -I.. -I$(BST)

.c.o:
	$(CC) $(_CFLAGS) $(FLAGS) -c $<

all: dpost dpost.1

dpost: $(OBJ)
	$(CC) $(_CFLAGS) $(_LDFLAGS) $(OBJ) $(LIBS) -o dpost

install:
	$(INSTALL) -c dpost $(ROOT)$(BINDIR)/dpost
	$(STRIP) $(ROOT)$(BINDIR)/dpost
	mkdir -p $(ROOT)$(MANDIR)/man1
	$(INSTALL) -c -m 644 dpost.1 $(ROOT)$(MANDIR)/man1/dpost.1

clean:
	rm -f $(OBJ) dpost core log *~ dpost.1

mrproper: clean

dpost.1: dpost.1.in
	sed -e 's"/usr/ucblib/doctools/font/devpost/postscript/"$(ROOT)$(PSTDIR)/"' \
	    -e 's"/usr/ucblib/doctools/font"$(ROOT)$(FNTDIR)"' \
	    -e 's"/usr/lib/lp/postscript/"$(ROOT)$(PSTDIR)/"' \
	    -e 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(MACDIR)/"' dpost.1.in > $@

color.o: color.c gen.h ext.h
dpost.o: dpost.c comments.h gen.h path.h ext.h ../dev.h dpost.h ../afm.h \
	asciitype.h
draw.o: draw.c gen.h ext.h
glob.o: glob.c gen.h
misc.o: misc.c gen.h ext.h path.h asciitype.h
pictures.o: pictures.c comments.h gen.h path.h
ps_include.o: ps_include.c ext.h gen.h asciitype.h path.h
request.o: request.c gen.h request.h path.h
afm.o: afm.c ../dev.h ../afm.h ../afm.c
otf.o: otf.c ../dev.h ../afm.h ../otf.c
makedev.o: makedev.c ../dev.h ../makedev.c
asciitype.o: asciitype.h
version.o: version.c ../../version.c
