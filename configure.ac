dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([klavaro],[3.12],[fe20@penso.eu.nom.br])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall tar-ustar])

# Support silent build rules. Disable by either passing
# --disable-silent-rules to configure or passing V=1 to make
AM_SILENT_RULES([yes])

AM_PROG_AR
AM_PROG_LIBTOOL

AC_SEARCH_LIBS([strerror],[cposix])
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_CXX
IT_PROG_INTLTOOL

dnl For Windows, comment out this one (then do an "autoreconf"):
dnl LT_INIT([win32-dll])
dnl For POSIX, simply use this:
LT_INIT

AC_HEADER_STDC
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h unistd.h curl/curl.h gtkdatabox.h])

PKG_CHECK_MODULES(GTKDATABOX, [gtkdatabox >= 1.0.0],,AC_MSG_ERROR([please install GtkDatabox3 found at https://gtkdatabox3.sourceforge.io/]))
AC_CHECK_LIB([gtkdatabox], [gtk_databox_new])
AC_SUBST(GTKDATABOX_CFLAGS)
AC_SUBST(GTKDATABOX_LIBS)

m4_define([gtk_required_version], [3.12.0])
m4_define([pango_required_version], [1.32.4])
m4_define([cairo_required_version], [1.12.0])

PKG_CHECK_MODULES(GTK, [gtk+-3.0 >= [gtk_required_version]])
PKG_CHECK_MODULES(GTK, [gdk-3.0 >= [gtk_required_version]])
PKG_CHECK_MODULES(PANGO, [pango >= [pango_required_version]])
PKG_CHECK_MODULES(CAIRO, [cairo >= [cairo_required_version]])
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

AC_CHECK_LIB([curl], [curl_global_init])
AC_CHECK_LIB([m], [sqrt])

AC_FUNC_STRTOD
AC_CHECK_FUNCS([floor pow memmove memset rint setlocale sqrt strcasecmp strchr strdup strerror strrchr strstr strtoul])

GETTEXT_PACKAGE=klavaro
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package.])
AC_DEFINE(ENABLE_NLS,"1",[enable nls])

AM_CONDITIONAL(IS_WIN, test `uname` = "MINGW64_NT-10.0")
AM_CONDITIONAL(IS_POSIX, test  `uname` != "MINGW64_NT-10.0" -a `uname` != "Darwin")

AC_CONFIG_FILES([Makefile
		src/Makefile
		po/Makefile.in
		doc/Makefile
		data/Makefile
		data/icons/Makefile
		data/icons/hicolor/Makefile
		data/icons/hicolor/16x16/Makefile
		data/icons/hicolor/16x16/apps/Makefile
		data/icons/hicolor/22x22/Makefile
		data/icons/hicolor/22x22/apps/Makefile
		data/icons/hicolor/24x24/Makefile
		data/icons/hicolor/24x24/apps/Makefile
		data/icons/hicolor/32x32/Makefile
		data/icons/hicolor/32x32/apps/Makefile
		data/icons/hicolor/48x48/Makefile
		data/icons/hicolor/48x48/apps/Makefile
		data/icons/hicolor/64x64/Makefile
		data/icons/hicolor/64x64/apps/Makefile
		data/icons/hicolor/96x96/Makefile
		data/icons/hicolor/96x96/apps/Makefile
])
AC_OUTPUT

