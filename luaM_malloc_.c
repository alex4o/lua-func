
#include <time.h>
#include <setjmp.h>
#include <ctype.h>

#include "lapi.h"
#include "lauxlib.h"
#include "lcode.h"
#include "lctype.h"
#include "ldebug.h"
#include "ldo.h"
#include "lfunc.h"
#include "lgc.h"
#include "llex.h"
#include "llimits.h"
#include "lmem.h"
#include "lobject.h"
#include "lopcodes.h"
#include "lopnames.h"
#include "lparser.h"
#include "lprefix.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "ltm.h"
#include "luaconf.h"
#include "lua.h"
#include "lualib.h"
#include "lundump.h"
#include "lvm.h"
#include "lzio.h"



extern void luaD_throw(lua_State *, int);
extern void * tryagain(lua_State *, void *, size_t, size_t);
extern long __builtin_expect(long, long);

void *luaM_malloc_ (lua_State *L, size_t size, int tag) {
  if (size == 0)
    return ((void*)0);
  else {
    global_State *g = (L->l_G);
    void *newblock = ((*g->frealloc)(g->ud, ((void*)0), tag, size));
    if ((__builtin_expect(((newblock == ((void*)0)) != 0), 0))) {
      newblock = tryagain(L, ((void*)0), tag, size);
      if (newblock == ((void*)0))
        luaD_throw(L, 4);
    }
    g->GCdebt += size;
    return newblock;
  }
}