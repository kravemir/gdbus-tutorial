
#include "alarm.h"
#include <stdio.h>

static gboolean emit_alarm_cb(gpointer skeleton) {
  alarm_emit_beeeeeeeeep(ALARM(skeleton));
  alarm_set_activated(ALARM(skeleton), FALSE);
  return FALSE;
}

static gboolean on_handle_configure(Alarm *skeleton, GDBusMethodInvocation *invocation,
                                    guint seconds) {
  if (alarm_get_activated(skeleton)) {
    g_dbus_method_invocation_return_error_literal(invocation, G_IO_ERROR, G_IO_ERROR_EXISTS,
                                                  "Exists");
    return FALSE;
  }

  alarm_set_activated(skeleton, TRUE);
  g_timeout_add_seconds(seconds, emit_alarm_cb, skeleton);
  alarm_complete_configure(skeleton, invocation);
  printf("Alarm set for %d seconds.\n", seconds);
  return TRUE;
}

static void on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data) {
  Alarm *skeleton;

  skeleton = alarm_skeleton_new();
  g_signal_connect(skeleton, "handle-configure", G_CALLBACK(on_handle_configure), NULL);

  g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton), connection,
                                   "/es/aleksander/Alarm", NULL);
}

void main(void) {
  GMainLoop *loop;

  loop = g_main_loop_new(NULL, FALSE);

  g_bus_own_name(G_BUS_TYPE_SESSION, "es.aleksander.Alarm", G_BUS_NAME_OWNER_FLAGS_NONE, NULL,
                 on_name_acquired, NULL, NULL, NULL);

  g_main_loop_run(loop);
}
