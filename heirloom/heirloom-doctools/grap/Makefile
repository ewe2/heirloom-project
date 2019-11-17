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
OBJ = coord.o for.o frame.o grap.o grapl.o input.o label.o main.o misc.o \
	plot.o print.o ticks.o version.o

FLAGS = -DLIBDIR='"$(LIBDIR)"' $(DEFINES) -I../include

YFLAGS = -d

.c.o:
	$(CC) $(_CFLAGS) $(FLAGS) -c $<

all: grap.c grapl.c grap grap.1

grap: $(OBJ)
	$(CC) $(_CFLAGS) $(_LDFLAGS) $(OBJ) $(LIBS) -lm -o grap

y.tab.h: grap.c

install:
	$(INSTALL) -c grap $(ROOT)$(BINDIR)/grap
	$(STRIP) $(ROOT)$(BINDIR)/grap
	test -d $(ROOT)$(LIBDIR) || mkdir -p $(ROOT)$(LIBDIR)
	$(INSTALL) -c -m 644 grap.defines $(ROOT)$(LIBDIR)/grap.defines
	$(INSTALL) -c -m 644 grap.1 $(ROOT)$(MANDIR)/man1/grap.1

clean:
	rm -f $(OBJ) grapl.c grap.c y.tab.h grap core log *~ grap.1

mrproper: clean

grap.1: grap.1.in
	sed 's"/usr/ucblib/"$(ROOT)$(LIBDIR)/"' grap.1.in > $@

coord.o: coord.c grap.h y.tab.h
for.o: for.c grap.h y.tab.h
frame.o: frame.c grap.h y.tab.h
grap.o: grap.c grap.h
grapl.o: grapl.c grap.h y.tab.h
input.o: input.c grap.h y.tab.h
label.o: label.c grap.h y.tab.h
main.o: main.c grap.h y.tab.h
misc.o: misc.c grap.h y.tab.h
plot.o: plot.c grap.h y.tab.h
print.o: print.c grap.h y.tab.h
ticks.o: ticks.c grap.h y.tab.h
