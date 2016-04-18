#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <webkit2/webkit2.h>

static void destroy(GtkWidget *widget, gpointer data )
{
  gtk_main_quit();
}

int main(int argc, char **argv)
{
  if(argc != 6) {
    printf("Usage: %s x y width height URL\n");
    return 1;
  }

  const int x = atoi(argv[1]);
  const int y = atoi(argv[2]);
  const int w = atoi(argv[3]);
  const int h = atoi(argv[4]);
  const char *url = argv[5];

  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_POPUP);
  GdkScreen *screen = gtk_window_get_screen(GTK_WINDOW(window));
  GdkVisual *visual = gdk_screen_get_rgba_visual(screen);
  gtk_widget_set_visual(GTK_WIDGET(window), visual);
  gtk_widget_set_app_paintable(GTK_WIDGET(window), TRUE);

  gtk_window_set_title(GTK_WINDOW(window), "vandal");
  gtk_window_set_type_hint(GTK_WINDOW(window), GDK_WINDOW_TYPE_HINT_DESKTOP);
  gtk_window_set_default_size(GTK_WINDOW(window), w, h);
  gtk_window_set_skip_taskbar_hint(GTK_WINDOW(window), TRUE);
  gtk_window_set_skip_pager_hint(GTK_WINDOW(window), TRUE);
  gtk_window_set_accept_focus(GTK_WINDOW(window), FALSE);
  gtk_window_set_focus_on_map(GTK_WINDOW(window), FALSE);
  gtk_window_move(GTK_WINDOW(window), x, y);

  gtk_window_stick(GTK_WINDOW(window));


  GtkWidget *webview = webkit_web_view_new();
  webkit_web_view_load_uri((WebKitWebView*)webview, url);
  GdkRGBA trs = {1.0, 1.0, 1.0, 0.0};
  webkit_web_view_set_background_color((WebKitWebView*)webview, &trs);

  g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

  gtk_container_add(GTK_CONTAINER(window), webview);
  gtk_widget_show(webview);
  gtk_widget_show(window);

  GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));

  gdk_window_lower(gdk_window);

  gtk_main();

  return 0;
}
