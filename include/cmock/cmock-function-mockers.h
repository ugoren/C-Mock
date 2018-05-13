// This file was GENERATED by command:
//     pump.py cmock-function-mockers.h.pump
// (pump.py can be found in googletest/scripts)
// DO NOT EDIT BY HAND!!!

// Copyright 2013, Hubert Jagodziński
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: hubert.jagodzinski@gmail.com (Hubert Jagodziński)

// C Mock - extension to Google Mock framework allowing for writing C mock
// functions.
//
// This file implements C function mockers of various arities.

#ifndef CMOCK_INCLUDE_CMOCK_CMOCK_FUNCTION_MOCKERS_H_
#define CMOCK_INCLUDE_CMOCK_CMOCK_FUNCTION_MOCKERS_H_

#include <dlfcn.h>

#include <sstream>
#include <stdexcept>

#define DECLARE_FUNCTION_MOCK0(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(); \
        ::testing::MockSpec<F>& cmock_func(); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(); \
};

#define IMPLEMENT_FUNCTION_MOCK0(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()() { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 0, \
     this_method_does_not_take_0_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(); \
} \
\
::testing::MockSpec<F>& c::cmock_func() { \
    mocker.RegisterOwner(this); \
    return mocker.With(); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call() { \
    if (instance != NULL) { \
        return (*instance)(); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n() { \
    return c::call(); \
}

#define DECLARE_FUNCTION_MOCK1(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1); \
};

#define IMPLEMENT_FUNCTION_MOCK1(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 1, \
     this_method_does_not_take_1_argument); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1) { \
    return c::call(cmock_a1); \
}

#define DECLARE_FUNCTION_MOCK2(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2); \
};

#define IMPLEMENT_FUNCTION_MOCK2(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 2, \
     this_method_does_not_take_2_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2) { \
    return c::call(cmock_a1, cmock_a2); \
}

#define DECLARE_FUNCTION_MOCK3(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, \
            F) cmock_a3); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3); \
};

#define IMPLEMENT_FUNCTION_MOCK3(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 3, \
     this_method_does_not_take_3_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3); \
}

#define DECLARE_FUNCTION_MOCK4(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4); \
};

#define IMPLEMENT_FUNCTION_MOCK4(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
    F) cmock_a4) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 4, \
     this_method_does_not_take_4_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
    F) cmock_a4) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
    F) cmock_a4) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4); \
}

#define DECLARE_FUNCTION_MOCK5(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, \
            F) cmock_a5); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5); \
};

#define IMPLEMENT_FUNCTION_MOCK5(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 5, \
     this_method_does_not_take_5_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5); \
}

#define DECLARE_FUNCTION_MOCK6(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
        GMOCK_ARG_(, 6, F) cmock_a6); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
            GMOCK_MATCHER_(, 6, F) cmock_a6); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
            F) cmock_a6); \
};

#define IMPLEMENT_FUNCTION_MOCK6(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 6, \
     this_method_does_not_take_6_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
         cmock_a6); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
    GMOCK_MATCHER_(, 6, F) cmock_a6) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, cmock_a6); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6); \
}

#define DECLARE_FUNCTION_MOCK7(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
        GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
            GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, \
            F) cmock_a7); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
            F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7); \
};

#define IMPLEMENT_FUNCTION_MOCK7(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 7, \
     this_method_does_not_take_7_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
         cmock_a6, cmock_a7); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
    GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, cmock_a6, \
        cmock_a7); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7); \
}

#define DECLARE_FUNCTION_MOCK8(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
        GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
        GMOCK_ARG_(, 8, F) cmock_a8); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
            GMOCK_ARG_(, 8, F) cmock_a8); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
            GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7, \
            GMOCK_MATCHER_(, 8, F) cmock_a8); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
            GMOCK_ARG_(, 8, F) cmock_a8); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
            F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, GMOCK_ARG_(, 8, \
            F) cmock_a8); \
};

#define IMPLEMENT_FUNCTION_MOCK8(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 8, \
     this_method_does_not_take_8_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
         cmock_a6, cmock_a7, cmock_a8); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
    GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7, \
    GMOCK_MATCHER_(, 8, F) cmock_a8) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7, cmock_a8); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7, cmock_a8); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, cmock_a6, \
        cmock_a7, cmock_a8); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7, cmock_a8); \
}

#define DECLARE_FUNCTION_MOCK9(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
        GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
        GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
            GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
            GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7, \
            GMOCK_MATCHER_(, 8, F) cmock_a8, GMOCK_MATCHER_(, 9, \
            F) cmock_a9); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
            GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
            F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, GMOCK_ARG_(, 8, \
            F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9); \
};

#define IMPLEMENT_FUNCTION_MOCK9(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, \
    F) cmock_a9) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 9, \
     this_method_does_not_take_9_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
         cmock_a6, cmock_a7, cmock_a8, cmock_a9); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
    GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7, \
    GMOCK_MATCHER_(, 8, F) cmock_a8, GMOCK_MATCHER_(, 9, F) cmock_a9) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7, cmock_a8, cmock_a9); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, \
    F) cmock_a9) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7, cmock_a8, cmock_a9); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, cmock_a6, \
        cmock_a7, cmock_a8, cmock_a9); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, \
    F) cmock_a9) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7, cmock_a8, cmock_a9); \
}

#define DECLARE_FUNCTION_MOCK10(c, n, F) \
class c \
{ \
    typedef GMOCK_RESULT_(, F) (*func_type)(GMOCK_ARG_(, 1, F) cmock_a1, \
        GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
        GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
        GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
        GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
        GMOCK_ARG_(, 10, F) cmock_a10); \
\
    public: \
        static func_type real; \
\
        c(); \
        ~c(); \
\
        GMOCK_RESULT_(, F) operator()(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
            GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
            GMOCK_ARG_(, 10, F) cmock_a10); \
        ::testing::MockSpec<F>& cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
            GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
            GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
            GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7, \
            GMOCK_MATCHER_(, 8, F) cmock_a8, GMOCK_MATCHER_(, 9, F) cmock_a9, \
            GMOCK_MATCHER_(, 10, F) cmock_a10); \
\
    private: \
        static func_type lookup(); \
        static GMOCK_RESULT_(, F) call(GMOCK_ARG_(, 1, F) cmock_a1, \
            GMOCK_ARG_(, 2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, \
            GMOCK_ARG_(, 4, F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, \
            GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, \
            GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
            GMOCK_ARG_(, 10, F) cmock_a10); \
\
        static c *instance; \
\
        ::testing::FunctionMocker<F> mocker; \
\
        friend GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, \
            2, F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, \
            F) cmock_a4, GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, \
            F) cmock_a6, GMOCK_ARG_(, 7, F) cmock_a7, GMOCK_ARG_(, 8, \
            F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, GMOCK_ARG_(, 10, \
            F) cmock_a10); \
};

#define IMPLEMENT_FUNCTION_MOCK10(c, n, F) \
c::c() { \
    instance = this; \
} \
\
c::~c() { \
    instance = NULL; \
} \
\
GMOCK_RESULT_(, F) c::operator()(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
    GMOCK_ARG_(, 10, F) cmock_a10) { \
    GTEST_COMPILE_ASSERT_(::std::tr1::tuple_size< \
    ::testing::internal::Function<F>::ArgumentTuple>::value == 10, \
     this_method_does_not_take_10_arguments); \
     mocker.SetOwnerAndName(this, #n); \
     return mocker.Invoke(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
         cmock_a6, cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
} \
\
::testing::MockSpec<F>& c::cmock_func(GMOCK_MATCHER_(, 1, F) cmock_a1, \
    GMOCK_MATCHER_(, 2, F) cmock_a2, GMOCK_MATCHER_(, 3, F) cmock_a3, \
    GMOCK_MATCHER_(, 4, F) cmock_a4, GMOCK_MATCHER_(, 5, F) cmock_a5, \
    GMOCK_MATCHER_(, 6, F) cmock_a6, GMOCK_MATCHER_(, 7, F) cmock_a7, \
    GMOCK_MATCHER_(, 8, F) cmock_a8, GMOCK_MATCHER_(, 9, F) cmock_a9, \
    GMOCK_MATCHER_(, 10, F) cmock_a10) { \
    mocker.RegisterOwner(this); \
    return mocker.With(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
} \
\
c::func_type c::lookup() { \
    return (c::func_type)dlsym(RTLD_NEXT, #n); \
} \
\
GMOCK_RESULT_(, F) c::call(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
    GMOCK_ARG_(, 10, F) cmock_a10) { \
    if (instance != NULL) { \
        return (*instance)(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
            cmock_a6, cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
    } \
\
    if (real == NULL) { \
        std::ostringstream msg; \
        msg << "Error: Function " << #n; \
        msg << " not found - both mock and real function are missing"; \
        throw std::logic_error(msg.str()); \
    } \
    return real(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, cmock_a6, \
        cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
} \
\
c *c::instance = NULL; \
c::func_type c::real = lookup(); \
\
GMOCK_RESULT_(, F) n(GMOCK_ARG_(, 1, F) cmock_a1, GMOCK_ARG_(, 2, \
    F) cmock_a2, GMOCK_ARG_(, 3, F) cmock_a3, GMOCK_ARG_(, 4, F) cmock_a4, \
    GMOCK_ARG_(, 5, F) cmock_a5, GMOCK_ARG_(, 6, F) cmock_a6, GMOCK_ARG_(, 7, \
    F) cmock_a7, GMOCK_ARG_(, 8, F) cmock_a8, GMOCK_ARG_(, 9, F) cmock_a9, \
    GMOCK_ARG_(, 10, F) cmock_a10) { \
    return c::call(cmock_a1, cmock_a2, cmock_a3, cmock_a4, cmock_a5, \
        cmock_a6, cmock_a7, cmock_a8, cmock_a9, cmock_a10); \
}

#endif // CMOCK_INCLUDE_CMOCK_CMOCK_FUNCTION_MOCKERS_H_
