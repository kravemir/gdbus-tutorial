bin_PROGRAMS = service-alarm client-alarm

client_alarm_SOURCES = alarm.c alarm.h client-alarm.c

service_alarm_SOURCES = alarm.c alarm.h service-alarm.c

BUILT_SOURCES = alarm.h alarm.c
# We don't want to install this header
noinst_HEADERS = $(BUILT_SOURCES)

# Correctly clean the generated headers, but keep the xml description
CLEANFILES = $(BUILT_SOURCES)
EXTRA_DIST = es.aleksander.Alarm.xml

#Rule to generate the binding headers
alarm.h:  es.aleksander.Alarm.xml
	gdbus-codegen --interface-prefix es.aleksander --generate-c-code alarm es.aleksander.Alarm.xml

alarm.c:  es.aleksander.Alarm.xml
	gdbus-codegen --interface-prefix es.aleksander --generate-c-code alarm es.aleksander.Alarm.xml

