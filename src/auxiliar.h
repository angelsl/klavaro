/**************************************************************************/
/*  Klavaro - a flexible touch typing tutor                               */
/*  Copyright (C) from 2005 until 2008 Felipe Castro                      */
/*  Copyright (C) from 2009 until 2019 The Free Software Foundation       */
/*                                                                        */
/*  This program is free software, licensed under the terms of the GNU    */
/*  General Public License as published by the Free Software Foundation,  */
/*  either version 3 of the License, or (at your option) any later        */
/*  version. You should have received a copy of the GNU General Public    */
/*  License along with this program. If not,                              */
/*  see <https://www.gnu.org/licenses/>.                                  */
/**************************************************************************/

#include <glib.h>
#include <gtk/gtk.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (PACKAGE, String)
#  define Q_(String) g_strip_context ((String), gettext (String))
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dngettext(Domain,Message,Message2,N) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define Q_(String) g_strip_context ((String), (String))
#  define N_(String) (String)
#endif

/* Public Functions.
 */

GObject * get_obj (gchar *name);

GtkWidget * get_wg (gchar *name);

GtkWindow * get_win (gchar *name);

void set_wg_bg_color (GtkWidget *widget, gchar *bg_color);

void set_pixmap (gchar *widget, gchar *image);

/* Search for the user directory and create it if not found
 */
void assert_user_dir (void);

/* Compare two strings, so that it applies to other sorting functions.
 */
gint compare_string_function (gconstpointer a, gconstpointer b);
