# From gtkdatabox git repo, adapted

lib_LTLIBRARIES		= libgtkdataboks.la
libgtkdataboks_la_SOURCES= \
			gtkdatabox.c\
			gtkdatabox_marshal.c\
			gtkdatabox_scale.c\
			gtkdatabox_graph.c\
 			gtkdatabox_points.c\
			gtkdatabox_lines.c\
			gtkdatabox_bars.c\
			gtkdatabox_grid.c\
			gtkdatabox_ruler.c\
			gtkdatabox_xyc_graph.c

libgtkdataboks_la_LDFLAGS= \
			-lgmodule-2.0 \
			@GTK_LIBS@

if IS_WIN
libgtkdataboks_la_LDFLAGS += -no-undefined -export-symbols-regexp '^gtk_databox_'
endif

include_HEADERS		= \
			gtkdatabox_typedefs.h\
			gtkdatabox.h\
			gtkdatabox_marshal.h\
			gtkdatabox_scale.h\
			gtkdatabox_graph.h\
 			gtkdatabox_points.h\
		    	gtkdatabox_lines.h\
		    	gtkdatabox_bars.h\
		    	gtkdatabox_grid.h\
			gtkdatabox_ruler.h\
			gtkdatabox_xyc_graph.h

EXTRA_DIST = gtkdatabox_marshal.list

BUILT_SOURCES = gtkdatabox_marshal.c gtkdatabox_marshal.h

$(srcdir)/gtkdatabox_marshal.c: $(srcdir)/gtkdatabox_marshal.list
	glib-genmarshal --body --prefix=gtk_databox_marshal --internal $< > $@

$(srcdir)/gtkdatabox_marshal.h: $(srcdir)/gtkdatabox_marshal.list
	glib-genmarshal --header --prefix=gtk_databox_marshal --internal $< > $@

AM_CPPFLAGS = \
			-I$(top_srcdir)

AM_CFLAGS =\
			-O2\
			-W -Wall\
			-DG_DISABLE_DEPRECATED\
			-DGDK_DISABLE_DEPRECATED\
			-DGDK_PIXBUF_DISABLE_DEPRECATED\
			-DGTK_DISABLE_DEPRECATED\
			-DGTK_MULTIHEAD_SAFE=1\
			-DGSEAL_ENABLE\
			-DGTK_DISABLE_SINGLE_INCLUDES\
		 	@GTK_CFLAGS@

