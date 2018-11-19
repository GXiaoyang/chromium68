/*
 * pmtrace_bundle_provider.h
 *
 * Tracepoint provider file for LTTng UST tracing in palmsystem-injection
 *
 * For more information on see:
 *    http://lttng.org/files/doc/man-pages/man3/lttng-ust.3.html
 *
 * The application level API to these tracepoints is in WebAppMgrBundleTracer.h
 *
 * Copyright (c) 2015 LG Electronics, Inc.
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER pmtrace_bundle

#undef TRACEPOINT_INCLUDE_FILE
#define TRACEPOINT_INCLUDE_FILE ./pmtrace_bundle_provider.h

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus */

#if !defined(_PMTRACE_BUNDLE_PROVIDER_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _PMTRACE_BUNDLE_PROVIDER_H

#include <lttng/tracepoint.h>

/* "message" tracepoint should be used for single event trace points */
TRACEPOINT_EVENT(
    pmtrace_bundle,
    message,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))
/* "item" tracepoint should be used for name/value pairs */
TRACEPOINT_EVENT(
    pmtrace_bundle,
    item,
    TP_ARGS(char*, text1, char*, text2),
    TP_FIELDS(ctf_string(name, text1) ctf_string(value, text2)))
/* "before"/"after" tracepoint should be used for measuring the
   duration of something that doesn't correspond with a function call or scope */
TRACEPOINT_EVENT(
    pmtrace_bundle,
    before,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))
TRACEPOINT_EVENT(
    pmtrace_bundle,
    after,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))
/* "scope_entry"/"scope_exit" tracepoints should be used only by
   PmtraceTraceScope class to measure the duration of a scope within
   a function in C++ code. In C code these may be used directly for
   the same purpose, just make sure you trace any early exit from the
   scope such as break statements or gotos.  */
TRACEPOINT_EVENT(
    pmtrace_bundle,
    scope_entry,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))
TRACEPOINT_EVENT(
    pmtrace_bundle,
    scope_exit,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))
/* "function_entry"/"function_exit" tracepoints should be used only by
   PmtraceTraceFunction class to measure the duration of a function
   in C++ code. In C code it may be used directly for the same
   purpose, just make sure you capture any early exit from the
   function such as return statements. */
TRACEPOINT_EVENT(
    pmtrace_bundle,
    function_entry,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))
TRACEPOINT_EVENT(
    pmtrace_bundle,
    function_exit,
    TP_ARGS(char*, text),
    TP_FIELDS(ctf_string(scope, text)))

#endif /* _PMTRACE_BUNDLE_PROVIDER_H */

#include <lttng/tracepoint-event.h>

#ifdef __cplusplus
}
#endif /*__cplusplus */

