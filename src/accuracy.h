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

#include <plot.h>
#include <glib.h>

#define ACCUR_LOG_FILE "accuracy.log"
#define PROFI_LOG_FILE "proficiency.log"
#define MAX_CHARS_EVALUATED 130
#define MAX_TT_SAVED 30
#define ERROR_INERTIA 10 /* How many correct touchs to eliminate a wrong one (it was 30 first) */
#define ERROR_LIMIT 60   /* How many errors to start a special practice on adaptability */
#define PROFI_LIMIT 2.2  /* How many times the 10th slowest key-touch-time should be relative to the 40th slowest one, 
			    in order to start a special practice on adaptability */ 
#define UTF8_BUFFER 7

void accur_init (void);
void accur_terror_reset (void);
void accur_ttime_reset (void);
void accur_reset (void);
gint accur_terror_n_get (void);
gint accur_ttime_n_get (void);
gchar * accur_terror_char_utf8 (gint i);
gchar * accur_ttime_char_utf8 (gint i);
gulong accur_wrong_get (gint i);
gdouble accur_profi_aver (gint i);
gint accur_profi_aver_norm (gint i);
void accur_correct (gunichar uchr, double touch_time);
void accur_wrong (gunichar uchr);
gulong accur_error_total (void);
void accur_terror_sort (void);
void accur_ttime_sort (void);
void accur_sort (void);
gboolean accur_create_word (gunichar *word);
void accur_close (void);
