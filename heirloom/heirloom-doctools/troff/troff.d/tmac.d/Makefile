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
MACS=	acm.me bib chars.me deltext.me e eqn.me \
	float.me footnote.me index.me local.me m mmn mmt ms.acc \
	ms.cov ms.eqn ms.ref ms.tbl ms.ths ms.toc null.me refer.me \
	s sh.me tbl.me thesis.me v vgrind \
	an andoc doc doc-common doc-ditroff doc-nroff doc-syms \
	pictures color pm srefs ptx safe g padj taa naa \
	tmac.gchar an-ext

MAN=	mcolor.7 mpictures.7 man.7 mdoc.7

.SUFFIXES: .in

.in:
	sed 's:@MACDIR@:$(MACDIR):; s:@LIBDIR@:$(LIBDIR):' $< >$@

all: $(MACS) $(MAN)

install: all $(ROOT)$(MACDIR) $(ROOT)$(MANDIR)/man7
	for i in $(MACS); do \
		$(INSTALL) -m 644 $$i $(ROOT)$(MACDIR)/ || exit; \
	done
	for i in $(MAN); do \
		$(INSTALL) -m 644 $$i $(ROOT)$(MANDIR)/man7/ || exit; \
	done

clean:
	rm -f andoc bib doc e g m s pm an doc-ditroff mcolor.7

mrproper: clean

mcolor.7: mcolor.7.in
	sed -e 's"/usr/ucblib/doctools/font/devpost/postscript"$(ROOT)$(PSTDIR)"' \
	    -e 's"/usr/ucblib/doctools/tmac"$(ROOT)$(MACDIR)"' \
	    mcolor.7.in > $@

$(ROOT)$(MACDIR) $(ROOT)$(MANDIR)/man7:
	mkdir -p $@
