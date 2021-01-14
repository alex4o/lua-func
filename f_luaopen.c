
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



extern void luaX_init(lua_State *);
extern void luaT_init(lua_State *);
extern void luaS_init(lua_State *);
extern void init_registry(lua_State *, global_State *);
extern void stack_init(lua_State *, lua_State *);

extern void f_luaopen (lua_State *L, void *ud) {
  global_State *g = (L->l_G);
  ((void)(ud));
  stack_init(L, L);
  init_registry(L, g);
  luaS_init(L);
  luaT_init(L);
  luaX_init(L);
  g->gcrunning = 1;
  ((&g->nilvalue)->tt_=(((0) | ((0) << 4))));
  ((void)L);
}