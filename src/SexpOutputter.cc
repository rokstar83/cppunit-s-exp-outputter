/*****************************************************************************/ 
/* SexpOutputter.cc                                                          */
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
#include "SexpOutputter.hh"
#include <cppunit/Test.h>
#include <cppunit/TestFailure.h>
#include <cppunit/Exception.h>

CPPUNIT_NS_BEGIN

SexpOutputter::SexpOutputter( TestResultCollector * result, OStream &stream ) :
   _result(result), _stream(stream)
{
}

SexpOutputter::~SexpOutputter()
{
}

void SexpOutputter::write()
{
   _stream << "(";
   
   const TestResultCollector::TestFailures &failures = _result->failures();
   TestResultCollector::TestFailures::const_iterator itFailure = failures.begin();

   FailedTests failedTests;
   while(itFailure != failures.end()) {
      TestFailure * failure = *itFailure++;
      failedTests.insert(std::pair<Test* const, TestFailure*>(failure->failedTest(), failure));
   }

   const TestResultCollector::Tests &tests = _result->tests();
   for(unsigned int x = 0; x < tests.size(); ++x) {      
      Test * test = tests[x];
      _stream << "(";
      if(failedTests.find(test) != failedTests.end()) {
         _stream << "\"" << test->getName() << "\"" << " " << "'success";
      } else {
         SourceLine sourceLine = failedTests[test]->sourceLine();
         _stream << test->getName() << " " << (failedTests[test]->isError() ?
                                               "'error" : "'failed");
         if(failedTests[test]->sourceLine().isValid()) {
            _stream << "('file \"" << sourceLine.fileName() << "\")";
            _stream << "('line \"" << sourceLine.lineNumber() << "\")";
         }
         _stream << "('message \"" << failedTests[test]->thrownException()->what() << "\")";
      }
      _stream << ")";
   }
   _stream << ")";
}

CPPUNIT_NS_END
