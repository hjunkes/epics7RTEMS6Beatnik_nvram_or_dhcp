/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*
 * $Id$
 *
 */

#ifndef osdTimeh
#define osdTimeh

#ifdef __cplusplus
extern "C" {
#endif

int     osdNTPGet(struct timespec *);
void    osdNTPInit(void);
int     sysClkRateGet(void);
int     tickGet(void);

#ifdef __cplusplus
}
#endif
#endif /* ifndef osdTimeh */
