/*****************************************************************************/ 
/* SexpOutputter.hh                                                          */
/* Copyright (c) 2013 Thomas Hartman (rokstar83@gmail.com)                   */
/*                                                                           */
/* This program is free software; you can redistribute it and/or             */
/* modify it under the terms of the GNU General Public License               */
/* as published by the Free Software Foundation; either version 2            */
/* of the License, or the License, or (at your option) any later             */
/* version.                                                                  */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*****************************************************************************/
#ifndef SEXPOUTPUTTER_HH_
#define SEXPOUTPUTTER_HH_

#include <list>
#include <cppunit/Outputter.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/portability/Stream.h>
#include <cppunit/portability/CppUnitMap.h>
#include <string>
#include <list>

CPPUNIT_NS_BEGIN

class TestResultCollector;

class CPPUNIT_API SexpOutputter : public Outputter
{
public:
SexpOutputter(TestResultCollector * result, OStream &stream);
virtual ~SexpOutputter();

typedef CppUnitMap<Test *,TestFailure*, std::less<Test*> > FailedTests;

virtual void write();

private:
TestResultCollector * _result;
OStream & _stream;

private:
/* disable copy and assignment operator */
SexpOutputter(const SexpOutputter & copy);
void operator =(const SexpOutputter & copy);

};

CPPUNIT_NS_END

#endif /* SEXPOUTPUTTER_HH_ */
