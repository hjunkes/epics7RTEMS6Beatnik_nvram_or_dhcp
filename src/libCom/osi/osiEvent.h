
/* 
 * $Id$
 * 
 *
 * Author: Jeff Hill
 *
 */

#ifndef osiEventh
#define osiEventh

#include "osiSem.h"
#include "shareLib.h"

class epicsShareClass osiEvent {
public:
    osiEvent ();
    ~osiEvent ();
    void signal ();
    void wait (); /* blocks until full */
    bool wait (double timeOut); /* false if empty at time out */
    bool tryWait (); /* false if empty */
    void show (unsigned level);

    class invalidSemaphore {}; /* exception */
    class noMemory {}; /* exception */
private:
    semBinaryId id;
};

inline osiEvent::osiEvent ()
{
    this->id = semBinaryCreate (semEmpty);
    if (this->id==0) {
#       ifdef noExceptionsFromCXX
            assert (0);
#       else            
            throw noMemory ();
#       endif
    }
}

inline osiEvent::~osiEvent ()
{
    semBinaryDestroy (this->id);
}

inline void osiEvent::signal ()
{
    semBinaryGive (this->id);
}

inline void osiEvent::wait ()
{
    semTakeStatus status;
    status = semBinaryTake (this->id);
    if (status!=semTakeOK) {
#       ifdef noExceptionsFromCXX
            assert (0);
#       else            
            throw invalidSemaphore ();
#       endif
    }
}

inline bool osiEvent::wait (double timeOut)
{
    semTakeStatus status;
    status = semBinaryTakeTimeout (this->id, timeOut);
    if (status==semTakeOK) {
        return true;
    }
    else if (status==semTakeTimeout) {
        return false;
    }
    else {
#       ifdef noExceptionsFromCXX
            assert (0);
            return false;
#       else            
            throw invalidSemaphore ();
#       endif
    }
}

inline bool osiEvent::tryWait ()
{
    semTakeStatus status;
    status = semBinaryTakeNoWait (this->id);
    if (status==semTakeOK) {
        return true;
    }
    else if (status==semTakeTimeout) {
        return false;
    }
    else {
#       ifdef noExceptionsFromCXX
            assert (0);
            return false;
#       else            
            throw invalidSemaphore ();
#       endif
    }
}

inline void osiEvent::show (unsigned level)
{
    semBinaryShow (this->id, level);
}

#endif /* osiEventh */


