#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.69)
AC_INIT(gdbus-example, 1.0, mikebrady@eircom.net)
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall])
AC_CONFIG_SRCDIR([src/service-alarm.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
PKG_PROG_PKG_CONFIG
# Checks for programs.

# Checks for libraries.

PKG_CHECK_MODULES([GIO_UNIX], [gio-unix-2.0 >= 2.30.0],[CFLAGS="${GIO_UNIX_CFLAGS} ${CFLAGS}" LIBS="${GIO_UNIX_LIBS} ${LIBS}"])

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.


AS_AC_EXPAND(DATADIR, $datadir)

DBUS_SERVICES_DIR="$DATADIR/dbus-1/services"
AC_SUBST(DBUS_SERVICES_DIR)
AC_DEFINE_UNQUOTED(DBUS_SERVICES_DIR, "$DBUS_SERVICES_DIR", [Where services dir for DBUS is])


#AM_INIT_AUTOMAKE([subdir-objects -Wall])

# LT_PREREQ([2.2])
# LT_INIT([dlopen])

AC_CONFIG_FILES([Makefile
                 data/Makefile
                 src/Makefile])
AC_OUTPUT
