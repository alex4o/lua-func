
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



extern void lua_settop(lua_State *, int);
extern int strcmp(const char *, const char *);
extern const char * lua_tolstring(lua_State *, int, size_t *);

extern int incomplete (lua_State *L, int status) {
  if (status == 3) {
    size_t lmsg;
    const char *msg = lua_tolstring(L, -1, &lmsg);
    if (lmsg >= (sizeof("<eof>")/sizeof(char) - 1) && strcmp(msg + lmsg - (sizeof("<eof>")/sizeof(char) - 1), "<eof>") == 0) {
      lua_settop(L, -(1)-1);
      return 1;
    }
  }
  return 0;
}