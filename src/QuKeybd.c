/* $Xorg: QuKeybd.c,v 1.4 2001/02/09 02:03:35 xorgcvs Exp $ */
/*

Copyright 1986, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/
/* $XFree86$ */

#define NEED_REPLIES
#include "Xlibint.h"

struct kmap {
  char map[32];
};

int
XQueryKeymap(dpy, keys)
    register Display *dpy;
    char keys[32];

{       
    xQueryKeymapReply rep;
    register xReq *req;

    LockDisplay(dpy);
    GetEmptyReq(QueryKeymap, req);
    (void) _XReply(dpy, (xReply *)&rep, 
       (SIZEOF(xQueryKeymapReply) - SIZEOF(xReply)) >> 2, xTrue);
    *(struct kmap *) keys = *(struct kmap *)rep.map;  /* faster than memcpy */
    UnlockDisplay(dpy);
    SyncHandle();
    return 1;
}

