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
OBJ = diacrit.o e.o eqnbox.o font.o fromto.o funny.o glob.o integral.o \
	io.o lex.o lookup.o mark.o matrix.o move.o over.o paren.o pile.o \
	shift.o size.o sqrt.o text.o version.o

FLAGS = -I. -I.. -I../../include $(DEFINES)

.c.o:
	$(CC) $(_CFLAGS) $(FLAGS) -c $<

all: eqn eqnchar.7

eqn: $(OBJ)
	$(CC) $(_CFLAGS) $(_LDFLAGS) $(OBJ) $(LIBS) -o eqn

e.c: e.y
	$(YACC) -d ../e.y
	sed -f ../yyval.sed <y.tab.c >$@

y.tab.h: e.c

install:
	test -d $(ROOT)$(BINDIR) || mkdir -p $(ROOT)$(BINDIR)
	$(INSTALL) -c eqn $(ROOT)$(BINDIR)/eqn
	$(STRIP) $(ROOT)$(BINDIR)/eqn
	test -d $(ROOT)$(MANDIR)/man1 || mkdir -p $(ROOT)$(MANDIR)/man1
	test -d $(ROOT)$(MANDIR)/man7 || mkdir -p $(ROOT)$(MANDIR)/man7
	$(INSTALL) -c -m 644 eqn.1 $(ROOT)$(MANDIR)/man1/eqn.1
	$(INSTALL) -c -m 644 eqnchar.7 $(ROOT)$(MANDIR)/man7/eqnchar.7

clean:
	rm -f $(OBJ) eqn e.c y.tab.* core log *~ eqnchar.7

mrproper: clean

eqnchar.7: eqnchar.7.in
	sed 's"/usr/pub/"$(ROOT)$(PUBDIR)/"' eqnchar.7.in > $@

diacrit.o: ../diacrit.c ../e.h y.tab.h
eqnbox.o: ../eqnbox.c ../e.h y.tab.h
font.o: ../font.c ../e.h y.tab.h
fromto.o: ../fromto.c ../e.h y.tab.h
funny.o: ../funny.c ../e.h y.tab.h
glob.o: ../glob.c ../e.h
integral.o: ../integral.c ../e.h y.tab.h
io.o: ../io.c ../e.h
lex.o: ../lex.c ../e.h y.tab.h
lookup.o: ../lookup.c ../e.h y.tab.h
mark.o: ../mark.c ../e.h y.tab.h
matrix.o: ../matrix.c ../e.h y.tab.h
move.o: ../move.c ../e.h y.tab.h
over.o: ../over.c ../e.h y.tab.h
paren.o: ../paren.c ../e.h y.tab.h
pile.o: ../pile.c ../e.h y.tab.h
shift.o: ../shift.c ../e.h y.tab.h
size.o: ../size.c ../e.h y.tab.h
sqrt.o: ../sqrt.c ../e.h y.tab.h
text.o: ../text.c ../e.h y.tab.h
e.o: e.c ../e.h
