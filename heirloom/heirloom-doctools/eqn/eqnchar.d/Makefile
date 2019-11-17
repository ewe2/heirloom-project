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
FILES = ascii eqnchar greek iso utf-8

.c.o:
	$(CC) $(_CFLAGS) $(EUC) -c $<

all: $(FILES)

utf-8: genutf8
	-./genutf8 >utf-8

genutf8: genutf8.o
	-$(CC) $(_CFLAGS) $(_LDFLAGS) genutf8.o $(LIBS) -o genutf8

genutf8.o: genutf8.c
	-$(CC) $(_CFLAGS) $(EUC) -c genutf8.c

install: all
	test -d $(ROOT)$(PUBDIR) || mkdir -p $(ROOT)$(PUBDIR)
	for i in $(FILES); \
	do \
		test -s $$i || continue; \
		$(INSTALL) -c -m 644 $$i $(ROOT)$(PUBDIR)/$$i || exit; \
	done

clean:
	rm -f utf-8 genutf8 genutf8.o core log *~

mrproper: clean
