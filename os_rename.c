
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



extern int luaL_fileresult(lua_State *, int, const char *);
extern int rename(const char *, const char *);
extern const char * luaL_checklstring(lua_State *, int, size_t *);
extern const char * luaL_checklstring(lua_State *, int, size_t *);

extern int os_rename (lua_State *L) {
  const char *fromname = (luaL_checklstring(L, (1), ((void*)0)));
  const char *toname = (luaL_checklstring(L, (2), ((void*)0)));
  return luaL_fileresult(L, rename(fromname, toname) == 0, ((void*)0));
}