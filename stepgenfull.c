
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



extern void setpause(global_State *);
extern void luaC_runtilstate(lua_State *, int);
extern void entersweep(lua_State *);
extern void setminordebt(global_State *);
extern void atomic2gen(lua_State *, global_State *);
extern lu_mem atomic(lua_State *);
extern void luaC_runtilstate(lua_State *, int);
extern void enterinc(global_State *);

extern void stepgenfull (lua_State *L, global_State *g) {
  lu_mem newatomic;
  lu_mem lastatomic = g->lastatomic;
  if (g->gckind == 1)
    enterinc(g);
  luaC_runtilstate(L, (1<<(0)));
  newatomic = atomic(L);
  if (newatomic < lastatomic + (lastatomic >> 3)) {
    atomic2gen(L, g);
    setminordebt(g);
  }
  else {
    g->GCestimate = ((lu_mem)((g)->totalbytes + (g)->GCdebt)); ;
    entersweep(L);
    luaC_runtilstate(L, (1<<(8)));
    setpause(g);
    g->lastatomic = newatomic;
  }
}