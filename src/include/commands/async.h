/*-------------------------------------------------------------------------
 *
 * async.h
 *	  Asynchronous notification: NOTIFY, LISTEN, UNLISTEN
 *
 * Portions Copyright (c) 1996-2000, PostgreSQL, Inc
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $Id: async.h,v 1.15 2000/08/27 19:00:41 petere Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef ASYNC_H
#define ASYNC_H

extern bool Trace_notify;

/* notify-related SQL statements */
extern void Async_Notify(char *relname);
extern void Async_Listen(char *relname, int pid);
extern void Async_Unlisten(char *relname, int pid);

/* perform (or cancel) outbound notify processing at transaction commit */
extern void AtCommit_Notify(void);
extern void AtAbort_Notify(void);

/* signal handler for inbound notifies (SIGUSR2) */
extern void Async_NotifyHandler(int signum);

/*
 * enable/disable processing of inbound notifies directly from signal handler.
 * The enable routine first performs processing of any inbound notifies that
 * have occurred since the last disable.  These are meant to be called ONLY
 * from the appropriate places in PostgresMain().
 */
extern void EnableNotifyInterrupt(void);
extern void DisableNotifyInterrupt(void);

#endif	 /* ASYNC_H */
