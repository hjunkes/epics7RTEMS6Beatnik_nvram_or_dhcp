#ifndef osiSemh
#define osiSemh

#include "epicsAssert.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "shareLib.h"

typedef void *semBinaryId;
typedef enum {semTakeOK,semTakeTimeout,semTakeError} semTakeStatus;
typedef enum {semEmpty,semFull} semInitialState;

epicsShareFunc semBinaryId epicsShareAPI semBinaryCreate(
    semInitialState initialState);
epicsShareFunc semBinaryId epicsShareAPI semBinaryMustCreate (
    semInitialState initialState);
epicsShareFunc void epicsShareAPI semBinaryDestroy(semBinaryId id);
epicsShareFunc void epicsShareAPI semBinaryGive(semBinaryId id);
epicsShareFunc semTakeStatus epicsShareAPI semBinaryTake(semBinaryId id);
#define semBinaryMustTake(ID) assert((semBinaryTake ((ID))==semTakeOK))
epicsShareFunc semTakeStatus epicsShareAPI semBinaryTakeTimeout(
    semBinaryId id, double timeOut);
epicsShareFunc semTakeStatus epicsShareAPI semBinaryTakeNoWait(semBinaryId id);
epicsShareFunc void epicsShareAPI semBinaryShow(semBinaryId id, unsigned int level);

typedef void *semMutexId;
epicsShareFunc semMutexId epicsShareAPI semMutexCreate(void);
epicsShareFunc semMutexId epicsShareAPI semMutexMustCreate (void);
epicsShareFunc void epicsShareAPI semMutexDestroy(semMutexId id);
epicsShareFunc void epicsShareAPI semMutexGive(semMutexId id);
epicsShareFunc semTakeStatus epicsShareAPI semMutexTake(semMutexId id);
#define semMutexMustTake(ID) assert((semMutexTake((ID))==semTakeOK))
epicsShareFunc semTakeStatus epicsShareAPI semMutexTakeTimeout(
    semMutexId id, double timeOut);
epicsShareFunc semTakeStatus epicsShareAPI semMutexTakeNoWait(semMutexId id);
epicsShareFunc void epicsShareAPI semMutexShow(semMutexId id,unsigned  int level);

/*NOTES:
    Mutex semaphores MUST implement recursive locking
    Mutex semaphores should implement priority inheritance and deletion safe
*/

#ifdef __cplusplus
}
#endif

#include "osdSem.h"

#endif /* osiSemh */
