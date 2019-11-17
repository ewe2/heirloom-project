/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)pt.h	1.54 (gritter) 8/19/08
 */

/*
 * Portions copyright 2017 Roy Fisher
 */

/* t6.c */
extern int	width(register tchar);
extern void	zapwcache(int);
extern int	getcw(register int);
extern int	abscw(int);
extern int	onfont(tchar);
extern int	getascender(void);
extern int	getdescender(void);
extern int	kernadjust(tchar, tchar);
extern void	xbits(register tchar, int);
extern tchar	setch(int);
extern tchar	setabs(void);
extern int	findft(register int, int);
extern void	caseps(void);
extern void	casps1(register int);
extern int	findps(register int);
extern void	mchbits(void);
extern void	setps(void);
extern tchar	setht(void);
extern tchar	setslant(void);
extern void	caseft(void);
extern void	setfont(int);
extern void	setwd(void);
extern tchar	vmot(void);
extern tchar	hmot(void);
extern tchar	mot(void);
extern tchar	sethl(int);
extern tchar	makem(register int);
extern tchar	getlg(tchar);
extern int	strlg(int, int *, int);
extern void	caselg(void);
extern void	caseflig(int);
extern void	casefdeferlig(void);
extern void	casefp(int);
extern void	casefps(void);
extern int	setfp(int, int, char *);
extern int	nextfp(void);
extern void	casecs(void);
extern void	casebd(void);
extern void	casevs(void);
extern void	casess(int);
extern void	caseminss(void);
extern void	caseletadj(void);
extern void	casefspacewidth(void);
extern void	casespacewidth(void);
extern tchar	xlss(void);
extern void	casetrack(void);
extern void	casefallback(void);
extern void	casehidechar(void);
extern void	casefzoom(void);
extern double	getfzoom(void);
extern void	casekern(void);
extern void	casefkern(void);
extern void	casepapersize(void);
extern void	casemediasize(void);
extern void	casetrimat(void);
extern void	casebleedat(void);
extern void	casecropat(void);
extern void	caselhang(void);
extern void	caserhang(void);
extern void	casekernpair(void);
extern void	casekernafter(void);
extern void	casekernbefore(void);
extern void	caseftr(void);
extern void	casefeature(void);
extern int	un2tr(int, int *);
extern int	tr2un(tchar, int);
extern tchar	setuc0(int);
extern tchar	setanchor(void);
extern tchar	setlink(void);
extern tchar	setulink(void);
extern int	pts2u(int);
extern double	u2pts(int);
/* t10.c */
extern void	ptinit(void);
extern void	specnames(void);
extern int	findch(register const char *);
void	ptout(register tchar);
extern tchar	*ptout0(tchar *, tchar *);
extern void	ptps(void);
extern void	ptfont(void);
extern void	ptfpcmd(int, const char *, char *, int);
extern void	ptlead(void);
extern void	ptesc(void);
extern void	newpage(int);
extern void	ptsupplyfont(char *, char *);
extern void	ptlocale(const char *);
extern void	pttrailer(void);
extern void	ptstop(void);
extern void	dostop(void);
/* t6.c typo additions - rwf */
extern void	caseadjlapenalty(void);
extern void	caseadjpenalty(void);
extern void	caseelpchar(void) ;
extern void	caseelppen(void) ;
extern void	caseexhyp(void) ;
extern void	caselastlinestretch(void) ;
extern void	caseletcalc(void) ;
extern void	caseletpen(void) ;
extern void	caseletshp(void);
extern void	caseletspc(void);
extern void	caseletstren(void) ;
extern void	caseletthresh(void) ;
extern void	caselinepenalty(void) ;
extern void	caselooseness(void) ;
extern void	caseoverrunpenalty(void) ;
extern void	casewrdspc(void);
extern void	casewscalc(void) ;
extern void	casewsmark(void) ;
extern void	casewsmin(void) ;
extern void	casewswarn(void) ;
extern void	caserhanglevel(void) ;
