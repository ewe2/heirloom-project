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
OBJ = regexp.o vfontedpr.o vgrindefs.o version.o

FLAGS = $(EUC) -DLIBDIR='"$(LIBDIR)"' $(DEFINES) -I../include

.c.o:
	$(CC) $(_CFLAGS) $(FLAGS) -c $<

all: vgrind vfontedpr vgrind.1

vfontedpr: $(OBJ)
	$(CC) $(_CFLAGS) $(_LDFLAGS) $(OBJ) $(LIBS) -o vfontedpr

vgrind: vgrind.sh
	rm -f $@
	echo "#!$(SHELL)" >>$@
	echo "_TROFF=$(BINDIR)/troff" >>$@
	echo "_VFONTEDPR=$(LIBDIR)/vfontedpr" >>$@
	echo "_TMAC_VGRIND=$(MACDIR)/vgrind" >>$@
	echo "_DPOST=$(BINDIR)/dpost" >>$@
	cat vgrind.sh >>$@
	chmod 755 $@

install:
	$(INSTALL) -c vgrind $(ROOT)$(BINDIR)/vgrind
	test -d $(ROOT)$(LIBDIR) || mkdir -p $(ROOT)$(LIBDIR)
	$(INSTALL) -c vfontedpr $(ROOT)$(LIBDIR)/vfontedpr
	$(STRIP) $(ROOT)$(LIBDIR)/vfontedpr
	$(INSTALL) -c -m 644 vgrindefs.src $(ROOT)$(LIBDIR)/vgrindefs
	$(INSTALL) -c -m 644 vgrind.1 $(ROOT)$(MANDIR)/man1/vgrind.1

clean:
	rm -f $(OBJ) vfontedpr vgrind retest retest.o core log *~ vgrind.1

mrproper: clean

vgrind.1: vgrind.1.in
	sed -e 's"/usr/ucblib/tmac/"$(ROOT)$(MACDIR)/"' \
	    -e 's"/usr/ucblib/"$(ROOT)$(LIBDIR)/"' vgrind.1.in > $@
