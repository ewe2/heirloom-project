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
VPATH=..

LIBHNJ = ../libhnj
BST = ../../stuff/bst

OBJ = n10.o n6.o hytab.o n1.o n2.o n3.o n4.o n5.o \
	n7.o n8.o n9.o ni.o nii.o suftab.o \
	version.o draw.o $(BST)/bst.o

FLAGS = -DNROFF -DUSG $(EUC) -I. -I.. -I../../include -DMACDIR='"$(MACDIR)"' \
	-DFNTDIR='"$(FNTDIR)"' -DTABDIR='"$(TABDIR)"' -DHYPDIR='"$(HYPDIR)"' \
	-DSHELL='"$(SHELL)"' -DRELEASE='"$(RELEASE)"' $(DEFINES) \
	-I$(BST)

.c.o:
	$(CC) $(_CFLAGS) $(FLAGS) -c $<

all: nroff nroff.1

nroff: $(OBJ) $(LIBHNJ)/libhnj.a
	$(CC) $(_CFLAGS) $(_LDFLAGS) $(OBJ) -L$(LIBHNJ) -lhnj $(LIBS) -o nroff

install:
	$(INSTALL) -c nroff $(ROOT)$(BINDIR)/nroff
	$(STRIP) $(ROOT)$(BINDIR)/nroff
	$(INSTALL) -c -m 644 nroff.1 $(ROOT)$(MANDIR)/man1/nroff.1

clean:
	rm -f $(OBJ) nroff core log *~ nroff.1

mrproper: clean

nroff.1: nroff.1.in
	sed -e 's"/usr/ucblib/doctools/tmac/"$(ROOT)$(MACDIR)/"' \
	    -e 's"/usr/ucblib/doctools/nterm/"$(ROOT)$(TABDIR)/"' \
	    nroff.1.in > $@

draw.o: ../tdef.h ../ext.h
n10.o: n10.c ../tdef.h ../ext.h tw.h pt.h
n6.o: n6.c ../tdef.h tw.h pt.h ../ext.h
hytab.o: ../hytab.c
malloc.o: ../malloc.c ../mallint.h
n1.o: ../n1.c ../tdef.h ../ext.h ./pt.h tw.h
n2.o: ../n2.c ../tdef.h ./pt.h ../ext.h tw.h
n3.o: ../n3.c ../tdef.h ./pt.h ../ext.h tw.h
n4.o: ../n4.c ../tdef.h ./pt.h ../ext.h tw.h
n5.o: ../n5.c ../tdef.h ./pt.h ../ext.h tw.h
n7.o: ../n7.c ../tdef.h ./pt.h ../ext.h tw.h
n8.o: ../n8.c ../tdef.h ../ext.h ./pt.h
n9.o: ../n9.c ../tdef.h ./pt.h ../ext.h tw.h
ni.o: ../ni.c ../tdef.h ./pt.h ./ext.h
nii.o: ../nii.c ../tdef.h ./pt.h ../ext.h tw.h
suftab.o: ../suftab.c
version.o: ../version.c
