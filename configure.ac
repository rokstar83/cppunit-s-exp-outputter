dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.26)

m4_define([cppunit_sexp_outputter_major_version], [0])
m4_define([cppunit_sexp_outputter_minor_version], [1])
m4_define([cppunit_sexp_outputter_version], \
          [cppunit_sexp_outputter_major.cppunit_sexp_outputter_minor_version])

AC_INIT([cppunit-s-exp-outputter],[1.0])
AC_CONFIG_MACRO_DIR([config])
AM_INIT_AUTOMAKE([1.11 dist-bzip2])
AC_LANG([C++])

AC_SUBST(CPPUNIT_SEXP_OUTPUTTER_MAJOR_VERSION, [cppunit_sexp_outputter_major_version])
AC_SUBST(CPPUNIT_SEXP_OUTPUTTER_MINOR_VERSION, [cppunit_sexp_outputter_minor_version])
AC_SUBST(CPPUNIT_SEXP_OUTPUTTER_VERSION, [cppunit_sexp_outputter_version])

dnl Check for programs.

AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_CXX
PKG_CHECK_MODULES([CPPUNIT], [cppunit])
AC_LANG(C++)
AC_PROG_LIBTOOL
AC_LTDL_DLLIB

# Check for standard libraries
AC_CXX_HAVE_STD
AC_CXX_HAVE_STL

AC_CONFIG_FILES([Makefile] [include/Makefile] [src/Makefile])

AC_OUTPUT