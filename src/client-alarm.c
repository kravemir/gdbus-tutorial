
#include "alarm.h"
#include <stdio.h>

GMainLoop *loop;

void notify_activated_callback(Alarm *proxy, gpointer user_data) {
  printf("\"notify_activated_callback\" called with a gpointer of %lx.\n",(int64_t)user_data);
}

void beep_callback(Alarm *proxy, gpointer user_data) {
  int * sample = (int*)user_data;
  printf("\"beeeeeeeeep\" callback called with a sample data item, an integer pointer, pointing to a value of %d.\n",*sample);
  g_main_loop_quit(loop);
}

void main(void) {
  
  int time_interval = 10;

  loop = g_main_loop_new(NULL, FALSE);

  Alarm *proxy;
  GError *error = NULL;

  proxy = alarm_proxy_new_for_bus_sync(G_BUS_TYPE_SESSION, G_DBUS_PROXY_FLAGS_NONE,
                                       "es.aleksander.Alarm", "/es/aleksander/Alarm", NULL, &error);
  g_signal_connect(proxy, "beeeeeeeeep", G_CALLBACK(beep_callback), &time_interval);
  g_signal_connect(proxy, "notify::activated", G_CALLBACK(notify_activated_callback), NULL);
  gboolean result = alarm_call_configure_sync(proxy, time_interval, NULL, &error);
  g_main_loop_run(loop);
  printf("exiting program.\n");
  g_object_unref(proxy);
}
