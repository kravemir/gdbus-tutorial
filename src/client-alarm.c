
#include "alarm.h"
#include <stdio.h>

GMainLoop *loop;

void sample_callback(void) { printf("\"notify\" callback called.\n"); }

void beep_callback(void) {
  printf("\"beeeeeeeeep\" callback called.\n");
  g_main_loop_quit(loop);
}

void main(void) {

  loop = g_main_loop_new(NULL, FALSE);

  Alarm *proxy;
  GError *error = NULL;

  proxy = alarm_proxy_new_for_bus_sync(G_BUS_TYPE_SESSION, G_DBUS_PROXY_FLAGS_NONE,
                                       "es.aleksander.Alarm", "/es/aleksander/Alarm", NULL, &error);

  g_signal_connect(proxy, "beeeeeeeeep", beep_callback, NULL);
  g_signal_connect(proxy, "notify", sample_callback, NULL);

  gboolean result = alarm_call_configure_sync(proxy, 5, NULL, &error);

  g_main_loop_run(loop);

  printf("exiting program.\n");
  g_object_unref(proxy);
}
